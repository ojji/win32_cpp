#include "SampleWindow.h"
#include <Windows.h>

PWSTR SampleWindow::ClassName() const
{
    return L"Sample window class";
}

LRESULT SampleWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
        default:
            return DefWindowProc(Window(), uMsg, wParam, lParam);
    }
}
