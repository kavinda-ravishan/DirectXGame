#include <Windows.h>
#include <stdexcept>
#include "DX3D/Window/Window.h"

static LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}

	return 0;
}

dx3d::Window::Window(const WindowDesc& desc): Base(desc.base) {
	
	GetLogger().Log(Logger::LogLevel::Info, "Initializing Window");

	auto RegisterWindowClass = []() {
		WNDCLASSEX wc{};
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.lpszClassName = L"DX3DWindow";
		wc.lpfnWndProc = WindowProcedure;
		return RegisterClassEx(&wc);
	};
	
	static const auto window_class_id = std::invoke(RegisterWindowClass);

	if (window_class_id == 0) {
		GetLogger().Log(Logger::LogLevel::Error, "Failed to register window class");
		throw std::runtime_error("Failed to register window class");
	}

	const DWORD window_style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU;

	RECT rc = { 0, 0, 1280, 720 };
	AdjustWindowRect(&rc, window_style, false);

	_win_handle = CreateWindowEx(
		NULL, 
		MAKEINTATOM(window_class_id), 
		L"C++ 3D Game", 
		window_style, 
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		rc.right - rc.left, 
		rc.bottom - rc.top, 
		NULL, 
		NULL, 
		NULL, 
		NULL);

	if (nullptr == _win_handle) {
		GetLogger().Log(Logger::LogLevel::Error, "Failed to create window");
		throw std::runtime_error("Failed to create window");
	}

	ShowWindow(static_cast<HWND>(_win_handle), SW_SHOW);
}

dx3d::Window::~Window() {
	GetLogger().Log(Logger::LogLevel::Info, "Destroying Window");

	DestroyWindow(static_cast<HWND>(_win_handle));
}
