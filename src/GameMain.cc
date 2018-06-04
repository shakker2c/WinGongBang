#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
using namespace std;

#include <Windows.h>
#include "resource.h"

// ������Ϸ����
#include "GameLogic\MainLogic.h"
#include "GameLogic\CChess.h"
#include "GameLogic\CChessBoard.h"

#define MAX_STR_LEN 100

HINSTANCE g_hInstance;
WCHAR szClassName[MAX_STR_LEN] = L"GoBangGame";

// ע�ᴰ��
ATOM MyRegisterClass(HINSTANCE);
// ���´���
BOOL MyUpdateWindow(int);
// ��ʾ����
void MyShowWindow(HWND, int);
// ��Ϣ����
void MyProcMsg();
// �¼������ص�
LRESULT CALLBACK MyWndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR lpCmdLine,
	int nCmdShow) {
	// �����ò���
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	// end
	
	MyRegisterClass(hInstance);

	if (!MyUpdateWindow(nCmdShow)) {
		return FALSE;
	}
	MyProcMsg();

	return 0;
}

ATOM 
MyRegisterClass(HINSTANCE hInstance) {
	g_hInstance = hInstance;

	WNDCLASSEX wcs;
	memset(&wcs, 0, sizeof(WNDCLASSEX));

	wcs.cbSize = (sizeof(WNDCLASSEX));
	wcs.cbWndExtra = 0;
	wcs.cbClsExtra = 0;
	wcs.style = CS_HREDRAW | CS_VREDRAW;
	wcs.hInstance = hInstance;
	wcs.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcs.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wcs.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcs.lpszClassName = szClassName;
	wcs.lpszMenuName = NULL;
	wcs.lpfnWndProc = MyWndProc;
	wcs.hIconSm = LoadIcon(wcs.hInstance, MAKEINTRESOURCE(IDI_ICON1));

	return RegisterClassEx(&wcs);
}

BOOL 
MyUpdateWindow(int nCmdShow) {
	HWND hWnd;

	hWnd = CreateWindowW(szClassName, L"������", WS_OVERLAPPEDWINDOW | WS_DISABLED,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, g_hInstance, NULL);
	if (!hWnd) {
		MessageBox(hWnd, L"Error", L"��ʼ����Դʧ��", MB_OKCANCEL | MB_ICONERROR);
		return FALSE;
	}

	MyShowWindow(hWnd, nCmdShow);

	return TRUE;
}

void
MyShowWindow(HWND hWnd, int nCmdShow) {
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
}

void 
MyProcMsg() {
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		if (!TranslateAccelerator(msg.hwnd, NULL, &msg)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

LRESULT CALLBACK 
MyWndProc(HWND hWnd,
	UINT msgID, 
	WPARAM wParam, 
	LPARAM lParam) {
	switch (msgID) {
	case WM_CREATE: {

	}break;
	case WM_PAINT: {

	}break;
	case WM_DESTROY: {
		PostQuitMessage(0);
	}break;
	default:
		return DefWindowProc(hWnd, msgID, wParam, lParam);
	}

	return 0;
}