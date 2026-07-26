#pragma once
#include "DX3D/Core/Base.h"

namespace dx3d{
	class GraphicsEngine final : public Base {
	public:
		explicit GraphicsEngine(const GraphicsEngineDesc& desc);
		virtual ~GraphicsEngine() override;

		GraphicsDevice& GetGraphicsDevice() const noexcept;
	private:
		std::shared_ptr<GraphicsDevice> _graphics_device{};
	};
} // namespace dx3d
