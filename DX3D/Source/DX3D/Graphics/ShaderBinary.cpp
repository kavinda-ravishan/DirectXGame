#include <d3dcompiler.h>
#include <string>
#include <DX3D/Graphics/ShaderBinary.h>
#include <DX3D/Graphics/GraphicsUtils.h>

dx3d::ShaderBinary::ShaderBinary(const ShaderCompileDesc& desc, const GraphicsResourceDesc& g_desc) : GraphicsResource(g_desc) {

	DX3DLogInfo(("Compiling " + std::string(desc.shader_entry_ponit) + " shader entry ponit code").c_str());

	if (!desc.shader_source_name) DX3DLogThrowInvalidArg("No shader source name provided");
	if (!desc.shader_source_code) DX3DLogThrowInvalidArg("No shader source code provided");
	if (!desc.shader_source_code_size) DX3DLogThrowInvalidArg("No shader code size provided");
	if (!desc.shader_entry_ponit) DX3DLogThrowInvalidArg("No shader entry point provided");

	UINT compile_flags{};

#ifdef _DEBUG
	compile_flags |= D3DCOMPILE_DEBUG;
#endif // _DEBUG

	Microsoft::WRL::ComPtr<ID3DBlob> error_blob{};

	DX3DGraphicsCheckShaderCompile(
		D3DCompile(
			desc.shader_source_code,
			desc.shader_source_code_size,
			desc.shader_source_name,
			nullptr,
			nullptr,
			desc.shader_entry_ponit,
			dx3d::graphics_utils::GetShaderModelTarget(desc.shader_type),
			compile_flags,
			0,
			&_blob,
			&error_blob
		),
		error_blob.Get()
	);
}
