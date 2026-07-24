#pragma once
#include "DX3D/Core/Base.h"
#include "DX3D/Core/Core.h"

namespace dx3d {

	class Game : public Base {
	public:
		Game();
		virtual ~Game() override;

		virtual void Run() final;
	private:
		// order of initialization is important here, graphics engine must be initialized before window
		// and graphics engine must be destroyed after window
		std::unique_ptr<GraphicsEngine> _graphics_engine{ nullptr };
		std::unique_ptr<Window> _window{ nullptr };
		bool _is_running{ true };
	};

} // namespace dx3d
