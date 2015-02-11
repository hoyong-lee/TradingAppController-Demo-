#include "stdafx.h"
#include "TradingAppWndManager.h"

TradingAppWndManager* TradingAppWndManager::s_pInstance = NULL;

TradingAppWndManager::TradingAppWndManager()
{

}


TradingAppWndManager::~TradingAppWndManager()
{

}

TradingAppWndManager* TradingAppWndManager::getInstance()
{
	if (s_pInstance == NULL)
		s_pInstance = new TradingAppWndManager();

	return s_pInstance;
}

bool EnumWindowsProc(HWND hWnd, LPDWORD lParam)
{
	TradingAppWndManager::getInstance()->EnumWindowProc(hWnd);
	return true;
}

void TradingAppWndManager::EnumWindowProc(HWND hWnd)
{
	m_listTradinAppWnds.push_back(hWnd);
}

void TradingAppWndManager::getTradeAppTopWndHandle()
{
	m_listTradinAppWnds.clear();
	::EnumWindows((WNDENUMPROC)EnumWindowsProc, NULL);

	vector<HWND> topWnds;
	for (int i = 0; i < m_listTradinAppWnds.size(); i++)
	{	
		TCHAR szWindowText[MAX_PATH];
		::GetWindowText(m_listTradinAppWnds[i], szWindowText, MAX_PATH);

		if (_tcsstr(szWindowText, _T("网上股票交易系统5.0")) != NULL)
			topWnds.push_back(m_listTradinAppWnds[i]);
	}

	if (topWnds.size() == 1)
		m_hWndTopWindow = topWnds[0];

}

bool TradingAppWndManager::getMDIFrameHwnd()
{
	m_hWndMDIFrame = ::FindWindowEx(m_hWndTopWindow, NULL, _T("AfxMDIFrame42s"), NULL);
	return (m_hWndMDIFrame != NULL);
}

bool TradingAppWndManager::getStatusbarWndHandle()
{
	m_hWndStatusbar = ::FindWindowEx(m_hWndTopWindow, NULL, _T("msctls_statusbar32"), NULL);
	return m_hWndStatusbar != NULL;
}

bool TradingAppWndManager::getTreeViewWndHandle()
{
	HWND hWnd1 = ::FindWindowEx(m_hWndMDIFrame, NULL, _T("AfxWnd42s"), NULL);
	if (hWnd1 == NULL)
		return false;

	HWND hWnd2 = ::FindWindowEx(hWnd1, NULL, _T("Afx:400000:0"), NULL);
	if (hWnd2 == NULL)
		return false;

	HWND hWnd3 = ::FindWindowEx(hWnd2, NULL, _T("AfxWnd42s"), NULL);
	if (hWnd3 == NULL)
		return false;

	m_hWndTreeview = ::FindWindowEx(hWnd3, NULL, _T("SysTreeView32"), NULL);
	return m_hWndTreeview != NULL;
}

