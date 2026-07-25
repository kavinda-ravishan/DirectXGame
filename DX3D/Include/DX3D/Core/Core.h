#pragma once

#include <cstdint>
#include <stdexcept>
#include <memory>

namespace dx3d {

	class Base;
	class Window;
	class Display;
	class Game;

	class GraphicsEngine;
	class RenderSystem;
	class SwapChain;

	class Logger;


	using i32 = std::int32_t;
	using ui32 = std::uint32_t;
	using f32 = float;
	using d64 = double;

	using SwapChainPtr = std::shared_ptr<SwapChain>;

} // namespace dx3d
