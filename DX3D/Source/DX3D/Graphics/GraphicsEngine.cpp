#include "DX3D/Graphics/GraphicsEngine.h"
#include "DX3D/Graphics/GraphicsDevice.h"

using namespace dx3d;

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base) {
	DX3DLogInfo("Initializing Graphics Engine");

	_graphics_device = std::make_shared<GraphicsDevice>(GraphicsDeviceDesc({_logger}));
}

dx3d::GraphicsEngine::~GraphicsEngine() {
	DX3DLogInfo("Destroying Graphics Engine");
}

GraphicsDevice& dx3d::GraphicsEngine::GetGraphicsDevice() const noexcept {

	return *_graphics_device;
}
