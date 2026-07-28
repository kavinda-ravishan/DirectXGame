#pragma once
#include <DX3D/Graphics/GraphicsResource.h>
#include <DX3D/Math/Vec4.h>

namespace dx3d {

	class DeviceContext final : public GraphicsResource {
	public:
		explicit DeviceContext(const GraphicsResourceDesc& gr_desc);
		void ClearAndSetBackBuffer(const SwapChain& swap_chain, const Vec4& color);
		void SetGraphicsPipelineState(const GraphicsPipelineState& pipeline);
		void SetVertexBuffer(const VertexBuffer& buffer);
		void SetViewportSize(const Rect& size);
		void DrawTriangleList(const ui32 vertex_count, const ui32 start_vertex_location);
	
	private:
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> _context;

		friend class GraphicsDevice;
	};

} // namespace dx3d
