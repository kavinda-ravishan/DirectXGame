#pragma once
#include "DX3D/Graphics/GraphicsResource.h"

namespace dx3d {

class SwapChain final : public GraphicsResource {

public:
	SwapChain(const SwapChainDesc& desc, const GraphicsResourceDesc& g_desc);
	void Present(bool vsync = false);

private:
	void ReloadBuffers();

private:
	Microsoft::WRL::ComPtr<IDXGISwapChain> _swap_chain{};
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> _render_target_view{};

	friend class DeviceContext;
};

} // namespace dx3d
