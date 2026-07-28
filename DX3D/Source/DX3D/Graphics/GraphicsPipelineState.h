#pragma once
#include <DX3D/Graphics/GraphicsResource.h>

namespace dx3d {

	class GraphicsPipelineState final : public GraphicsResource {
	public:
		GraphicsPipelineState(const GraphicsPipelineStateDesc& desc, const GraphicsResourceDesc& g_desc);

	private:
		Microsoft::WRL::ComPtr<ID3D11VertexShader> _vs;
		Microsoft::WRL::ComPtr<ID3D11PixelShader> _ps;
		Microsoft::WRL::ComPtr<ID3D11InputLayout> _layout{};

		friend class DeviceContext;
	};

} // namespace dx3d
