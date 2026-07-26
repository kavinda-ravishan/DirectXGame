#include "DX3D/Graphics/SwapChain.h"

dx3d::SwapChain::SwapChain(const SwapChainDesc& desc, const GraphicsResourceDesc& g_desc) : GraphicsResource(g_desc) {

	DX3DLogInfo("Creating SwapChain...");

	DXGI_SWAP_CHAIN_DESC dxgi_desc {};

	dxgi_desc.BufferDesc.Width = std::max(1, desc.win_size.width);
	dxgi_desc.BufferDesc.Height = std::max(1, desc.win_size.height);
	dxgi_desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // RGBA each channel 8 bits and UNORM means normalized 0-1 in shader
	dxgi_desc.BufferCount = 2; // in windowed mode, 2 means 2 back buffers, 1 front buffer (front buffer handle by descktop window manager or DWM), NOTE : in fullscreen mode buffer count includes front buffer
	dxgi_desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // buffer will be used as render target

	dxgi_desc.OutputWindow = static_cast<HWND>(desc.win_handle);
	dxgi_desc.SampleDesc.Count = 1; // sample count for multisaple antialiasing, 1 means no multisampling
	dxgi_desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD; // flip model, discard previous frame, more efficient than traditional blit model
	dxgi_desc.Windowed = TRUE; // windowed mode

	DX3DGraphicsLogThrowOnFail(
		_factory.CreateSwapChain(&_device, &dxgi_desc, &_swap_chain),
		"Failed to create swap chain."
	);
}

dx3d::SwapChain::~SwapChain() {
	DX3DLogInfo("Destroying Swap Chain")
}
