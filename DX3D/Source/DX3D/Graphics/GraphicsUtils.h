#pragma once
#include <d3d11.h>
#include <bit>
#include <DX3D/Core/Common.h>

namespace dx3d {

	namespace graphics_utils {
		inline const char* GetShaderModelTarget(const ShaderType type) {

			switch (type) {
			case ShaderType::VertexShader: return "vs_5_0"; // 5.0 vertex shader model (DX11 support shader models upto version 5.0)
			case ShaderType::PixelShader: return "ps_5_0"; // 5.0 pixel shader model
			default: return "";
			}
		}

		inline DXGI_FORMAT GetDXGIFormatFromMask(D3D_REGISTER_COMPONENT_TYPE type, UINT mask) {

			constexpr auto format_table_component_count = 4;

			const auto component_count = std::popcount(mask);
			if (component_count < 1) return DXGI_FORMAT_UNKNOWN;
			if (component_count > format_table_component_count) return DXGI_FORMAT_UNKNOWN;

			constexpr DXGI_FORMAT format_taable[1][format_table_component_count] = {
				{
					DXGI_FORMAT_R32_FLOAT,
					DXGI_FORMAT_R32G32_FLOAT,
					DXGI_FORMAT_R32G32B32_FLOAT,
					DXGI_FORMAT_R32G32B32A32_FLOAT,
				}
			};

			auto type_index = 0u;
			switch (type) {
			case D3D_REGISTER_COMPONENT_FLOAT32: type_index = 0u; break;
			default: return DXGI_FORMAT_UNKNOWN;
			}

			return format_taable[type_index][component_count - 1];
		}

	} // namespace graphics_utils

} // namespace dx3d
