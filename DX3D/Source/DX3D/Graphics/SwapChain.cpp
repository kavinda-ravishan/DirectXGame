#include "DX3D/Graphics/SwapChain.h"

dx3d::SwapChain::SwapChain(const SwapChainDesc& desc, const GraphicsResourceDesc& g_desc) : GraphicsResource(g_desc) {
	DXGI_SWAP_CHAIN_DESC dxgi_desc {};

	dxgi_desc.BufferDesc.Width = std::max(1, desc.win_size.width);
	dxgi_desc.BufferDesc.Height = std::max(1, desc.win_size.height);
	dxgi_desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // RGBA each channel 8 bits and UNORM means normalized 0-1 in shader
	dxgi_desc.BufferCount = 2; // in windowed mode, 2 means 2 back buffers, 1 front buffer (front buffer handle by descktop window manager or DWM), NOTE : in fullscreen mode buffer count includes front buffer
	dxgi_desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // buffer will be used as render target

	dxgi_desc.OutputWindow = static_cast<HWND>(desc.win_handle);
	dxgi_desc.SampleDesc.Count = 1; // sample count for multisample antialiasing, 1 means no multisampling
	dxgi_desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD; // flip model, discard previous frame, more efficient than traditional blit model
	dxgi_desc.Windowed = TRUE; // windowed mode

	DX3DGraphicsLogThrowOnFail(
		_factory.CreateSwapChain(&_device, &dxgi_desc, &_swap_chain),
		"Failed to create swap chain."
	);

	ReloadBuffers();
}

void dx3d::SwapChain::Present(bool vsync) {
	DX3DGraphicsLogThrowOnFail(
		_swap_chain->Present(vsync, 0),
		"Failed the Present call"
	);
}

void dx3d::SwapChain::ReloadBuffers() {

	Microsoft::WRL::ComPtr<ID3D11Texture2D> buffer{};
	DX3DGraphicsLogThrowOnFail(
		_swap_chain->GetBuffer(0, IID_PPV_ARGS(&buffer)),
		"Failed to get buffer from the swap chain."
	);

	DX3DGraphicsLogThrowOnFail(
		_device.CreateRenderTargetView(buffer.Get(), nullptr, &_render_target_view),
		"Failed to create render target view from buffer."
	);
}
