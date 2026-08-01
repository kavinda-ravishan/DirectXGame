#pragma once
#include <DX3D/Core/Base.h>
#include <DX3D/Math/Vec3.h>
#include <DX3D/Math/Vec4.h>

namespace dx3d{
	class GraphicsEngine final : public Base {
	public:
		explicit GraphicsEngine(const GraphicsEngineDesc& desc);
		virtual ~GraphicsEngine() override;

		GraphicsDevice& GetGraphicsDevice() noexcept;

		void Render(SwapChain& swap_chain);
	private:
		struct Vertex {
			Vec3 position;
			Vec4 color;
		};

	private:
		std::shared_ptr<GraphicsDevice> _graphics_device{};
		DeviceContextPtr _device_context{};
		GraphicsPipelineStatePtr _pipeline{};
		VertexBufferPtr _vb{};
	};
} // namespace dx3d
