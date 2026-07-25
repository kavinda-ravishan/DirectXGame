#pragma once
#include "DX3D/Graphics/GraphicsResource.h"

namespace dx3d {

class SwapChain final : public GraphicsResource {

public:
	SwapChain(const SwapChainDesc& desc, const GraphicsResourceDesc& g_desc);

	~SwapChain();
private:
	Microsoft::WRL::ComPtr<IDXGISwapChain> _swap_chain{ nullptr };
};

} // namespace dx3d
