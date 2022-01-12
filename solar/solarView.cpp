
// solarView.cpp : implementation of the CsolarView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "solar.h"
#endif

#include "solarDoc.h"
#include "solarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsolarView

IMPLEMENT_DYNCREATE(CsolarView, CView)

BEGIN_MESSAGE_MAP(CsolarView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CsolarView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()

	ON_COMMAND(ID_BUTTON1, &CsolarView::OnButtonsolarStart)
	ON_COMMAND(ID_BUTTON3, &CsolarView::OnButtonsolarStop)
END_MESSAGE_MAP()

// CsolarView construction/destruction

CsolarView::CsolarView() noexcept
{
	// TODO: add construction code here
	NewThread = NULL;
	x = 400;
	y = 200;
	x1 = 300 + 150 * cos(3);
	y1 = 200 + 150 * sin(3);
}

CsolarView::~CsolarView()
{
}

BOOL CsolarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CsolarView drawing

void CsolarView::OnDraw(CDC* pDC)
{
	int i, count;
	CsolarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	
	
	pDC->Ellipse(450, 350, 150, 50);


	
	pDC->Ellipse(400, 300, 200, 100);
	

	CBrush brush1(RGB(255, 255, 0));
	CBrush* pBrush1 = pDC->SelectObject(&brush1);
	pDC->Ellipse(300, 200, 270, 170);
	pDC->SelectObject(pBrush1);



	CBrush brush2(RGB(173, 216, 230));
	CBrush* pBrush2 = pDC->SelectObject(&brush2);
	pDC->Ellipse(x + 8, y + 8, x - 8, y - 8);
	pDC->SelectObject(pBrush2);


	CBrush brush(RGB(255, 255, 0));
	CBrush* pBrush = pDC->SelectObject(&brush);
	pDC->Ellipse(x1 + 8, y1 + 5, x1 - 8, y1 - 8);
	pDC->SelectObject(pBrush);

	
	



}


// CsolarView printing


void CsolarView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}


BOOL CsolarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CsolarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CsolarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CsolarView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);



}

void CsolarView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CsolarView diagnostics

#ifdef _DEBUG
void CsolarView::AssertValid() const
{
	CView::AssertValid();
}

void CsolarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
void CsolarView::OnButtonsolarStart()
{
	// TODO: Add your command handler code here
	//AfxMessageBox(_T("Start"));
	NewThread = AfxBeginThread(CsolarView::StartThread, this);
}
void CsolarView::OnButtonsolarStop()
{
	NewThread->SuspendThread();

}

CsolarDoc* CsolarView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsolarDoc)));
	return (CsolarDoc*)m_pDocument;
}
#endif //_DEBUG


// CsolarView message handlers
UINT CsolarView::StartThread(LPVOID Param)
{
    CsolarView* pView = (CsolarView*)Param;

	
	int j = 6;
	
	while(1)
	{
		j = j + 6;
		pView->x = 300 + 100 * cos(j);//for inner loop
		pView->y = 200 + 100 * sin(j);

		pView->x1 = 300 + 150 * cos(j + 10);//for outer loop
		pView->y1 = 200 + 150 * sin(j + 10);

		pView->Invalidate();
		
		Sleep(300);


	}

	// TODO: Add your implementation code here.
	return 0;
}


