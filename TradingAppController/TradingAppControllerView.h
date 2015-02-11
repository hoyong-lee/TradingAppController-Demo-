
// TradingAppControllerView.h : interface of the CTradingAppControllerView class
//

#pragma once


class CTradingAppControllerView : public CView
{
protected: // create from serialization only
	CTradingAppControllerView();
	DECLARE_DYNCREATE(CTradingAppControllerView)

// Attributes
public:
	CTradingAppControllerDoc* GetDocument() const;

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
	virtual ~CTradingAppControllerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TradingAppControllerView.cpp
inline CTradingAppControllerDoc* CTradingAppControllerView::GetDocument() const
   { return reinterpret_cast<CTradingAppControllerDoc*>(m_pDocument); }
#endif

