#pragma once

#include <cstdint>
#include <stdexcept>
#include <memory>

namespace dx3d {

	class Logger;

	class Base;
	class Window;
	class Display;
	class Game;

	class GraphicsEngine;
	class GraphicsDevice;
	class SwapChain;
	class DeviceContext;
	class ShaderBinary;
	class GraphicsPipelineState;

	using i32 = std::int32_t;
	using ui32 = std::uint32_t;
	using f32 = float;
	using d64 = double;

	using SwapChainPtr = std::shared_ptr<SwapChain>;
	using DeviceContextPtr = std::shared_ptr<DeviceContext>;
	using ShaderBinaryPtr = std::shared_ptr<ShaderBinary>;
	using GraphicsPipelineStatePtr = std::shared_ptr<GraphicsPipelineState>;

} // namespace dx3d
