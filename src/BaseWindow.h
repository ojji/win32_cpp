#pragma once
#include <Windows.h>

template <class TWindow>
class BaseWindow
{
	public:
		BaseWindow() : m_hWnd(nullptr) {};
		static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
		{
			TWindow* pThis = nullptr;
			if (uMsg == WM_NCCREATE)
			{
				CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
				pThis = reinterpret_cast<TWindow*>(pCreate->lpCreateParams);
				SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis));
				pThis->m_hWnd = hWnd;
			}
			else
			{
				pThis = reinterpret_cast<TWindow*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
			}
			if (pThis)
			{
				return pThis->HandleMessage(uMsg, wParam, lParam);
			}
			else
			{
				return DefWindowProc(hWnd, uMsg, wParam, lParam);
			}
		}

		bool Create(LPWSTR lpWindowName, int width, int height, DWORD dwStyle, int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, DWORD dwExStyle = 0) 
		{
			WNDCLASS wc{};
			wc.lpfnWndProc = TWindow::WindowProc;
			wc.lpszClassName = ClassName();
			wc.hInstance = GetModuleHandle(nullptr);

			RegisterClass(&wc);
			
			m_hWnd = CreateWindowEx(dwExStyle, ClassName(), lpWindowName, dwStyle, x, y, width, height, NULL, NULL, GetModuleHandle(nullptr), this);

			return (m_hWnd ? true : false);
		}
		HWND Window() const { return m_hWnd; }
	protected:
		virtual PWSTR ClassName() const = 0;
		virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
		HWND m_hWnd;
};
