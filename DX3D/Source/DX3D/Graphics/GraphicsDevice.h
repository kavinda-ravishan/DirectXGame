#pragma once
#include <wrl.h>
#include <d3d11.h>
#include <DX3D/Core/Base.h>
#include <DX3D/Graphics/GraphicsResource.h>

namespace dx3d {
	class GraphicsDevice final : public Base, public std::enable_shared_from_this<GraphicsDevice> {
	public:
		explicit GraphicsDevice(const GraphicsDeviceDesc& desc);
		virtual ~GraphicsDevice() override;

		SwapChainPtr CreateSwapChain(const SwapChainDesc& desc) const;
		DeviceContextPtr CreateDeviceContext();
		ShaderBinaryPtr CompileShader(const ShaderCompileDesc& desc);
		GraphicsPipelineStatePtr CreateGraphicsPipelineState(const GraphicsPipelineStateDesc& desc);

		void ExecuteCommandList(DeviceContext& context);
	private:
		GraphicsResourceDesc GetGraphicsResourceDesc() const noexcept;

	private:
		/**
			* ID3D11Device - High-level rendering device (Direct3D)
			*      |
			*      \/
			* IDXGIDevice - Graphics device bound to a GPU
			*      |
			*     \/
			* IDXGIAdapter - Represents the GPU
			*      |
			*     \/
			* IDXGIFactory - Manages adapters and creates swap chains
			* 
		**/
		Microsoft::WRL::ComPtr<ID3D11Device> _d3d_device{};
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> _d3d_context{};
		Microsoft::WRL::ComPtr<IDXGIDevice> _dxgi_device{};
		Microsoft::WRL::ComPtr<IDXGIAdapter> _dxgi_adapter{};
		Microsoft::WRL::ComPtr<IDXGIFactory> _dxgi_factory{};
	};
} // namespace dx3d
