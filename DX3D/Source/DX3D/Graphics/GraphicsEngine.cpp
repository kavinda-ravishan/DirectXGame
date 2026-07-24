#include "DX3D/Graphics/GraphicsEngine.h"
#include "DX3D/Graphics/RenderSystem.h"

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base) {
	GetLogger().Log(Logger::LogLevel::Info, "Initializing Graphics Engine");

	_render_system = std::make_unique<RenderSystem>(RenderSystemDesc({_logger}));
}

dx3d::GraphicsEngine::~GraphicsEngine() {
	GetLogger().Log(Logger::LogLevel::Info, "Destroying Graphics Engine");
}
