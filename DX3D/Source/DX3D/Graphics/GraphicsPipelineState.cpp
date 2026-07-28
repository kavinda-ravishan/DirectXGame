#include <DX3D/Graphics/GraphicsPipelineState.h>
#include <DX3D/Graphics/ShaderBinary.h>

dx3d::GraphicsPipelineState::GraphicsPipelineState(const GraphicsPipelineStateDesc& desc, const GraphicsResourceDesc& g_desc) : GraphicsResource(g_desc) {

	DX3DLogInfo("Compiling the vertex shader and pixel shader binaries");

	if (desc.vs.GetType() != ShaderType::VertexShader) {
		DX3DLogThrowInvalidArg("The 'vs' member is not a valid vertex shader binary");
	}

	if (desc.ps.GetType() != ShaderType::PixelShader) {
		DX3DLogThrowInvalidArg("The 'ps' member is not a valid pixel shader binary");
	}

	const auto vs = desc.vs.GetData();
	const auto ps = desc.ps.GetData();

	// NOTE : can be automatically genarate from future call reflection
	// input layout must match the structure defined in the vertex shader code
	constexpr D3D11_INPUT_ELEMENT_DESC elements[] = {
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0}
	};

	DX3DGraphicsLogThrowOnFail(
		_device.CreateInputLayout(elements, std::size(elements), vs.data, vs.data_size, &_layout),
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
