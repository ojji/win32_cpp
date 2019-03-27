#include <Windows.h>
#include "SampleWindow.h"

int WINAPI wWinMain(HINSTANCE /*hInstance*/, HINSTANCE, PWSTR /*pCmdLine*/, int nCmdShow)
{
	SampleWindow sw;
	if (!sw.Create(L"Sample window", 1600, 900, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX))
	{
		return 0;
	}

	ShowWindow(sw.Window(), nCmdShow);

	bool running = true;
	MSG msg {};
	while(running)
	{
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				running = false;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}
