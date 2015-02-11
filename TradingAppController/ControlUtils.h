#pragma once
#include <vector>

using namespace std;

class ControlUtils
{
public:
	ControlUtils();
	~ControlUtils();

public:

	static void sendKeyInput(HWND hWnd, DWORD dwKey, int nSleepInterval);
	static vector<HWND> getVisibleDlgWnds(HWND hWndParent);
};

