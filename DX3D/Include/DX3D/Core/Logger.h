#pragma once

namespace dx3d {
	class Logger final {
	public:
		enum class LogLevel {
			Error = 0,
			Warning,
			Info,
		};

		explicit Logger(LogLevel log_level = LogLevel::Error);

		void Log(LogLevel level, const char* message) const;

	private:
		const LogLevel _log_level{ LogLevel::Error };
	};

#define DX3DLogInfo(message) {\
	GetLogger().Log((Logger::LogLevel::Info), message);\
	}

#define DX3DLogWarning(message) {\
	GetLogger().Log((Logger::LogLevel::Warning), message);\
	}

#define DX3DLogError(message) {\
	GetLogger().Log((Logger::LogLevel::Error), message);\
	}

#define DX3DLogErrorAndThrow(message) {\
	DX3DLogError(message);\
	throw std::runtime_error(message);\
	}

} // namespace dx3d
