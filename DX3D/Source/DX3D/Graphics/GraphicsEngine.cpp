#include "DX3D/Graphics/GraphicsEngine.h"
#include "DX3D/Graphics/RenderSystem.h"

dx3d::GraphicsEngine::GraphicsEngine() {
	_render_system = std::make_unique<RenderSystem>();
}

dx3d::GraphicsEngine::~GraphicsEngine() {}
