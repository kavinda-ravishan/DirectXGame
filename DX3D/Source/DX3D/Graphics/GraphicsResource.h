#pragma once
#include <wrl.h>
#include <d3d11.h>
#include "DX3D/Core/Base.h"
#include "DX3D/Graphics/GraphicsLogUtils.h"

namespace dx3d {
	struct GraphicsResourceDesc {
		BaseDesc base;
		std::shared_ptr<const RenderSystem> render_system;
		ID3D11Device& device;
		IDXGIFactory& factory;
	};

	class GraphicsResource : public Base {
	public:
		explicit GraphicsResource(const GraphicsResourceDesc& desc) : 
			Base(desc.base), _render_system(desc.render_system), _device(desc.device), _factory(desc.factory) { }
	protected:
		std::shared_ptr<const RenderSystem> _render_system;
		ID3D11Device& _device;
		IDXGIFactory& _factory;
	};
} // namespace dx3d
