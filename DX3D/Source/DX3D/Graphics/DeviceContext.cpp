#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/SwapChain.h>
#include <DX3D/Graphics/GraphicsPipelineState.h>

dx3d::DeviceContext::DeviceContext(const GraphicsResourceDesc& gr_desc) : GraphicsResource(gr_desc) {

	DX3DGraphicsLogThrowOnFail(
		_device.CreateDeferredContext(0, &_context),
		"Failed to create Deferred Context"
	);
}

void dx3d::DeviceContext::ClearAndSetBackBuffer(const SwapChain& swap_chain, const Vec4& color) {

	const f32 fcolor[] = { color.x, color.y, color.z, color.w };
	auto render_target_view = swap_chain._render_target_view.Get();

	_context->ClearRenderTargetView(render_target_view, fcolor);
	_context->OMSetRenderTargets(1, &render_target_view, nullptr);
}

void dx3d::DeviceContext::SetGraphicsPipelineState(const GraphicsPipelineState& pipeline) {

	_context->VSSetShader(pipeline._vs.Get(), nullptr, 0);
	_context->PSSetShader(pipeline._ps.Get(), nullptr, 0);
}
