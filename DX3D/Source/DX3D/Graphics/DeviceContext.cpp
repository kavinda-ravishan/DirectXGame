#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/SwapChain.h>
#include <DX3D/Graphics/GraphicsPipelineState.h>
#include <DX3D/Graphics/VertexBuffer.h>

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

	_context->IASetInputLayout(pipeline._layout.Get());
	_context->VSSetShader(pipeline._vs.Get(), nullptr, 0);
	_context->PSSetShader(pipeline._ps.Get(), nullptr, 0);
}

void dx3d::DeviceContext::SetVertexBuffer(const VertexBuffer& buffer) {

	auto stride = buffer._vertex_size;
	auto buf = buffer._buffer.Get();
	auto offset = 0u;

	_context->IASetVertexBuffers(0, 1, &buf, &stride, &offset);
}

void dx3d::DeviceContext::SetViewportSize(const Rect& size) {

	D3D11_VIEWPORT vp{};
	vp.Width = static_cast<f32>(size.width);
	vp.Height = static_cast<f32>(size.height);
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;

	_context->RSSetViewports(1, &vp);
}

void dx3d::DeviceContext::DrawTriangleList(const ui32 vertex_count, const ui32 start_vertex_location) {

	_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	_context->Draw(vertex_count, start_vertex_location);
}
