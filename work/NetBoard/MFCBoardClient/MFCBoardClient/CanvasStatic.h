#pragma once 
#include "stdafx.h"
#include "Global.h"

/////////////////////////////////////////////////////////////////////////////
// CCanvasStatic window

class CCanvasStatic : public CStatic
{
// Construction
public:
	CCanvasStatic();
    

// Attributes
private:
	CDC						m_dcMem;			/// ��ͼ���ڴ�dc
	CBitmap					m_bitmap;			/// ��ͼ���ڴ�bitmap

	CDC						m_dcOld;			/// ����ԭ����dc
	CBitmap					m_bitmapOld;		/// ����ԭ����bitmap

	TOOL					m_emTool;			/// ����
	int						m_nWidth;			/// �߿�
	COLORREF				m_clDrawColor;		/// ��ɫ

	HCURSOR					m_hCursor;			/// ���ָ��

	CPoint					m_ptStart;			/// ��ʼ��
	CPoint					m_ptEnd;			/// ������

	BOOL					m_bDrawing;			/// �Ƿ��ڻ�ͼ��
	BOOL					m_bOwnerDraw;		/// �Ƿ����Լ���ͼ���Ǳ��˻�ͼ

// Operations
public:
	void SetTool( TOOL emTool ){ m_emTool = emTool; SetCursorByTool(); }
	void SetWidth( int nWidth ){ m_nWidth = nWidth; SetCursorByTool(); }
	void SetColor( COLORREF cl ){ m_clDrawColor = cl; }

	/// ���ݻ�ͼ��Ϣ��ͼ
	void Draw( DRAWINFO drawInfo );

	/// ��ͼ
	void Draw();

	/// �������
	void ClearCanvas();

	///�Զ������ͼ��
	void ClearShape();

private:
	/// ���»���
	void UpdataCanvas();

    /// ���ͼ��
    void ClearGraphics();

	/// �������ָ��
	void SetCursorByTool();

	/// ����
	void DrawLine();

	/// ����
	void Erase();

	/// ����
	void DrawPoint();

	/// �����ľ���
	void DrawEmptyRectangle();

	/// ������
	void DrawRectangle();

	/// ��������Բ
	void DrawEmptyEllipse();

	/// ����Բ
	void DrawEllipse();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCanvasStatic)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCanvasStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCanvasStatic)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnMouseLeave( WPARAM wParam, LPARAM lParam );
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeaveL( WPARAM wParam, LPARAM lParam )
	{
		OnMouseLeave(wParam,lParam);
		return 1;
	}
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};
