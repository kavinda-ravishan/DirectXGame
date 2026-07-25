#include "DX3D/Graphics/RenderSystem.h"
#include "DX3D/Graphics/GraphicsLogUtils.h"

dx3d::RenderSystem::RenderSystem(const RenderSystemDesc& desc) : Base(desc.base) {
	DX3DLogInfo("Initializing Render System");

	D3D_FEATURE_LEVEL feature_level{};
	UINT create_device_flags{};

#ifdef _DEBUG
	create_device_flags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // _DEBUG

	DX3DGraphicsLogErrorAndThrow(
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

}

dx3d::RenderSystem::~RenderSystem() {
	DX3DLogInfo("Destroying Render System");
}
