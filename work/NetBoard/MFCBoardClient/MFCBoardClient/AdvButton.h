#pragma once
#include "stdafx.h"

//����ͼ�ΰ�ť
class CAdvButton : public CButton
{
// Construction
public:
	CAdvButton();

// Attributes
private:
	int				m_nState;			/// ��ť��״̬
	CBitmap			m_bmpNormal;		/// ����ͼ��
	CBitmap			m_bmpHover;			/// ����ͼ��
	CBitmap			m_bmpDown;			/// ����ͼ��
	CBitmap			m_bmpDisable;		/// ��Чͼ��
	CToolTipCtrl	m_pToolTipCtrl;		/// ��ʾ��

// Operations
private:
	/// ������״̬
	void DrawNORMAL();

	/// ������״̬
	void DrawHOVER();

	/// ������״̬
	void DrawDOWN();

	/// ����Ч״̬
	void DrawDISABLE();

	/// ɾ��ͼ��
	void DeleteBmp();

public:
	/// ����ͼ��
	void setBmp( const UINT nIDNormal,
				 const UINT nIDHover,
				 const UINT nIDDown,
				 const UINT nIDDisable );

	/// ���ð�ťΪ����״̬
	void SetNormal();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdvButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAdvButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CAdvButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave( WPARAM wParam, LPARAM lParam );
	afx_msg LRESULT OnMouseLeaveL( WPARAM wParam, LPARAM lParam )
	{
		OnMouseLeave(wParam,lParam);
		return 1;
	}
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};
