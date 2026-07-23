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
		Window* _display{ nullptr };
		bool _is_running{ true };
	};

} // namespace dx3d
