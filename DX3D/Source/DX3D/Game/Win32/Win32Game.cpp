#include <Windows.h>
#include "DX3D/Game/Game.h"

void dx3d::Game::Run() {

	MSG msg{};
	while (_is_running) {
		
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {

			if (msg.message == WM_QUIT) {
				_is_running = false;
				break;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		OnInternalUpdate();
	}
}
