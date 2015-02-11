#include "stdafx.h"
#include "TradingAppWndManager.h"
#include "ControlUtils.h"

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

HWND TradingAppWndManager::getActiveDlgWnd()
{
	vector<HWND> dlgHWnds = ControlUtils::getVisibleDlgWnds(m_hWndMDIFrame);
	if (dlgHWnds.size() > 0)
		return dlgHWnds[0];

	return NULL;
}


bool TradingAppWndManager::getBuyDlgHwnds()
{
	ControlUtils::sendKeyInput(m_hWndTopWindow, VK_F1, 1500);
	m_hWndBuyDlg = getActiveDlgWnd();
	if (m_hWndBuyDlg == NULL)
		return false;

	m_hWnd_Buy_Stock_Code = ::FindWindowEx(m_hWndBuyDlg, NULL, _T("Edit"), NULL);
	if (m_hWnd_Buy_Stock_Code == NULL)
		return false;

	m_hWnd_Buy_Stock_Name = ::FindWindowEx(m_hWndBuyDlg, m_hWnd_Buy_Stock_Code, _T("Static"), NULL);
	if (m_hWnd_Buy_Stock_Name == NULL)
		return false;

	m_hWnd_Buy_Stock_Price = ::FindWindowEx(m_hWndBuyDlg, m_hWnd_Buy_Stock_Name, _T("Edit"), NULL);
	if (m_hWnd_Buy_Stock_Price == NULL)
		return false;

	m_hWnd_Buy_Available_Stock = ::FindWindowEx(m_hWndBuyDlg, m_hWnd_Buy_Stock_Price, _T("Static"), NULL);
	if (m_hWnd_Buy_Available_Stock == NULL)
		return false;

	m_hWnd_Buy_Stock_Amount = ::FindWindowEx(m_hWndBuyDlg, m_hWnd_Buy_Available_Stock, _T("Edit"), NULL);
	if (m_hWnd_Buy_Stock_Amount == NULL)
		return false;

	m_hWnd_Buy_Buy_Button = ::FindWindowEx(m_hWndBuyDlg, m_hWnd_Buy_Stock_Amount, _T("Button"), NULL);
	if (m_hWnd_Buy_Buy_Button == NULL)
		return false;

	return true;

}

bool TradingAppWndManager::getSellDialogHwnds()
{
	ControlUtils::sendKeyInput(m_hWndTopWindow, VK_F2, 1500);
	m_hWndSellDlg = getActiveDlgWnd();
	if (m_hWndSellDlg == NULL)
		return false;

	m_hWnd_Sell_Stock_Code = ::FindWindowEx(m_hWndSellDlg, NULL, _T("Edit"), NULL);
	if (m_hWnd_Sell_Stock_Code == NULL)
		return false;

	m_hWnd_Sell_Stock_Name = ::FindWindowEx(m_hWndSellDlg, m_hWnd_Sell_Stock_Code, _T("Static"), NULL);
	if (m_hWnd_Sell_Stock_Name == NULL)
		return false;

	m_hWnd_Sell_Stock_Price = ::FindWindowEx(m_hWndSellDlg, m_hWnd_Sell_Stock_Name, _T("Edit"), NULL);
	if (m_hWnd_Sell_Stock_Price == NULL)
		return false;

	m_hWnd_Sell_Available_Stock = ::FindWindowEx(m_hWndSellDlg, m_hWnd_Sell_Stock_Price, _T("Static"), NULL);
	if (m_hWnd_Sell_Available_Stock == NULL)
		return false;

	m_hWnd_Sell_Stock_Amount = ::FindWindowEx(m_hWndSellDlg, m_hWnd_Sell_Available_Stock, _T("Edit"), NULL);
	if (m_hWnd_Sell_Stock_Amount == NULL)
		return false;

	m_hWnd_Sell_Sell_Button = ::FindWindowEx(m_hWndSellDlg, m_hWnd_Sell_Stock_Amount, _T("Button"), NULL);
	if (m_hWnd_Sell_Sell_Button == NULL)
		return false;

	return true;
}

bool TradingAppWndManager::getWithdrawDlgHwnds()
{
	ControlUtils::sendKeyInput(m_hWndTopWindow, VK_F3, 1500);
	m_hWndWithdrawDlg = getActiveDlgWnd();
	if (m_hWndWithdrawDlg == NULL)
		return false;

	m_hWnd_Withdraw_SelectAll_Button = ::FindWindowEx(m_hWndWithdrawDlg, NULL, _T("Button"), NULL);
	if (m_hWnd_Withdraw_SelectAll_Button == NULL)
		return false;

	m_hWnd_Withdraw_Withdraw_Button = ::FindWindowEx(m_hWndWithdrawDlg, m_hWnd_Withdraw_SelectAll_Button, _T("Button"), NULL);
	if (m_hWnd_Withdraw_Withdraw_Button)
		return false;

	return true;
}

bool TradingAppWndManager::getMoneyBalanceHwnds()
{
	ControlUtils::sendKeyInput(m_hWndTopWindow, VK_F3, 1500);
	m_hWndMoneyBalanceDlg = getActiveDlgWnd();
	if (m_hWndMoneyBalanceDlg == NULL)
		return false;

	HWND hWnd1 = ::FindWindowEx(m_hWndMoneyBalanceDlg, 0, _T("Static"), _T("资金余额"));
	HWND hWnd2 = ::FindWindowEx(m_hWndMoneyBalanceDlg, hWnd1, _T("Static"), NULL);
	HWND hWnd3 = ::FindWindowEx(m_hWndMoneyBalanceDlg, hWnd2, _T("Static"), NULL);

	if (hWnd3 == NULL)
		return false;

	m_hWndMoneyBalance_Balance = ::FindWindowEx(m_hWndMoneyBalanceDlg, hWnd3, _T("Static"), NULL);
	m_hWnd_MoneyBalance_Frozen = ::FindWindowEx(m_hWndMoneyBalanceDlg, m_hWndMoneyBalance_Balance, _T("Static"), NULL);
	m_hWndMoneyBalance_Available = ::FindWindowEx(m_hWndMoneyBalanceDlg, m_hWnd_MoneyBalance_Frozen, _T("Static"), NULL);
	
	if (m_hWndMoneyBalance_Available == NULL)
		return false;

	HWND hWnd4 = ::FindWindowEx(m_hWndMoneyBalanceDlg, m_hWndMoneyBalance_Available, _T("Static"), NULL);
	HWND hWnd5 = ::FindWindowEx(m_hWndMoneyBalanceDlg, hWnd4, _T("Static"), NULL);
	HWND hWnd6 = ::FindWindowEx(m_hWndMoneyBalanceDlg, hWnd5, _T("Static"), NULL);

	m_hWnd_MoneyBalance_Desired = ::FindWindowEx(m_hWndMoneyBalanceDlg, hWnd6, _T("Static"), NULL);
	m_hWnd_MoneyBalance_StockCost = ::FindWindowEx(m_hWndMoneyBalanceDlg, m_hWnd_MoneyBalance_Desired, _T("Static"), NULL);
	m_hWnd_MoneyBalance_MarketCost = ::FindWindowEx(m_hWndMoneyBalanceDlg, m_hWnd_MoneyBalance_StockCost, _T("Static"), NULL);
	
	if (m_hWnd_MoneyBalance_MarketCost == NULL)
		return false;

	return true;
}