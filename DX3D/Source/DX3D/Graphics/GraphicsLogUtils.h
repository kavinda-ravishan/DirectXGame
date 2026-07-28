#pragma once
#include <d3d11.h>
#include <DX3D/Core/Core.h>
#include <DX3D/Core/Logger.h>

namespace dx3d {

	namespace graphics_log_utils {

		inline void CheckShaderCompile(Logger& logger, const HRESULT hr, ID3DBlob* error_blob, const char* file, const int line) {
			
			auto error_msg = error_blob ? static_cast<const char*>(error_blob->GetBufferPointer()) : nullptr;
			
			if (FAILED(hr)) {
				if (error_msg) {
					DX3DLogThrowUtil(logger, std::runtime_error, Logger::LogLevel::Error, error_msg, file, line);
				}
				else {
					DX3DLogThrowUtil(logger, std::runtime_error, Logger::LogLevel::Error, "Shader compilation failed", file, line);
				}
			}

			if (error_msg) {
				DX3DLogUtil(logger, Logger::LogLevel::Warning, error_msg, file, line);
			}
		}
	} // namespace graphics_log_utils

} // namespace dx3d

#define DX3DGraphicsLogThrowOnFailUtil(hr, message, file, line) {\
	auto res = (hr);\
	if (FAILED(res)) {\
		DX3DLogThrowErrorUtil(message, file, line);\
	}\
}

#define DX3DGraphicsLogThrowOnFail(hr, message)\
	DX3DGraphicsLogThrowOnFailUtil(hr, message, __FILE__, __LINE__)

#define DX3DGraphicsCheckShaderCompileUtil(hr, error_blob, file, line) {\
	auto res = (hr);\
	dx3d::graphics_log_utils::CheckShaderCompile(GetLogger(), res, error_blob, file, line);\
}

#define DX3DGraphicsCheckShaderCompile(hr, error_blob)\
	DX3DGraphicsCheckShaderCompileUtil(hr, error_blob, __FILE__, __LINE__)
