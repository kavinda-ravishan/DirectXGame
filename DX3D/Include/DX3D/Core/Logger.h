#pragma once

namespace dx3d {
	class Logger final {
	public:
		enum class LogLevel {
			Error = 0,
			Warning,
			Info,
		};

		explicit Logger(LogLevel level = LogLevel::Error);

		~Logger();

		void Log(LogLevel level, const char* message, const char* file, const int line);

	protected:
		Logger(const Logger&) = delete; // delete copy constructor
		Logger(Logger&&) = delete; // delete move constructor
		Logger& operator=(const Logger&) = delete; // delete copy assignment operator
		Logger& operator=(Logger&&) = delete; // delete move assignment operator

	private:
		const LogLevel _level{ LogLevel::Error };
	};

} // namespace dx3d

#define DX3DLog(logger, type, message)\
	logger.Log((type), message, __FILE__, __LINE__)

#define DX3DLogThrow(logger, exception, type, message)\
{\
	DX3DLog(logger, type, message);\
	throw exception(message);\
}
