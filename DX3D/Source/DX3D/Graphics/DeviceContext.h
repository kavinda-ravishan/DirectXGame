#pragma once
#include <DX3D/Graphics/GraphicsResource.h>
#include <DX3D/Math/Vec4.h>

namespace dx3d {

	class DeviceContext final : public GraphicsResource {
	public:
		explicit DeviceContext(const GraphicsResourceDesc& gr_desc);
		void ClearAndSetBackBuffer(const SwapChain& swap_chain, const Vec4& color);
	
	private:
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> _context;

		friend class GraphicsDevice;
	};

} // namespace dx3d
