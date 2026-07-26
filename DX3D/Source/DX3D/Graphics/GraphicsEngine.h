#pragma once
#include "DX3D/Core/Base.h"

namespace dx3d{
	class GraphicsEngine final : public Base {
	public:
		explicit GraphicsEngine(const GraphicsEngineDesc& desc);
		virtual ~GraphicsEngine() override;

		GraphicsDevice& GetGraphicsDevice() noexcept;

		void Render(SwapChain& swap_chain);
	private:
		std::shared_ptr<GraphicsDevice> _graphics_device{};
		DeviceContextPtr _device_context{};
	};
} // namespace dx3d
