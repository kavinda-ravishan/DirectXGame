#pragma once
#include <DX3D/Core/Core.h>
#include <DX3D/Core/Logger.h>
#include <DX3D/Math/Rect.h>

namespace dx3d {

	// struct for dependency injection pattern with dependency aggregation strategy
	struct BaseDesc {
		Logger& logger;
	};

	struct WindowDesc {
		BaseDesc base;
		Rect size{};
	};

	struct DisplayDesc {
		WindowDesc window;
		RenderSystem& render_system;
	};

	struct GraphicsEngineDesc {
		BaseDesc base;
	};

	struct RenderSystemDesc {
		BaseDesc base;
	};

	struct SwapChainDesc {
		void* win_handle{};
		Rect win_size{};
	};

	struct GameDesc {
		Rect window_size{ 1280, 720 };
		Logger::LogLevel log_level = Logger::LogLevel::Error;
	};

} // namespace dx3d
