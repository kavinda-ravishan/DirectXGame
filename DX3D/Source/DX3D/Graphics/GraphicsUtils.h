#pragma once
#include "DX3D/Core/Common.h"

namespace dx3d {

	namespace graphics_utils {
		inline const char* GetShaderModelTarget(const ShaderType type) {

			switch (type) {
			case ShaderType::VertexShader: return "vs_5_0"; // 5.0 vertex shader model (DX11 support shader models upto version 5.0)
			case ShaderType::PixelShader: return "ps_5_0"; // 5.0 pixel shader model
			default: return "";
			}
		}
	} // namespace graphics_utils

} // namespace dx3d
