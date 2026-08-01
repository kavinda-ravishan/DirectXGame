#include <string>
#include <fstream>
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

	constexpr char shader_file_path[] = "DX3D/Assets/Shaders/Basic.hlsl";
	std::ifstream shader_stream(shader_file_path);

	if (!shader_stream) DX3DLogThrowError("Failed to open the shader file");
	const std::string shader_file_data{
		std::istreambuf_iterator<char>(shader_stream),
		std::istreambuf_iterator<char>(),
	};

	// HLSL shader code
	const auto shader_source_code = shader_file_data.c_str();
	const auto shader_source_code_size = shader_file_data.length();

	auto vs = device.CompileShader({ shader_file_path, shader_source_code, shader_source_code_size, "VSMain", ShaderType::VertexShader });
	auto ps = device.CompileShader({ shader_file_path, shader_source_code, shader_source_code_size, "PSMain", ShaderType::PixelShader });

	auto vs_sig = device.CreateVertexShaderSignature({ vs });

	_pipeline = device.CreateGraphicsPipelineState({ *vs_sig, *ps });

	const Vertex vertex_list[] = {
		{{-0.5f, -0.5f, 0.0f}, {1,0,0,1}},
		{{-0.5f, 0.5f, 0.0f}, {0,1,0,1}},
		{{0.5f, 0.5f, 0.0f}, {0,0,1,1}},
		{{0.5f, 0.5f, 0.0f}, {0,0,1,1}},
		{{0.5f, -0.5f, 0.0f}, {1,0,1,1}},
		{{-0.5f, -0.5f, 0.0f}, {1,0,0,1}}
	};

	_vb = device.CreateVertexBuffer({ vertex_list, std::size(vertex_list), sizeof(Vertex) });
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
	context.ClearAndSetBackBuffer(swap_chain, { 0.27f /*RED*/, 0.39f /*GREEN*/, 0.55f /*BLUE*/, 1/*ALPHA*/ });
	context.SetGraphicsPipelineState(*_pipeline);

	context.SetViewportSize(swap_chain.GetSize());

	auto& vb = *_vb;
	context.SetVertexBuffer(vb);
	context.DrawTriangleList(vb.GetVertexListSize(), 0u);
	
	auto& device = *_graphics_device;
	device.ExecuteCommandList(context);

	swap_chain.Present();
}
