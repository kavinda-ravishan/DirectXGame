#pragma once
#include "DX3D/Core/Common.h"

namespace dx3d {

	class Base {
	public:
		explicit Base(const BaseDesc& desc);
		virtual ~Base();

		virtual Logger& GetLogger() noexcept final;

	protected:
		Base(const Base&) = delete; // delete copy constructor
		Base(Base&&) = delete; // delete move constructor
		Base& operator=(const Base&) = delete; // delete copy assignment operator
		Base& operator=(Base&&) = delete; // delete move assignment operator

	protected:
		Logger& _logger;
	};

} // namespace dx3d

#define DX3DLogInfo(message) {\
	DX3DLog(GetLogger(), Logger::LogLevel::Info, message);\
}

#define DX3DLogWarning(message) {\
	DX3DLog(GetLogger(), Logger::LogLevel::Warning, message);\
}

#define DX3DLogError(message) {\
	DX3DLog(GetLogger(), Logger::LogLevel::Error, message);\
}

#define DX3DLogThrowError(message) {\
	DX3DLogThrow(GetLogger(), std::runtime_error, Logger::LogLevel::Error, message);\
}

#define DX3DLogThrowInvalidArg(message) {\
	DX3DLogThrow(GetLogger(), std::invalid_argument, Logger::LogLevel::Error, message);\
}
