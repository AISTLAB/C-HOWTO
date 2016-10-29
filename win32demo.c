/*
windows api gui demo
painting and load bitmap
c version
winxos 2015-09-26
*/
#include<windows.h>

LRESULT  CALLBACK  WndProc(HWND, UINT, WPARAM, LPARAM);
int  WINAPI  WinMain(HINSTANCE  hInstance, HINSTANCE  hPrevInstance, LPSTR  lpcmdLine, int   nCmdShow)
{
	static TCHAR  szAppName[] = TEXT(" HelloWorld ");
	static TCHAR  szClassName[] = TEXT(" HelloWorldClass ");
	HWND hwnd;
	MSG  msg;
	WNDCLASS  wndclass;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground =(HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szClassName;

	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT(" This program requires Windows NT !"), szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(szClassName,
		TEXT("hello"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		600, 600, //window size
		NULL, NULL,
		hInstance,
		NULL);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return  msg.wParam;
}
void update(HDC hdc)
{

}
LRESULT CALLBACK WndProc(HWND  hwnd,UINT  message,WPARAM  wParam,LPARAM  lParam)
{
	HDC hdc,hdcMem;
	PAINTSTRUCT ps;
	HPEN hpen,oldpen;
	switch (message)
	{
	case WM_CREATE:
		

		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		hdcMem=CreateCompatibleDC(hdc);
		HBITMAP bufbmp=CreateCompatibleBitmap (hdcMem,600,600);
		SelectObject(hdcMem, bufbmp);
		

		//HBRUSH hbrush=CreateSolidBrush(RGB(150,250,250));
		RECT rect;  
		SetRect(&rect, 0, 0, 600, 600); 
		HBRUSH hbrush=(HBRUSH)GetStockObject(WHITE_BRUSH); 
		FillRect(hdcMem,&rect,hbrush);

		hpen = CreatePen(PS_SOLID,5,RGB(255,250,0));
		oldpen=(HPEN)SelectObject(hdcMem, hpen); 

		MoveToEx(hdcMem, 100, 100,NULL);
		LineTo(hdcMem, 500, 500);
		BitBlt(hdc, 0, 0, 600, 600, hdcMem, 0, 0, SRCCOPY);

		SelectObject(hdcMem,oldpen);
		//DrawText(hdc, TEXT("Hello , Windows !"),-1, &rect,DT_SINGLELINE | DT_CENTER| DT_VCENTER);
		DeleteObject(hbrush);
		DeleteObject(hpen);
		EndPaint(hwnd, &ps);

		return  0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return  0;
	}
	return  DefWindowProc(hwnd, message, wParam, lParam);
}
