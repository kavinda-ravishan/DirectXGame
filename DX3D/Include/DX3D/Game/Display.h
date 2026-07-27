#pragma once
#include <DX3D/Window/Window.h>

namespace dx3d {
	class Display final : public Window {
	public:
		explicit Display(const DisplayDesc& desc);
		~Display();

		SwapChain& GetSwapChain() noexcept;

	private:
		SwapChainPtr _swap_chain{};
	};
} // namespace dx3d
