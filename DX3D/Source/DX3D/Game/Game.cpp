#include "DX3D/Core/Logger.h"
#include "DX3D/Game/Game.h"
#include "DX3D/Window/Window.h"
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
	_window = std::make_unique<Window>(WindowDesc({_logger}));

	_logger_ptr->Log(Logger::LogLevel::Info, "Game initialized successfully.");
}

dx3d::Game::~Game() {
	_logger_ptr->Log(Logger::LogLevel::Info, "Starting game destruction.");
}
