// InstantMessagingDlg.h : header file
//

#if !defined(AFX_INSTANTMESSAGINGDLG_H__7D41D06C_C73A_4AE1_9284_440FC1479084__INCLUDED_)
#define AFX_INSTANTMESSAGINGDLG_H__7D41D06C_C73A_4AE1_9284_440FC1479084__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CInstantMessagingDlg dialog
#include "StdAfx.h"
#include "AdvButton.h"
#include "DialogSetting.h"
//#include "FriendsListCtrl.h"
//#include "ChatRoomServerDlg.h"
//#include "ChatRoomClientDlg.h"
//#include "ChatDlg.h"
//#include "ShareScreenClientDlg.h"
//#include "ShareScreenServerDlg.h"
//#include "SendFilesServerDlg.h"
//#include "SendFilesClientDlg.h"
#include "WhiteBoardServerDlg.h"
#include "WhiteBoardClientDlg.h"
//#include "VideoChatDlg.h"
//#include "VideoChatListenSocket.h"

class CListeningSocket;

//LRESULT WINAPI EncodeCallback( HWND hWnd, LPVIDEOHDR lpVHdr );
BYTE _clip255( LONG v );
void YUY2_RGB( BYTE *YUY2buff, BYTE *RGBbuff, DWORD dwSize );

class CInstantMessagingDlg : public CDialog
{
// Construction
public:
	CInstantMessagingDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CInstantMessagingDlg)
	enum { IDD = IDD_INSTANTMESSAGING_DIALOG };
	CComboBox	m_comboxIP;
	//CFriendsListCtrl	m_listCtrlFriends;
	CListCtrl m_listCtrlFriends;
	CStatic	m_staticFace;
	CEdit	m_editNickName;
	CComboBox	m_comboxState;
	CComboBox	m_comboxFriend;
	CAdvButton	m_btnWhiteBoard;
	CAdvButton	m_btnShareScreen;
	CAdvButton	m_btnSendFiles;
	CAdvButton	m_btnChatRoom;
	CAdvButton	m_btnAddFriend;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInstantMessagingDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON					m_hIcon;
	NOTIFYICONDATA			m_nid;				/// 最小化是托盘所需结构体
	CBitmap					m_bmpFace;			/// 头像
	WORD					m_wVirtualKeyCode;	/// 热键虚拟器码
	WORD					m_wModifiers;		/// 热键修改值
	WORD					m_wFace;			/// 头像
	WORD					m_wState;			/// 状态
	CString					m_strNickName;		/// 昵称
	BOOL					m_bCamera;			/// 摄像头
	BOOL					m_bAutoAddFriends;	/// 自动加为好友
	CStringList				m_strlstIP;			/// 自己的IP列表

	CStringList				m_strlstRequest;	/// 请求加为好友的IP列表

	CStringList				m_strlstKeepConnent;
												/// 保持连接的IP列表
	CStringList				m_strlstChatRoomRequest;	
												/// 请求加入聊天室的IP列表
	CListeningSocket		*m_pLisSocket;		/// 监听socket
	
	CArray< USER, USER >	m_arrFriends;		/// 好友列表

	//CChatRoomServerDlg		m_dlgCRServer;		/// 聊天室服务器

	//CArray< CChatRoomClientDlg *, CChatRoomClientDlg * >
	//						m_arrCRClient;		/// 聊天室的客户端列表

	//CArray< CChatDlg *, CChatDlg *>
	//						m_arrChatDlg;		/// 聊天对话框的列表

	CMapStringToPtr			m_mapIPToData;		/// 聊天ip到数据的map

	CMapStringToString		m_mapIPToTime;		/// 聊天ip到时间的map

	CMapStringToOb			m_mapIPToChat;		/// 聊天IP到聊天（时间和内容）的map

	CMapStringToString		m_mapSendChatMessage;
												/// 发送聊天消息的map

	CArray< int, int >		m_arrMessageArrive;	/// 保存有消息到达的用户序号

	CImageList				m_imageListMA;		/// 保存有消息到达的用户头像

	int						m_nTrayShowIndex;	/// 托盘显示的序号

	//CSendFilesServerDlg		m_dlgSendFilesServer;
	//											/// 发送文件服务器对话框
	//
	//CSendFilesClientDlg		m_dlgSendFilesClient;
	//											/// 发送文件服务器对话框

	//CShareScreenServerDlg	m_dlgSSServer;		/// 共享屏幕服务器对话框
	//
	//CShareScreenClientDlg	m_dlgSSClient;		/// 共享屏幕客户端对话框
	//
	//CStringList				m_strlstShareScreenRequest;	
	//											/// 请求加入共享屏幕的IP列表

	CWhiteBoardServerDlg	m_dlgWhiteBoardServer;
												/// 白板服务器对话框
	CStringList				m_strlstWhiteBoardRequest;	
												/// 请求加入白板的IP列表
	CWhiteBoardClientDlg	m_dlgWhiteBoardClient;
												/// 白板客户端对话框

	//CArray< CVideoChatDlg *, CVideoChatDlg *>
	//						m_arrVideoChatDlg;	/// 视频聊天对话框的列表
	//BOOL					m_bConnectCamera;	/// 连接上视频


	//CStringList				m_strlstVideoChatRequest;	
	//											/// 请求视频聊天的IP列表
	int						m_nMaxUDPDG;		/// UDP包支持的最大数据值

	//HWAVEIN					m_hWaveIn;
	//PWAVEHDR				m_pWaveHdr1;
	//PWAVEHDR				m_pWaveHdr2;
	//char					*m_pBuffer1;
	//char					*m_pBuffer2;
	//WAVEFORMATEX			m_WaveForm;

	//DWORD					m_dwTickTime;		/// 记录开始录音的时刻

	//CVideoChatListenSocket	*m_pVideoChatListenSocket;
	//											/// 视频聊天的监听socket

public:
	CSocket					m_pSocket;			/// 添加网段用户的socket

	//HWND					m_hWndVideo;		/// 视频的窗口句柄

	
private:
	/// 初始化程序
	void Init();

	/// 鼠标在托盘区的消息响应函数
	void OnShellNotifyProc( WPARAM wParam, LPARAM lParam );

	LRESULT OnShellNotifyProcL( WPARAM wParam, LPARAM lParam )
	{
		OnShellNotifyProc(wParam,lParam);
		return 1;
	}
	
	/// 热键响应函数
	void OnHotkey( WPARAM wParam, LPARAM lParam );
	LRESULT OnHotkeyL( WPARAM wParam, LPARAM lParam )
	{
		OnHotkey(wParam,lParam);
		return 1;
	}

	void SetState();

	void SendOffLineMessage();

	void AddRequest( const USER user );
	void AddFriend( const USER user );
	void DeleteFriend( const USER user );
	void KeepConnect( CString strIP );

	/// 响应加入聊天室的请求
	void OnAddToChatRoomRequest( const USER userServer );

	/// 向指定IP、PORT发送指定用户和数据
	void SendUserCommandToIP( CONTROLCOMMAND command, LPCSTR szIP, UINT nPort, const USER *pUser );

	///	为接收聊天消息作准备
	void PrepareChatMessage( LPCSTR szReceive, LPCSTR szIP );

	/// 接收聊天消息
	void ReceiveChatMessage( LPCSTR szReceive, LPCSTR szIP );

	/// 从历史记录中删除指定记录
	//void DeleteHistory( int nIndex, const CString strHistory );

	/// 开始发送数据
	void SendChatMessage( LPCSTR szReceive, LPCSTR szIP );

	/// 把指定ip的用户的头像加入到托盘动态显示
	void AddTrayIcon( LPCSTR szIP );

	/// 回应是否接收传输的文件
	void SendFilesResponse( LPCSTR szReceive, LPCSTR szIP );

	/// 响应加入共享屏幕的请求
	void OnAddToShareScreenRequest( const USER userServer );

	/// 响应加入白板的请求
	void OnAddToWhiteBoardRequest( const USER userServer );

	///// 响应视频聊天请求
	//void OnAddToVideoChatRequest( const USER user );

	///// user拒绝视频
	//void DenyAddToVideoChatRequest( const USER user );

	///// 允许加入视频聊天
	//void AllowAddToVideoChatRequest( const USER user );

	///// user断开视频连接
	//void UserDisconnectFromVideoChat( const USER user );

public:
	WORD GetFace(){ return m_wFace; }
	CString GetNickName(){ return m_strNickName; }
	BOOL HasCamera(){ return m_bCamera; }
	WORD GetVirtualKeyCode(){ return m_wVirtualKeyCode; }
	WORD GetModifiers(){ return m_wModifiers; }
	BOOL GetAutoAddFriends(){ return m_bAutoAddFriends; }
	int  GetMaxUDPDG(){ return m_nMaxUDPDG; }

	void SetFace( WORD wFace );
	void SetNickName( const CString strNickName );
	void SetHotKey( WORD wVirtualKeyCode, WORD wModifiers );
	void SetAutoAddFriends( BOOL bAutoAddFriends );
	void SetMaxUDPDG( int nMaxUDPDG ){ m_nMaxUDPDG = nMaxUDPDG; }

	void OnListeningReceive();
	
	void DeleteFriend( int nIndex );

	void GetFriendsArray( CArray< USER, USER > &arrFriends ){ arrFriends.Copy( m_arrFriends ); }

	void SendFriendMessage( const USER user, CONTROLCOMMAND command );

	/// 从列表中删除聊天室客户端
	//void DelCRClientFromList( LPCSTR szIP );

	///// 和第nIndex个好友聊天
	//void OnChat( UINT nIndex );

	///// 关闭聊天窗口
	//void OnCloseChatDlg( LPCSTR szIP );

	///// 发送聊天消息
	//void SendPreChatMessage( const USER userChat, CString strTime, CString strSend );

	///// 向指定IP用户发送传送文件的通知
	//void SendFilesNotify( LPCSTR szIP, CString strFile, DWORD dwLength );

	///// 拒绝接收文件
	//void DenyReceiveFile( CString strFilePath, LPCSTR szIP );

	/// 由IP得到USER
	void GetUserFromIP( LPCSTR szIP, USER &user );

	/// 得到自己IP列表框的IP
	CString GetComboBoxIP();

	/// 和第nIndex个好友视频聊天
	//void OnVideoChat( UINT nIndex );

	///// 得到打开的视频聊在对话框列表
	//void GetVideoChatDlgArray( CArray< CVideoChatDlg *, CVideoChatDlg *> &arrVideoChatDlg ){ arrVideoChatDlg.Copy( m_arrVideoChatDlg ); }

	///// 关闭视频聊天窗口
	//void CloseVideoChatDlg( const USER user );

	///// 视频聊天时更新画面
	//void UpdateVideoPicture( DWORD dwTickCount, 
	//						const BITMAPINFO bmpInfo, 
	//						unsigned char *pData, 
	//						DWORD dwBufferSize );

	///// 接受视频聊天的socket
	//void OnAcceptVideoChat();

	// Generated message map functions
	//{{AFX_MSG(CInstantMessagingDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOk();
	virtual void OnCancel();
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnExit();
	afx_msg void OnSetting();
	afx_msg void OnSelchangeComboState();
	afx_msg void OnState();
	afx_msg void OnBtnAddfriend();
	afx_msg void OnTimer(UINT nIDEvent);
	//afx_msg void OnBtnChatroom();
	//afx_msg void OnChatroom();
	//afx_msg void OnBtnSendfiles();
	//afx_msg void OnSendfiles();
	//afx_msg void OnReceivefiles();
	//afx_msg void OnAddSection();
	//afx_msg void OnBtnSharescreen();
	//afx_msg void OnSharescreen();
	afx_msg void OnBtnWhiteboard();
	afx_msg void OnWhiteboard();

	//afx_msg void WaveInOpen( WPARAM wParam, LPARAM lParam ) ;
	//afx_msg void WaveInData( WPARAM wParam, LPARAM lParam ) ;
	//afx_msg void WaveInClose( WPARAM wParam, LPARAM lParam ) ;

	//afx_msg LRESULT WaveInOpenL( WPARAM wParam, LPARAM lParam ) 
	//{
	//	WaveInOpen(wParam,lParam);
	//	return 1;
	//}
	//afx_msg LRESULT WaveInDataL( WPARAM wParam, LPARAM lParam ) 
	//{
	//	WaveInData(wParam,lParam);
	//	return 1;
	//}
	//afx_msg LRESULT WaveInCloseL( WPARAM wParam, LPARAM lParam ) 
	//{
	//	WaveInClose(wParam,lParam);
	//	return 1;
	//}

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INSTANTMESSAGINGDLG_H__7D41D06C_C73A_4AE1_9284_440FC1479084__INCLUDED_)
