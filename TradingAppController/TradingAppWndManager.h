#pragma once

#include <vector>

using namespace std;

enum LINKRESULT
{
	SUCCEEDED = 0,
	NOT_FOUND_WINDOW,
	FOUND_MULTIPLE_WINDOWS,
};

class TradingAppWndManager
{
public:
	TradingAppWndManager();
	~TradingAppWndManager();

	static TradingAppWndManager* getInstance();
	
	void		EnumWindowProc(HWND hWnd);

protected:

	void getTradeAppTopWndHandle();
	bool getMDIFrameHwnd();
	bool getStatusbarWndHandle();
	bool getTreeViewWndHandle();
	bool getBuyDlgHwnds();
	bool getSellDialogHwnds();
	bool getWithdrawDlgHwnds();
	bool getMoneyBalanceHwnds();
	HWND getActiveDlgWnd();

protected:

	static TradingAppWndManager* s_pInstance;

protected:
	
	vector<HWND> m_listTradinAppWnds;

	HWND m_hWndTopWindow;
	HWND m_hWndMDIFrame;
	HWND m_hWndStatusbar;
	HWND m_hWndTreeview;
	HWND m_hWndBuyDlg;
	HWND m_hWndSellDlg;
	HWND m_hWndWithdrawDlg;
	HWND m_hWndMoneyBalanceDlg;
	HWND m_hWnd_Buy_Stock_Code;
	HWND m_hWnd_Buy_Stock_Name;
	HWND m_hWnd_Buy_Stock_Price;
	HWND m_hWnd_Buy_Available_Stock;
	HWND m_hWnd_Buy_Stock_Amount;
	HWND m_hWnd_Buy_Buy_Button;
	HWND m_hWnd_Sell_Stock_Code;
	HWND m_hWnd_Sell_Stock_Name;
	HWND m_hWnd_Sell_Stock_Price;
	HWND m_hWnd_Sell_Available_Stock;
	HWND m_hWnd_Sell_Stock_Amount;
	HWND m_hWnd_Sell_Sell_Button;
	HWND m_hWnd_Withdraw_SelectAll_Button;
	HWND m_hWnd_Withdraw_Withdraw_Button;
	HWND m_hWndMoneyBalance_Balance;
	HWND m_hWnd_MoneyBalance_Frozen;
	HWND m_hWndMoneyBalance_Available;
	HWND m_hWnd_MoneyBalance_Desired;
	HWND m_hWnd_MoneyBalance_StockCost;
	HWND m_hWnd_MoneyBalance_MarketCost;

};

