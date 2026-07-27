#pragma once
#include <d3d11.h>
#include "DX3D/Core/Core.h"
#include "DX3D/Core/Logger.h"

namespace dx3d {

	namespace graphics_log_utils {

		inline void CheckShaderCompile(Logger& logger, const HRESULT hr, ID3DBlob* error_blob) {
			
			auto error_msg = error_blob ? static_cast<const char*>(error_blob->GetBufferPointer()) : nullptr;
			
			if (FAILED(hr)) {
				if (error_msg) {
					DX3DLogThrow(logger, std::runtime_error, Logger::LogLevel::Error, error_msg);
				}
				else {
					DX3DLogThrow(logger, std::runtime_error, Logger::LogLevel::Error, "Shader compilation failed");
				}
			}

			if (error_msg) {
				DX3DLog(logger, Logger::LogLevel::Warning, error_msg);
			}
		}
	} // namespace graphics_log_utils

} // namespace dx3d

#define DX3DGraphicsLogThrowOnFail(hr, message) {\
	auto res = (hr);\
	if (FAILED(res)) {\
		DX3DLogThrowError(message);\
	}\
}

#define DX3DGraphicsCheckShaderCompile(hr, error_blob) {\
	auto res = (hr);\
	dx3d::graphics_log_utils::CheckShaderCompile(GetLogger(), res, error_blob);\
}
