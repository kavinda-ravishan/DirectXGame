#include "DX3D/Graphics/GraphicsEngine.h"
#include "DX3D/Graphics/RenderSystem.h"

using namespace dx3d;

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base) {
	DX3DLogInfo("Initializing Graphics Engine");

	_render_system = std::make_shared<RenderSystem>(RenderSystemDesc({_logger}));
}

dx3d::GraphicsEngine::~GraphicsEngine() {
	DX3DLogInfo("Destroying Graphics Engine");
}

RenderSystem& dx3d::GraphicsEngine::GetRenderSystem() const noexcept {

	return *_render_system;
}
