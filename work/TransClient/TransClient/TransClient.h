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

//#define DEBUGOUT_LOG
#define DEBUG_START

#define SERVER_PORT   	12308
#define DEFAULT_BUFLEN 	256
#define DEFAULT_DIRLEN 	256
#define CHUNK_SIZE	   	102400		//分块发送大小100K
#define TIMEOUT_WAIT    1
#define RETRY_TIMES     3

#define ONE sizeof(char)            ///  单位长度    
#define PEER_DEFAULT_SIZE 2048*ONE  ///  图片分片默认大小

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
	virtual bool trans();  //共享文件
	virtual bool fileTrans(const std::string &filePath);/*接受*/
	virtual bool fileTrans(const std::string &filePath,const std::string &userId);/*发送*/
	int     PicTrans( char * , int len );///  Picture TransPort Overload Function -- Send
	int     PicTrans( char * ) ;///  Pictrue TransPort Overload Function -- Recv
	virtual bool transEnd();
	virtual bool isFileTrans()
	{ return m_transType == File ? true : false;}
	virtual SOCKET sock()
	{ return m_sock;}
private:
	static  void errorLine(const char* str);
	static  void printLine(const char *format,...);

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
	char	m_baseUrl[DEFAULT_DIRLEN];
	//	const std::string  m_outBuffer;
	//	const std::string  m_inBuffer;
};

#endif
