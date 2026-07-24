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
} // namespace dx3d
