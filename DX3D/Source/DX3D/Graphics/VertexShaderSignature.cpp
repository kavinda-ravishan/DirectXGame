#include <ranges>
#include <d3dcompiler.h>
#include <DX3D/Graphics/ShaderBinary.h>
#include <DX3D/Graphics/VertexShaderSignature.h>
#include <DX3D/Graphics/GraphicsUtils.h>

dx3d::VertexShaderSignature::VertexShaderSignature(const VertexShaderSignatureDesc& desc, const GraphicsResourceDesc& g_desc) 
	: GraphicsResource(g_desc), _vs_binary(desc.vs_binary) {

	if (!desc.vs_binary) DX3DLogThrowInvalidArg("No shader binary provided");
	if (desc.vs_binary->GetType() != ShaderType::VertexShader)
		DX3DLogThrowInvalidArg("The 'vs_binary' member is not a valid vertex shader binary");

	auto vs_data = _vs_binary->GetData();

	DX3DGraphicsLogThrowOnFail(
		D3DReflect(
			vs_data.data,
			vs_data.data_size,
			IID_PPV_ARGS(&_shader_reflection)
		),
		"Failed to get metadata from vs data with reflect"
	);

	D3D11_SHADER_DESC shader_desc;
	DX3DGraphicsLogThrowOnFail(
		_shader_reflection->GetDesc(&shader_desc),
		"Faild to get descriptor from vs shader reflection"
	);

	_num_elements = shader_desc.InputParameters;
	D3D11_SIGNATURE_PARAMETER_DESC params[D3D11_STANDARD_PIXEL_ELEMENT_COUNT]{};

	for (auto i : std::views::iota(0u, _num_elements)) {
		DX3DGraphicsLogThrowOnFail(
			_shader_reflection->GetInputParameterDesc(i, &params[i]),
			"Faild to get input parameters from vs shader reflection"
		);
	}

	// NOTE : can be automatically genarate from future call reflection
	// input layout must match the structure defined in the vertex shader code
	// float3 position : POSITION0;
	// float4 color : COLOR0;
	// constexpr D3D11_INPUT_ELEMENT_DESC elements[] = {
	//   {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
	//	 {"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0}
	// };
	for (auto i : std::views::iota(0u, _num_elements)) {
		const auto& param = params[i];
		_elements[i] = {
			param.SemanticName,
			param.SemanticIndex,
			graphics_utils::GetDXGIFormatFromMask(
				param.ComponentType, param.Mask
			),
			0,
			D3D11_APPEND_ALIGNED_ELEMENT,
			D3D11_INPUT_PER_VERTEX_DATA,
			0
		};
	}
}

dx3d::BinaryData dx3d::VertexShaderSignature::GetShaderBinaryData() const noexcept {
	return _vs_binary->GetData();
}

dx3d::BinaryData dx3d::VertexShaderSignature::GetInputElementsData() const noexcept
{
	return {
		_elements,
		_num_elements
	};
}
