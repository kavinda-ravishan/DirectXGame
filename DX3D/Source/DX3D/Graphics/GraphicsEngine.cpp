#include "DX3D/Graphics/GraphicsEngine.h"
#include "DX3D/Graphics/GraphicsDevice.h"
#include "DX3D/Graphics/DeviceContext.h"
#include "DX3D/Graphics/SwapChain.h"

using namespace dx3d;

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base) {
	DX3DLogInfo("Initializing Graphics Engine");

	_graphics_device = std::make_shared<GraphicsDevice>(GraphicsDeviceDesc({_logger}));

	auto& device = *_graphics_device;
	_device_context = device.CreateDeviceContext();
}

dx3d::GraphicsEngine::~GraphicsEngine() {
	DX3DLogInfo("Destroying Graphics Engine");
}

GraphicsDevice& dx3d::GraphicsEngine::GetGraphicsDevice() noexcept {

	return *_graphics_device;
}

void dx3d::GraphicsEngine::Render(SwapChain& swap_chain) {

	auto& context = *_device_context;

	// record commands to device context (draw RED)
	context.ClearAndSetBackBuffer(swap_chain, { 1 /*RED*/, 0 /*GREEN*/, 0 /*BLUE*/, 1/*ALPHA*/ });

	auto& device = *_graphics_device;
	device.ExecuteCommandList(context);

	swap_chain.Present();
}
