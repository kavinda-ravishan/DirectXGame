#include "DX3D/Core/Logger.h"
#include "DX3D/Game/Game.h"
#include "DX3D/Game/Display.h"
#include "DX3D/Graphics/GraphicsEngine.h"

dx3d::Game::Game(const GameDesc& desc) 
	: Base(
		// make a logger instance and pass it to Base class
		{*std::make_unique<Logger>(desc.log_level).release()}
	), 
	// this will allow Game class to manage the lifetime of the logger instance
	_logger_ptr(&_logger)
{
	_graphics_engine = std::make_unique<GraphicsEngine>(GraphicsEngineDesc({_logger}));
	_display = std::make_unique<Display>(DisplayDesc({_logger, desc.window_size, _graphics_engine->GetGraphicsDevice()}));

	DX3DLogInfo("Game initialized successfully.");
}

dx3d::Game::~Game() {
	DX3DLogInfo("Game is shutting down...");
}

void dx3d::Game::OnInternalUpdate() {
	_graphics_engine->Render(_display->GetSwapChain());
}
