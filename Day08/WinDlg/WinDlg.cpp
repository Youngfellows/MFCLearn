#include<windows.h>
#include "resource.h"

HINSTANCE g_hInstance = 0;

INT_PTR CALLBACK DlgProc(HWND hwndlg, UINT msgID, WPARAM wParam, LPARAM lParam)
{
	switch (msgID)
	{
	case WM_DESTROY:
		MessageBox(NULL, "��Ҫ����", "Infor", MB_OK);
		break;
	case WM_SYSCOMMAND:
		if (wParam == SC_CLOSE)
		{
			HWND hWnd = GetParent(hwndlg);
			EnableWindow(hWnd, TRUE);
			DestroyWindow(hwndlg);//������ģʽ�Ի���, �мɲ���EndDialog
			//EndDialog(hwndlg, 1001);//ֻ��������ģʽ�Ի���, ��������ģʽ�Ի���
		}
		break;
	default:
		break;
	}
	return FALSE;//�Ի������Ϣ���������Ի��򴰿ڴ���������
}

void OnNoModel(HWND hWnd)
{
	EnableWindow(hWnd, FALSE);
	//HWND hDlg = CreateDialog(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DlgProc);//ֱ�Ӵ���

	//ͨ����ӷ�ʽ������ģʽ�Ի���
	HRSRC hRs = FindResource(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), RT_DIALOG);
	HGLOBAL hGl = LoadResource(g_hInstance, hRs);
	LPCDLGTEMPLATE pTemplate = (LPCDLGTEMPLATE)LockResource(hGl);
	HWND hDlg = CreateDialogIndirect(g_hInstance, pTemplate, hWnd, DlgProc);

	ShowWindow(hDlg, SW_SHOW);
}

void OnCommand(HWND hWnd, WPARAM wParam)
{
	switch (LOWORD(wParam))
	{
	case ID_NOMODEL:
		OnNoModel(hWnd);
		break;
	default:
		break;
	}
}

//���ڴ�����( �Զ��壬������Ϣ)
LRESULT CALLBACK WndProc(HWND hWnd, UINT msgID, WPARAM wParam, LPARAM lParam)
{
	switch (msgID)
	{
	case WM_COMMAND:
		OnCommand(hWnd, wParam);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return DefWindowProc(hWnd, msgID, wParam, lParam);
}

/*
* ��ں���
*/
int CALLBACK WinMain(HINSTANCE hIns, HINSTANCE hPreIns, LPSTR lpCmdLine, int nCmdShow)
{
	g_hInstance = hIns;
	//ע�ᴰ����
	WNDCLASS wc = { 0 };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = NULL;
	wc.hIcon = NULL;
	wc.hInstance = hIns;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = "Main";
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);//(CHAR *)IDR_MENU1;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wc);//���������и�ֵȫ��д�����ϵͳ��

	//���ڴ洴������
	HWND hWnd = CreateWindowEx(0, "Main", "window", WS_OVERLAPPEDWINDOW, 100, 100, 500, 500, NULL, NULL, hIns, NULL);

	//��ʾ����
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	//��Ϣѭ��
	MSG nMsg = { 0 };
	while (GetMessage(&nMsg, NULL, 0, 0))
	{
		TranslateMessage(&nMsg);
		DispatchMessage(&nMsg);//����Ϣ�������ڴ�����������
	}
	return 0;
}