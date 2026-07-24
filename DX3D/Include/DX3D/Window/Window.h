#pragma once
#include "DX3D/Core/Base.h"

namespace dx3d {

	class Window : public Base {
	public:
		explicit Window(const WindowDesc& desc);
		virtual ~Window() override;
	private:
		void* _win_handle{ nullptr };
	};

} // namespace dx3d
