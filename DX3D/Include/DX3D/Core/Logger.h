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

		~Logger();

		void Log(LogLevel level, const char* message) const;

	protected:
		Logger(const Logger&) = delete; // delete copy constructor
		Logger(Logger&&) = delete; // delete move constructor
		Logger& operator=(const Logger&) = delete; // delete copy assignment operator
		Logger& operator=(Logger&&) = delete; // delete move assignment operator

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
