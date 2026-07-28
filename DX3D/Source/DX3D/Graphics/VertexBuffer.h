#pragma once

#include <wrl.h>
#include <DX3D/Graphics/GraphicsResource.h>

namespace dx3d {

	class VertexBuffer final : public GraphicsResource {
	public:
		VertexBuffer(const VertexBufferDesc& desc, const GraphicsResourceDesc& g_desc);
		ui32 GetVertexListSize() const noexcept;

	private:
		const ui32 _vertex_size{};
		const ui32 _vertex_list_size{};
		Microsoft::WRL::ComPtr<ID3D11Buffer> _buffer{};

		friend class DeviceContext;
	};

} // namespace dx3d
