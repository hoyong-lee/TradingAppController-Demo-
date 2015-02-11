
// TradingAppControllerView.cpp : implementation of the CTradingAppControllerView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TradingAppController.h"
#endif

#include "TradingAppControllerDoc.h"
#include "TradingAppControllerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTradingAppControllerView

IMPLEMENT_DYNCREATE(CTradingAppControllerView, CView)

BEGIN_MESSAGE_MAP(CTradingAppControllerView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTradingAppControllerView construction/destruction

CTradingAppControllerView::CTradingAppControllerView()
{
	// TODO: add construction code here

}

CTradingAppControllerView::~CTradingAppControllerView()
{
}

BOOL CTradingAppControllerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTradingAppControllerView drawing

void CTradingAppControllerView::OnDraw(CDC* /*pDC*/)
{
	CTradingAppControllerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTradingAppControllerView printing

BOOL CTradingAppControllerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTradingAppControllerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTradingAppControllerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CTradingAppControllerView diagnostics

#ifdef _DEBUG
void CTradingAppControllerView::AssertValid() const
{
	CView::AssertValid();
}

void CTradingAppControllerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTradingAppControllerDoc* CTradingAppControllerView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTradingAppControllerDoc)));
	return (CTradingAppControllerDoc*)m_pDocument;
}
#endif //_DEBUG


// CTradingAppControllerView message handlers
