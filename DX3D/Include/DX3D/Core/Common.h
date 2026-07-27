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
		GraphicsDevice& graphics_device;
	};

	struct GraphicsEngineDesc {
		BaseDesc base;
	};

	struct GraphicsDeviceDesc {
		BaseDesc base;
	};

	struct SwapChainDesc {
		void* win_handle{};
		Rect win_size{};
	};

	enum class ShaderType {
		VertexShader = 0,
		PixelShader
	};

	struct ShaderCompileDesc {
		const char* shader_source_name{};
		const void* shader_source_code{};
		size_t shader_source_code_size{};
		const char* shader_entry_ponit{};
		ShaderType shader_type;
	};

	struct GraphicsPipelineStateDesc {
		const ShaderBinary& vs;
		const ShaderBinary& ps;
	};

	struct ShaderBinaryData {
		const void* data{};
		size_t data_size{};
	};

	struct GameDesc {
		Rect window_size{ 1280, 720 };
		Logger::LogLevel log_level = Logger::LogLevel::Error;
	};

} // namespace dx3d
