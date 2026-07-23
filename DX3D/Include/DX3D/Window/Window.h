#pragma once
#include "DX3D/Core/Base.h"

namespace dx3d {

	class Window : public Base {
	public:
		Window();
		virtual ~Window() override;
	private:
		void* _handle{ nullptr };
	};

} // namespace dx3d
