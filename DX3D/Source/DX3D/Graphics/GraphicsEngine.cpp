#include <DX3D/Math/Vec3.h>
#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Graphics/GraphicsDevice.h>
#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/SwapChain.h>
#include <DX3D/Graphics/VertexBuffer.h>

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base) {
	DX3DLogInfo("Initializing Graphics Engine");

	_graphics_device = std::make_shared<GraphicsDevice>(GraphicsDeviceDesc({_logger}));

	auto& device = *_graphics_device;
	_device_context = device.CreateDeviceContext();

	// HLSL shader code
	constexpr char shader_source_code[] =
		R"(
float4 VSMain(float3 pos: POSITION): SV_Position {
	return float4(pos.xyz, 1.0);
}
float4 PSMain(): SV_Target {
	return float4(1.0, 1.0, 1.0, 1.0);
}
)";

	constexpr char shader_source_name[] = "Basic";
	constexpr auto shader_source_code_size = std::size(shader_source_code);

	auto vs = device.CompileShader({ shader_source_name, shader_source_code, shader_source_code_size, "VSMain", ShaderType::VertexShader });
	auto ps = device.CompileShader({ shader_source_name, shader_source_code, shader_source_code_size, "PSMain", ShaderType::PixelShader });

	_pipeline = device.CreateGraphicsPipelineState({ *vs, *ps });

	const dx3d::Vec3 vertex_list[] = {
		{-0.5f, -0.5f, 0.0f},
		{0.0f, 0.5f, 0.0f},
		{0.5f, -0.5f, 0.0f}
	};

	_vb = device.CreateVertexBuffer({ vertex_list, std::size(vertex_list), sizeof(Vec3) });
}

dx3d::GraphicsEngine::~GraphicsEngine() {
	DX3DLogInfo("Destroying Graphics Engine");
}

dx3d::GraphicsDevice& dx3d::GraphicsEngine::GetGraphicsDevice() noexcept {
	return *_graphics_device;
}

void dx3d::GraphicsEngine::Render(SwapChain& swap_chain) {

	auto& context = *_device_context;
	// record commands to device context (draw RED)
	context.ClearAndSetBackBuffer(swap_chain, { 1 /*RED*/, 0 /*GREEN*/, 0 /*BLUE*/, 1/*ALPHA*/ });
	context.SetGraphicsPipelineState(*_pipeline);

	context.SetViewportSize(swap_chain.GetSize());

	auto& vb = *_vb;
	context.SetVertexBuffer(vb);
	context.DrawTriangleList(vb.GetVertexListSize(), 0u);
	
	auto& device = *_graphics_device;
	device.ExecuteCommandList(context);

	swap_chain.Present();
}
