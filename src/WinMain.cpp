#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_PAINT:
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	const LPCWSTR pClassName = L"Falcon3D";

	WNDCLASSEXW windowConfig = { 0 };
	windowConfig.cbSize = sizeof(WNDCLASSEXW);
	windowConfig.style = CS_OWNDC;
	windowConfig.lpfnWndProc = WndProc;
	windowConfig.cbClsExtra = 0;
	windowConfig.cbWndExtra = 0;
	windowConfig.hInstance = hInstance;
	windowConfig.hIcon = nullptr;
	windowConfig.hCursor = nullptr;
	windowConfig.hbrBackground = nullptr;
	windowConfig.lpszMenuName = nullptr;
	windowConfig.lpszClassName = pClassName;
	windowConfig.hIconSm = nullptr;

	RegisterClassEx(&windowConfig);

	HWND hWindow = CreateWindowEx(0, pClassName, pClassName, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480, nullptr, nullptr, hInstance, nullptr);

	SetLayeredWindowAttributes(hWindow, RGB(0, 0, 0), 0, LWA_COLORKEY);

	ShowWindow(hWindow, SW_SHOW);

	MSG msg;
	BOOL gResult;
	while (gResult = GetMessage(&msg, nullptr, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult == -1)
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}
}