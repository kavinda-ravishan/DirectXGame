#include <DX3D/Graphics/GraphicsDevice.h>
#include <DX3D/Graphics/GraphicsLogUtils.h>
#include <DX3D/Graphics/SwapChain.h>
#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/ShaderBinary.h>
#include <DX3D/Graphics/GraphicsPipelineState.h>
#include <DX3D/Graphics/VertexBuffer.h>
#include <DX3D/Graphics/VertexShaderSignature.h>

dx3d::GraphicsDevice::GraphicsDevice(const GraphicsDeviceDesc& desc) : Base(desc.base) {
	DX3DLogInfo("Initializing Graphics Device");

	D3D_FEATURE_LEVEL feature_level{};
	UINT create_device_flags{};

#ifdef _DEBUG
	create_device_flags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // _DEBUG

	DX3DGraphicsLogThrowOnFail(
		D3D11CreateDevice(
			nullptr, // Use default adapter (GPU installed on the system)
			D3D_DRIVER_TYPE_HARDWARE, // Use hardware driver (Pick primary GPU)
			nullptr, // No software rasterizer
			create_device_flags, // Device creation flags (e.g., debug layer)
			nullptr, // Use default feature levels
			0, // Number of feature levels (size of previous array)
			D3D11_SDK_VERSION, // SDK version
			&_d3d_device, // Device pointer
			&feature_level, // Feature level pointer
			&_d3d_context // Device context pointer
	), "Failed to create D3D11 device and context");

	// Get pointer to DXGI device interface from D3D11 device
	DX3DGraphicsLogThrowOnFail(
		_d3d_device->QueryInterface(IID_PPV_ARGS(&_dxgi_device)), 
		"Failed to get DXGI device from D3D11 device"
	);

	DX3DGraphicsLogThrowOnFail(
		_dxgi_device->GetParent(IID_PPV_ARGS(&_dxgi_adapter)), 
		"Failed to get DXGI adapter from DXGI device"
	);

	DX3DGraphicsLogThrowOnFail(
		_dxgi_adapter->GetParent(IID_PPV_ARGS(&_dxgi_factory)),
		"Failed to get DXGI factory from DXGI adapter"
	);

}

dx3d::GraphicsDevice::~GraphicsDevice() {
	DX3DLogInfo("Destroying Graphics Device");
}

dx3d::SwapChainPtr dx3d::GraphicsDevice::CreateSwapChain(const SwapChainDesc& desc) const {
	return std::make_shared<SwapChain>(desc, GetGraphicsResourceDesc());
}

dx3d::DeviceContextPtr dx3d::GraphicsDevice::CreateDeviceContext() {
	return std::make_shared<DeviceContext>(GetGraphicsResourceDesc());
}

dx3d::ShaderBinaryPtr dx3d::GraphicsDevice::CompileShader(const ShaderCompileDesc& desc) {
	return std::make_shared<ShaderBinary>(desc, GetGraphicsResourceDesc());
}

dx3d::GraphicsPipelineStatePtr dx3d::GraphicsDevice::CreateGraphicsPipelineState(const GraphicsPipelineStateDesc& desc) {
	return std::make_shared<GraphicsPipelineState>(desc, GetGraphicsResourceDesc());
}

dx3d::VertexBufferPtr dx3d::GraphicsDevice::CreateVertexBuffer(const VertexBufferDesc& desc) {
	return std::make_shared<VertexBuffer>(desc, GetGraphicsResourceDesc());
}

dx3d::VertexShaderSignaturePtr dx3d::GraphicsDevice::CreateVertexShaderSignature(const VertexShaderSignatureDesc& desc) {
	return std::make_shared<VertexShaderSignature>(desc, GetGraphicsResourceDesc());
}

void dx3d::GraphicsDevice::ExecuteCommandList(DeviceContext& context) {

	Microsoft::WRL::ComPtr<ID3D11CommandList> command_list{};

	DX3DGraphicsLogThrowOnFail(
		context._context->FinishCommandList(false, &command_list),
		"Failed to get command list"
	);

	_d3d_context->ExecuteCommandList(command_list.Get(), false);
}

dx3d::GraphicsResourceDesc dx3d::GraphicsDevice::GetGraphicsResourceDesc() const noexcept {
	return { {_logger}, shared_from_this(), *_d3d_device.Get(), *_dxgi_factory.Get()};
}
