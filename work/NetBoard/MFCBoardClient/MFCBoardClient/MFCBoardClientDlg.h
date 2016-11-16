
// MFCBoardClientDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "resource.h"
#include "AdvButton.h"
//#include "WhiteBoardClientSocket.h"
#include "canvasstatic.h"

class CWhiteBoardClientSocket;
// CMFCBoardClientDlg �Ի���
class CMFCBoardClientDlg : public CDialogEx
{
// ����
public:
	CMFCBoardClientDlg(CWnd* pParent = NULL);	// ��׼���캯��
private:
	/// ��ʼ������
	void Init();
	
	/// ��ָ��IP��PORT����ָ���û�������
	void SendUserCommandToIP( CONTROLCOMMAND command, LPCSTR szIP, UINT nPort, const USER *pUser );
	
	/// �������ؼ���λ��
	void SetPosition();
	
	/// �ָ����ߵ�״̬
	void ResetTools();
	
	///	�ָ��߿�
	void ResetWidth();

	/// �������ر�
	void ServerClosed();

	/// ���߳�������Ļ
	void Kicked();

	/// ���ջ滭����
	void ReceiveDrawData( char *pReceivedData );

private:
	CMFCBoardClientDlg  	*m_pMainDlg;		/// ���Ի���
	//CImageList				m_imageList;		/// ͷ��ͼ���б�
	CString					m_strServerIP;		/// ������IP
	CWhiteBoardClientSocket	
							*m_pWBCSocket;		/// �װ�ͻ���socket
	
	TOOL					m_emTool;			/// ����
	int						m_nWidth;			/// �߿�
	COLORREF				m_clDrawColor;		/// ��ɫ
	//CWhiteBoardClientSocket *m_pSkt;	    	/// �װ�ͻ���Socket
public:
	/// ������������
	void OnReceive();

	/// ���ض�Ӧ�ķ�����IP
	CString GetServerIP(){ return m_strServerIP; }

    ///���ͻ�ͼ��Ϣ�������û�
    void SendDrawInfoToAllUser( const CPoint ptStart, const CPoint ptEnd );

    ///���տͻ��˻�ͼ��Ϣ
    void ReceiveClientDrawInfo( char *pReceivedData, const CString strIP );


	/// ͬ���������
	void AcceptAddRequest( const USER userServer );

	/// ����ͼ��Ϣ���͵�������
	void SendDrawInfoToServer( const CPoint ptStart, const CPoint ptEnd );

// �Ի�������
	enum { IDD = IDD_MFCBOARDCLIENT_DIALOG };

    
    ///�ж��Ƿ��Ƿ�����ö��ʵ��
    ISSERVER                IsServer;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

    ///���浱ǰ�ͻ���IP��ַ��
    CArray< CString ,CString >              m_arrClntIP;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CCanvasStatic m_staticCanvas;
	afx_msg void OnBnClickedEraser(); 
	afx_msg void OnBnClickedPencil();
	afx_msg void OnBnClickedLine();
	afx_msg void OnBnClickedRectangleEmpty();
	afx_msg void OnBnClickedRectangle();
	afx_msg void OnBnClickedEllipseEmpty();
	afx_msg void OnBnClickedEllipse();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedWidth1();
	afx_msg void OnBnClickedWidth2();
	afx_msg void OnBnClickedWidth3();
	afx_msg void OnBnClickedWidth4();
	CAdvButton m_btnEraser;
	CAdvButton m_btnPencil;
	CAdvButton m_btnLine;
	CAdvButton m_btnRectangleEmpty;
	CAdvButton m_btnRectangle;
	CAdvButton m_btnEllipseEmpty;
	CAdvButton m_btnEllipse;
	CStatic    m_staticColor;
	CAdvButton m_btnWidth1;
	CAdvButton m_btnWidth2;
	CAdvButton m_btnWidth3;
	CAdvButton m_btnWidth4;

	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	afx_msg void OnStnClickedColor();
	CAdvButton   m_btnClear;
	afx_msg void OnBnClickedConnect();
    afx_msg void OnMenuConnect();
    afx_msg void OnBnClickedResetser();
    afx_msg void OnSetser();
    afx_msg void OnResetProg();
};
