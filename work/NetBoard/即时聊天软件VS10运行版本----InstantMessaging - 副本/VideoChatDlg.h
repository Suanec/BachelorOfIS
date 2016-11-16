#if !defined(AFX_VideoChatDlg_H__BDDF4F60_77BB_477E_BF73_FAD24B363849__INCLUDED_)
#define AFX_VideoChatDlg_H__BDDF4F60_77BB_477E_BF73_FAD24B363849__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VideoChatDlg.h : header file
//

#include "VideoChatSocket.h"

/////////////////////////////////////////////////////////////////////////////
// CVideoChatDlg dialog

class CInstantMessagingDlg;

class CVideoChatDlg : public CDialog
{
// Construction
public:
	CVideoChatDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CVideoChatDlg)
	enum { IDD = IDD_VIDEOCHAT };
	CStatic	m_staticSelf;
	CStatic	m_staticFriend;
	CButton	m_btnTrump;
	CButton	m_btnMike;
	CButton	m_btnSetting;
	CButton	m_btnSelf;
	//}}AFX_DATA
	
private:
	/// 初始化窗口
	void Init();
	
private:
	CInstantMessagingDlg	*m_pMainDlg;		/// 主对话框
	USER					m_userChat;			/// 聊天对象的USER
	BOOL					m_bConnect;			/// 是否连接上视频对象
	BOOL					m_bDeny;			/// 拒绝视频

	CDC						m_dcMem;			/// 聊天对象窗口的内存dc
	CBitmap					m_bitmap;			/// 聊天对象窗口的内存bitmap

	BOOL					m_bReceiveAudio;	/// 播放声音
	BOOL					m_bRecord;			/// 录音

	HWAVEOUT				m_hWaveOut;
	PWAVEHDR				m_pWaveHdr1;
	WAVEFORMATEX			m_WaveForm;

	CArray< char *, char *>	m_arrAudioBuffer;	/// 音频缓冲区
	int						m_nReceive;			/// 接收的区块号
	int						m_nPlay;			/// 播放的区块号
	BOOL					m_bPlaying;			/// 正在播放音频

	CStringList				m_lstVideoData;		/// 保存视频数据

	DWORD					m_dwRecordAudioTickTime;	
												/// 录制音频时发送端的时间
	DWORD					m_dwPlayAudioTickTime;
												/// 播放音频时的时间

	CVideoChatSocket		m_VideoChatSocket;
												/// 收发数据的套接字
	BOOL					m_bReceiveFinished;	/// 视频数据接收完毕

	BYTE					*m_pAudioData;		/// 保存的音频数据
	DWORD					m_dwAudioDataSize;	/// 保存音频数据的大小

private:
	/// 设置自己的视频画面
	void SetSelfPicture( const BITMAPINFO bmpInfo, unsigned char *pData, DWORD dwBufferSize );

	// 发送消息
	void SendCommand( CONTROLCOMMAND command );

	/// 接收到音频数据，保存起来
	void SaveAudioData( char *pData, DWORD dwDataLength );

	/// 更新好友的视频窗口画面
	void UpdateFriendVideoPicture( BYTE *pData, DWORD dwDataLength );

	/// 接收完毕
	void ReceiveFinished();

public:
	/// 返回聊天对象的IP
	LPCSTR GetChatIP(){ return m_userChat.strIP; }
	
	/// 设置聊天的对象
	void SetChatUser( const USER userChat );

	/// 设置连接状态
	void SetConnect( BOOL bConnect ){ m_bConnect = bConnect; }

	/// 得到连接状态
	BOOL GetConnect(){ return m_bConnect; }

	/// 拒绝视频
	void DenyVideoChat();

	/// 用户断开了视频连接
	void Disconnect();

	BOOL GetReceiveAudio(){ return m_bReceiveAudio; }
	BOOL GetRecord(){ return m_bRecord; }

	/// 接收视频和音频数据
	void OnReceive();

	/// 更新自己的画面并发送数据
	void UpdateVideoPicture( DWORD dwTickCount,
							const BITMAPINFO bmpInfo, 
							unsigned char *pData, 
							DWORD dwBufferSize );

	/// 发送声音数据
	void SendAudioData( DWORD dwTickCount, char *pAudioData, DWORD dwBufferSize );

	///	连接到服务器
	void ConnectToServer();

	/// 附加客户端的socket
	void AttachClientSocket( SOCKET hSocket, CVideoChatDlg *pVidelChatDlg );

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoChatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CVideoChatDlg)
	afx_msg void OnOk();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnSetting();
	afx_msg void OnSelf();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnMike();
	afx_msg void OnTrump();
	afx_msg void WaveOutOpen( WPARAM wParam, LPARAM lParam ) ;
	afx_msg void WaveOutDone( WPARAM wParam, LPARAM lParam ) ;
	afx_msg void WaveOutClose( WPARAM wParam, LPARAM lParam ) ;
	afx_msg LRESULT WaveOutOpenL( WPARAM wParam, LPARAM lParam ) 
	{
		WaveOutOpen(wParam,lParam);
		return 1;
	}
	afx_msg LRESULT WaveOutDoneL( WPARAM wParam, LPARAM lParam ) 
	{
		WaveOutDone(wParam,lParam);
		return 1;
	}
	afx_msg LRESULT WaveOutCloseL( WPARAM wParam, LPARAM lParam ) 
	{
		WaveOutClose(wParam,lParam);
		return 1;
	}
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VideoChatDlg_H__BDDF4F60_77BB_477E_BF73_FAD24B363849__INCLUDED_)
