#include "DX3D/Game/Game.h"
#include "DX3D/Window/Window.h"
#include "DX3D/Graphics/GraphicsEngine.h"

dx3d::Game::Game() {
	_graphics_engine = std::make_unique<GraphicsEngine>();
	_window = std::make_unique<Window>();
}

dx3d::Game::~Game() {}
