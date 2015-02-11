#include "stdafx.h"
#include "ControlUtils.h"


ControlUtils::ControlUtils()
{
}


ControlUtils::~ControlUtils()
{
}

void ControlUtils::sendKeyInput(HWND hWnd, DWORD dwKey, int nSleepInterval)
{
	::PostMessage(hWnd, WM_KEYDOWN, dwKey, NULL);
	::Sleep(50);
	::PostMessage(hWnd, WM_KEYUP, dwKey, NULL);
	::Sleep(nSleepInterval);
}

vector<HWND> ControlUtils::getVisibleDlgWnds(HWND hWndParent)
{
	vector<HWND> dlgHwnds;

	HWND hWndDlg = ::FindWindowEx(hWndParent, NULL, _T("#32770"), NULL);
	for (hWndDlg; hWndDlg != NULL; hWndDlg = ::FindWindowEx(hWndParent, hWndDlg, _T("#32770"), NULL))
	{
		if (::IsWindowVisible(hWndDlg))
			dlgHwnds.push_back(hWndDlg);
	}

	return dlgHwnds;
}
