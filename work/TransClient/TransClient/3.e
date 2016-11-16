#include "TransClient.h"
#include <iostream>



TransClient::TransClient(TransMode type):m_runStatus(Off), m_transType(type)
{
	GetCurrentDirectory(MAX_PATH,(LPTSTR)m_bufDir);
	WSAData Data;
	if(WSAStartup(MAKEWORD(2, 2), &Data)!=0) 
		errorLine("Socket DLL Init Error.");
}

TransClient::~TransClient()
{
	closeConn();


}

bool TransClient::init(const std::string &ip, const int port)
{
	if(m_runStatus!=Off)
		return false;

	//SOCKET
	struct sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(ip.c_str());

	m_sock = socket(AF_INET, SOCK_STREAM, 0);
	int conn;
	if( conn=connect(m_sock, (struct sockaddr *) &sin,sizeof(sin)) == -1) {
		errorLine("error in connect.");
		exit(-1);
	}
	if (conn < 0)
		return false;

	m_runStatus = Free;
	return true;
}


bool TransClient::closeConn()
{
	if (m_runStatus != Free)
		return false;
	closesocket(m_sock);
	WSACleanup();
	m_runStatus = Off;
	return true;
}


bool TransClient::fileTrans(const std::string &filePath, const std::string &userId)
{
	if (m_runStatus != Free)
		return false;

	if (m_transType != File)
		return false;
	m_file = fopen(filePath.c_str(), "rb");
	if (!m_file){
		errorLine("File Open Error.");
		return false;
	}
	m_runStatus = Out;

 	send(m_sock,"r",sizeof("r"),0);
	send(m_sock,filePath.c_str(),sizeof(filePath.c_str())+1,0);

	long nCurrentPos = 0;//接受断点值
	if(recv(m_sock,(char*)&nCurrentPos,sizeof(long),0) == SOCKET_ERROR)		//接收断点
		std::cout << "The Clinet Socket is Closed\n";
	else
	{
		std::cout << "The Currentpos is The " << nCurrentPos << ".\n";
		int	nChunkCount = 0;        //文件块数
		if(m_file)
		{
			fseek(m_file,0L,SEEK_END);		//获取文件总长度					
			long FileFullLen = ftell(m_file) + 1;

			fseek(m_file,(long)(nCurrentPos),SEEK_SET);		//文件指针移至断点处

			int FileLen = FileFullLen - nCurrentPos;		//剩余文件大小

			if(FileLen == 0)
			{
				std::cout << "The file has been sent.\n";
			}
			else
			{
				nChunkCount = FileLen / CHUNK_SIZE;		//文件块数
				if( nChunkCount == 0 || FileLen % nChunkCount != 0)
				{
					nChunkCount++;
				}

				send(m_sock,(char*)&FileLen,sizeof(int),0);		//向客户端发送文件长度
				for(int i = nCurrentPos;i < nChunkCount;i++)		//从断点处分块发送
				{ 
					int nSendSize = 0;		//将要发送的数据大小

					if(i + 1 == nChunkCount)		//最后一块
					{
						nSendSize = FileLen - CHUNK_SIZE * ( nChunkCount - 1 );
					}
					else
					{
						nSendSize = CHUNK_SIZE;
					}

					char *data = (char*)malloc(sizeof(char) * nSendSize);		//分配存放当前读取的文件空间
					ZeroMemory(data,nSendSize);
					int idx=0;
					int rdLens = fread(data,sizeof(char),nSendSize,m_file);
					if( nSendSize != rdLens+1)		//判断是否读取额定大小的文件内容
					{
						std::cout << "read file error.\n";
						break;		//break for
					};
					int ret = 0;		//判断socket是否正常
					while(nSendSize > 0)
					{
						ret = send(m_sock,&data[idx],nSendSize,0);
						if(ret == SOCKET_ERROR)
						{
							std::cout<<"Send The Date Error \n";
							break;
						}
						nSendSize -= ret;
						idx += ret;
					}
					free(data);

					if(ret != SOCKET_ERROR)
					{
						std::cout<< "\r Sending "
							<< ((float)(i + 1)/(float)nChunkCount) * 100
							<< "%";
					}
					else
					{
						std::cout << "The connection is closed.\n";
						break;
					}
				}
			}
			fclose(m_file);
		}
		else
		{
			std::cout << "open the file error\n";
		} 
	}
	/* //Create Thread to sendfile  (this)
	char temp[DEFAULT_BUFLEN];
	int num1,num2; 
	while(!feof(fp))  {  
	num1 = fread(temp, 1, DEFAULT_BUFLEN, fp);  
	num2 = send(m_sock, temp, num1, 0);
	if(num2 < 1)
	std::cerr<< "Send File With Some Error.code:"<< GetLastError()<< std::endl;
	}
	std::cerr<< "server file send end"<< std::endl;  
	fclose(fp); 

	if( shutdown(m_sock, SD_SEND) == SOCKET_ERROR)  
	std::cerr<<"server shutdown failed"<< WSAGetLastError()<< std::endl;*/




	return true;
}


bool TransClient::fileTrans(const std::string &fileName) //download
{
	
	std::string tmpPath = "./";
	std::string destPath = "./";	
	tmpPath.append(fileName.c_str()).append(".").append(".tmp");
	destPath.append(fileName.c_str()).append(".");
	int		FileLen = 0;		//本次接收文件长度
	int		nCurrentPos = 0;		//断点位置
	FILE*	PosFile  = fopen( tmpPath.c_str(),"r");		//读取存储断点文件

	if(PosFile)		//如果有临时文件则读取断点
	{
		fread((char*)&nCurrentPos,sizeof(nCurrentPos),1,PosFile);		//读取断点位置
		std::cout<< "The File Pos is " << nCurrentPos << ".\n";
		fclose(PosFile);
	}
	
	send(m_sock,"d",sizeof("d"),0);
	getchar();
	send(m_sock,fileName.c_str(),sizeof(fileName.c_str())+1,0);
	getchar();

	send(m_sock,(char*)&nCurrentPos,sizeof(int),0);		//发送断点值
	if( recv(m_sock,(char*)&FileLen,sizeof(FileLen),0) != 0)		//本次接收文件长度
	{
		if(FileLen > 0)
		{
			int	nChunkCount;		//本次接收的块数
			nChunkCount = FileLen / CHUNK_SIZE;		//计算文件块数
			if(nChunkCount == 0 || FileLen % nChunkCount != 0)		//若文件不能整分
			{
				nChunkCount++;
			}
			FILE *file = fopen(destPath.c_str(),"ab");		//追加写方式打开文件
			if(file)
			{
				fseek(file,(long)(nCurrentPos * CHUNK_SIZE),SEEK_SET);//文件指针移至断点处
				long seekpos = nCurrentPos;		//记录接收到的文件的大小
				for(int i = nCurrentPos;i < nChunkCount;i++)        //从断点处开始写入文件
				{
					int nRecvSize = 0;

					if(i+1 == nChunkCount)		//最后一块
					{
						nRecvSize = FileLen - CHUNK_SIZE * ( nChunkCount - 1 );
					}
					else
					{
						nRecvSize = CHUNK_SIZE;
					}
					char *data = (char*)malloc(sizeof(char) * nRecvSize);
					ZeroMemory(data,nRecvSize);

					int idx=0;

					while(nRecvSize > 0)
					{
						int ret = recv(m_sock,&data[idx],nRecvSize,0);
						if(ret == SOCKET_ERROR)
						{
							std::cout<<"Recv Date Error.\n";
							return 0;
						}
						idx += ret;
						seekpos += ret;
						nRecvSize -= ret;
					}
					fwrite(data,sizeof(char),idx,file);

					free(data);

					//将断点写入PosFile.txt文件
					FILE * PosFile = NULL;
					PosFile = fopen(tmpPath.c_str(),"w");
					if(PosFile)
					{
						fwrite((char*)&seekpos,sizeof(long),1,PosFile);
						fclose(PosFile);
					}

					std::cout<<"\r Receiving "
						 	 <<((float)(i + 1)/(float)nChunkCount) * 100
							 << "%";

				}
				fclose(file);
				file = NULL;
			}
		}
		remove(tmpPath.c_str());
		std::cout<<"\n the file is receive complete.\n";
	}
	return 0;


	return true;
}


bool TransClient::trans()
{
	if (m_runStatus != Free)
		return false;

	if(m_transType == File){
		m_file = fopen( m_bufDir, "w+b");
		if (!m_file){
			errorLine("File Create Error.");
			return false;
		}
	}
	if(m_transType == Screen){
		/*	m_file = fopen( m_bufDir, "w+b");
		if (!m_file){
		errorLine("File Create Error.");
		return false;
		}*/
	}
	if(m_transType == Board){
		/*	m_file = fopen( m_bufDir, "w+b");
		if (!m_file){
		errorLine("File Create Error.");
		return false;
		}*/
	}

	m_runStatus = In;
	// thread recv; (this)



	return true;
}


bool TransClient::transEnd()
{
	if(m_runStatus==In || m_runStatus==Out)
		m_runStatus = Free;

	if(m_file)
		fclose(m_file);
	/*if(m_media)
	close(m_media);
	if(m_file)
	close(m_board);*/
	m_file =NULL;
	/*m_media =NULL;
	m_board =NULL;*/


	return true;
}


void TransClient::errorLine(char * c)
{ 
	std::cerr<< c<< "-code:"<< GetLastError()<< std::endl;
}


///  -- suanec
int TransClient::PicTrans( char * pSend , const int len )
{
	int sum = 0;                               ///  the total lenth sended.
	char * pIndex = pSend ;                     ///  the position that should send next time.
	char * pTemTail = pSend ;                   ///  the position that the peer's tail.
	int ret = 0;	                           ///  is the socket aviliable?

	if (m_runStatus != Free)
		return false;

	if (m_transType != TransClient::TransMode::Screen)
		return false;

	if (!pSend||!len){
		errorLine("Nothing in the Mem to Send.");
		return false;
	}
	m_runStatus = Out;

 	if(send(m_sock,"r",sizeof("r"),0)<=0)return 0;
	
	if(pSend)
	{
		if( ( len - sum ) == 0 )return sum;
		while( sum < len )
		{
			((len-sum)>PEER_DEFAULT_SIZE)?
				(ret = send( m_sock, pIndex, PEER_DEFAULT_SIZE, 0))
				:(ret = send( m_sock, pIndex, (len-sum), 0));
			if(ret<0)return ret;
			sum += (ret/ONE);
			pIndex += (ret/ONE);
		}
	}
	if(sum == len) return sum;
	else return -1;
}


int TransClient::PicTrans( char * pRecv ) //download
{
	char * pIndex = pRecv;                            ///  the position that read the coming data.
	int len;                                          ///  the data lenth.
	int sum;                                          ///  the lenth received.
    int ret;                                          ///  is the socket aviliable.
	if( send(m_sock,"d",sizeof("d"),0) <= 0 ) return false;
	
	if( !recv( m_sock, (char*)&len, sizeof(len), 0 ) || !len) return false;

	if(pRecv)
	{
		while( sum < len )
		{
			( (len-sum) < PEER_DEFAULT_SIZE )?
				(ret = recv( m_sock, pIndex, (len-sum), 0))
				:(ret = recv( m_sock, pIndex, PEER_DEFAULT_SIZE, 0));
			if(ret<0)return ret;
			sum += ret;
			pIndex += (ret/ONE);
		}
	}
	if(sum == len) return sum;
	else return -1;
}