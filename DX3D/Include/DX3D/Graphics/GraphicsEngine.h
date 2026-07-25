#pragma once
#include "DX3D/Core/Base.h"

namespace dx3d{
	class GraphicsEngine final : public Base {
	public:
		explicit GraphicsEngine(const GraphicsEngineDesc& desc);
		virtual ~GraphicsEngine() override;

		RenderSystem& GetRenderSystem() const noexcept;
	private:
		std::shared_ptr<RenderSystem> _render_system{};
	};
} // namespace dx3d
