#pragma once
#include <wrl.h>
#include <d3d11.h>
#include "DX3D/Core/Core.h"
#include "DX3D/Core/Base.h"

namespace dx3d {
	class RenderSystem final : public Base {
	public:
		RenderSystem();
		virtual ~RenderSystem() override;
	private:
		Microsoft::WRL::ComPtr<ID3D11Device> _d3d_device{};
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> _d3d_context{};
	};
} // namespace dx3d
