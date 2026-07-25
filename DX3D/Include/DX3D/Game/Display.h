#pragma once
#include "DX3D/Window/Window.h"

namespace dx3d {
	class Display final : public Window {
	public:
		explicit Display(const DisplayDesc& desc);

	private:
		SwapChainPtr _swap_chain{ nullptr };
	};
} // namespace dx3d
