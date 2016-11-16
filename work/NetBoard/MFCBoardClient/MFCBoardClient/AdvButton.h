#pragma once
#include "stdafx.h"

//设置图形按钮
class CAdvButton : public CButton
{
// Construction
public:
	CAdvButton();

// Attributes
private:
	int				m_nState;			/// 按钮的状态
	CBitmap			m_bmpNormal;		/// 正常图标
	CBitmap			m_bmpHover;			/// 焦点图标
	CBitmap			m_bmpDown;			/// 按下图标
	CBitmap			m_bmpDisable;		/// 无效图标
	CToolTipCtrl	m_pToolTipCtrl;		/// 提示类

// Operations
private:
	/// 画正常状态
	void DrawNORMAL();

	/// 画焦点状态
	void DrawHOVER();

	/// 画按下状态
	void DrawDOWN();

	/// 画无效状态
	void DrawDISABLE();

	/// 删除图像
	void DeleteBmp();

public:
	/// 设置图像
	void setBmp( const UINT nIDNormal,
				 const UINT nIDHover,
				 const UINT nIDDown,
				 const UINT nIDDisable );

	/// 设置按钮为正常状态
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
