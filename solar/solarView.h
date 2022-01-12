
// solarView.h : interface of the CsolarView class
//

#pragma once


class CsolarView : public CView
{
	CWinThread* NewThread;
	CArray<CPoint, CPoint> m_PointArray;
	int x = 0;
	int y = 0;
	int x1 = 0;
	int y1 = 0;

protected: // create from serialization only
	CsolarView() noexcept;
	DECLARE_DYNCREATE(CsolarView)

// Attributes
public:
	CsolarDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CsolarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions

public:
	afx_msg void OnButtonsolarStart();
	
	afx_msg void OnButtonsolarStop();

	
	static UINT StartThread(LPVOID Param);
	static UINT StopThread(LPVOID Param);
protected:

	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in solarView.cpp
inline CsolarDoc* CsolarView::GetDocument() const
   { return reinterpret_cast<CsolarDoc*>(m_pDocument); }
#endif

