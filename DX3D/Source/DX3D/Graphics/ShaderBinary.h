#pragma once
#include <DX3D/Graphics/GraphicsResource.h>

namespace dx3d {

	class ShaderBinary final : public GraphicsResource {

	public:
		ShaderBinary(const ShaderCompileDesc& desc, const GraphicsResourceDesc& g_desc);

	private:
		Microsoft::WRL::ComPtr<ID3DBlob> _blob;
	};

} // namespace dx3d
