#pragma once
#include <d3dcompiler.h>
#include <DX3D/Graphics/GraphicsResource.h>

namespace dx3d {

	class VertexShaderSignature final : public GraphicsResource {
	public:
		VertexShaderSignature(const VertexShaderSignatureDesc& desc, const GraphicsResourceDesc& g_desc);
		BinaryData GetShaderBinaryData() const noexcept;
		BinaryData GetInputElementsData() const noexcept;
	private:
		ShaderBinaryPtr _vs_binary{};
		Microsoft::WRL::ComPtr<ID3D11ShaderReflection> _shader_reflection{};
		D3D11_INPUT_ELEMENT_DESC _elements[D3D11_STANDARD_PIXEL_ELEMENT_COUNT]{};
		ui32 _num_elements{};
	};

}; // namespace dx3d
