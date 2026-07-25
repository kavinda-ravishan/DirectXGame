#pragma once
#include "DX3D/Core/Base.h"

namespace dx3d {

	class Game : public Base {
	public:
		explicit Game(const GameDesc& desc);
		virtual ~Game() override;

		virtual void Run() final;
	private:
		// order of initialization is important here, graphics engine must be initialized before window
		// and graphics engine must be destroyed after window.
		// logger must initialized before all and destroyed after all.
		std::unique_ptr<Logger> _logger_ptr{ nullptr };
		std::unique_ptr<GraphicsEngine> _graphics_engine{ nullptr };
		std::unique_ptr<Display> _display{ nullptr };
		bool _is_running{ true };
	};

} // namespace dx3d
