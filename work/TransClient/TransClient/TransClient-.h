/*
 2014 12 29
 By BOBO
 FILE Trans By TCP /WINDOWS
*/
#ifndef _TRANSCLIENT_H
#define _TRANSCLIENT_H
#include <string>
#include <winsock.h>
#include <Windows.h>
#pragma comment(lib,"wsock32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_DIRLEN 256
#define CHUNK_SIZE	   102400		//�ֿ鷢�ʹ�С100K
#define ONE sizeof(char)            ///  ��λ����    
#define PEER_DEFAULT_SIZE 2048*ONE  ///  ͼƬ��ƬĬ�ϴ�С

class TransClient{
public:
	enum RunMode {
		Off,
		Free,
		In,
		Out,
		other1,
	};
	enum TransMode {
		File,
		Screen,
		Board,
	    other2,
	};
	TransClient(TransMode type);
	virtual ~TransClient();
	virtual bool init(const std::string &ip, const int port);                  
	virtual bool closeConn();

public:
	virtual bool trans();  //�����ļ�
	virtual bool fileTrans(const std::string &filePath);/*����*/
	virtual bool fileTrans(const std::string &filePath,const std::string &userId);/*����*/
	int     PicTrans( char * , int len );///  Picture TransPort Overload Function -- Send
	int     PicTrans( char * ) ;///  Pictrue TransPort Overload Function -- Recv
	virtual bool transEnd();
	virtual void errorLine(char * c);
	virtual bool isFileTrans()
	{ return m_transType == File ? true : false;}
	virtual SOCKET sock()
	{ return m_sock;}


protected:  
	std::string TargetIP;
	SOCKET	    m_sock;
//	addrinfo*	TargetInfo;
private: 
	FILE*	m_file;

private:
    //Media * m_media;
	char * m_PicData;


private:
    //Board * m_board;


private:  //base
	int		m_runStatus;
    int		m_transType;   // file  media whiteboard
	char	m_bufDir[DEFAULT_DIRLEN];
	//	const std::string  m_outBuffer;
	//	const std::string  m_inBuffer;
};

#endif