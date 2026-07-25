#pragma once
#include <DX3D/Core/Core.h>
#include <DX3D/Core/Logger.h>

namespace dx3d {

	// struct for dependency injection pattern with dependency aggregation strategy
	struct BaseDesc {
		Logger& logger;
	};

	struct WindowDesc {
		BaseDesc base;
	};

	struct GraphicsEngineDesc {
		BaseDesc base;
	};

	struct RenderSystemDesc {
		BaseDesc base;
	};

	struct GameDesc {
		Logger::LogLevel log_level = Logger::LogLevel::Error;
	};

} // namespace dx3d
