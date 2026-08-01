#pragma once
#include <DX3D/Graphics/GraphicsResource.h>

namespace dx3d {

	class ShaderBinary final : public GraphicsResource {

	public:
		ShaderBinary(const ShaderCompileDesc& desc, const GraphicsResourceDesc& g_desc);
		BinaryData GetData() const noexcept;
		ShaderType GetType() const noexcept;
	private:
		Microsoft::WRL::ComPtr<ID3DBlob> _blob;
		const ShaderType _type;
	};

} // namespace dx3d
