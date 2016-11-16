#if !defined(AFX_SHARESCREENSERVERDLG_H__C65D2BB7_71EA_4568_AC91_13588D9954B4__INCLUDED_)
#define AFX_SHARESCREENSERVERDLG_H__C65D2BB7_71EA_4568_AC91_13588D9954B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShareScreenServerDlg.h : header file
//

#include "AdvButton.h"

/////////////////////////////////////////////////////////////////////////////
// CShareScreenServerDlg dialog

class CInstantMessagingDlg;
class CShareScreenServerSocket;

class CShareScreenServerDlg : public CDialog
{
// Construction
public:
	CShareScreenServerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CShareScreenServerDlg)
	enum { IDD = IDD_SHARESCREEN_SERVER };
	CEdit	m_editInformation;
	CListCtrl	m_listCtrlOutOfShareScreen;
	CListCtrl	m_listCtrlInShareScreen;
	CAdvButton	m_btnDeleteFriends;
	CAdvButton	m_btnAddFriends;
	//}}AFX_DATA
	
private:
	/// 初始化工作
	void Init();

	/// 向指定IP、PORT发送指定用户和数据
	void SendUserCommandToIP( CONTROLCOMMAND command, LPCSTR szIP, UINT nPort, const USER *pUser );

	/// 向共享屏幕添加用户
	void AddUserToShareScreen( const USER user );

	/// 移除用户
	void DelUserFromShareScreen( const USER user );

	/// 更新添加和删除按钮
	void UpdateButtons();

	/// 得到屏幕的dib数据并压缩
	void GetScreenDIB( BYTE *&pDIB, DWORD &dwDIBLength );

	/// 向好友传输桌面的尺寸
	void SendDIMToFriends( const USER user );

	/// 向好友传输桌面图面
	void SendScreenToFriends();
		
private:
	CInstantMessagingDlg	*m_pMainDlg;		/// 主对话框
	CImageList				m_imageList;		/// 头像图像列表
	CArray< USER, USER >	m_arrFriendsInShareScreen;	
												/// 共享屏幕中的好友列表
	CArray< USER, USER >	m_arrFriendsOutOfShareScreen;
												/// 不在共享屏幕中的好友列表
	CShareScreenServerSocket	
							*m_pSSSSocket;		/// 聊天室服务器socket

	HBITMAP hbmp ;

public:
	/// 接收网络数据
	void OnReceive();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShareScreenServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShareScreenServerDlg)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnAddfriends();
	afx_msg void OnDelfriends();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHARESCREENSERVERDLG_H__C65D2BB7_71EA_4568_AC91_13588D9954B4__INCLUDED_)
