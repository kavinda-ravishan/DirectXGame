#include <DX3D/Graphics/GraphicsPipelineState.h>
#include <DX3D/Graphics/ShaderBinary.h>
#include <DX3D/Graphics/VertexShaderSignature.h>

dx3d::GraphicsPipelineState::GraphicsPipelineState(const GraphicsPipelineStateDesc& desc, const GraphicsResourceDesc& g_desc) : GraphicsResource(g_desc) {

	DX3DLogInfo("Compiling the vertex shader and pixel shader binaries");

	if (desc.ps.GetType() != ShaderType::PixelShader) {
		DX3DLogThrowInvalidArg("The 'ps' member is not a valid pixel shader binary");
	}

	const auto vs = desc.vs.GetShaderBinaryData();
	const auto ps = desc.ps.GetData();
	auto vs_input_elements = desc.vs.GetInputElementsData();

	DX3DGraphicsLogThrowOnFail(
		_device.CreateInputLayout(
			static_cast<const D3D11_INPUT_ELEMENT_DESC*>(vs_input_elements.data), 
			static_cast<ui32>(vs_input_elements.data_size), 
			vs.data, 
			vs.data_size, 
			&_layout
		),
		"Failed to create input layout"
	);

	DX3DGraphicsLogThrowOnFail(
		_device.CreateVertexShader(vs.data, vs.data_size, nullptr, &_vs), 
		"Failed to create vertex shader"
	);

	DX3DGraphicsLogThrowOnFail(
		_device.CreatePixelShader(ps.data, ps.data_size, nullptr, &_ps), 
		"Failed to create pixel shader"
	);
}
