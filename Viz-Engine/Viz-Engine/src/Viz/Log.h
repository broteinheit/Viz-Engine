#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Viz {
	class VIZ_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define VIZ_CORE_ERROR(...) ::Viz::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VIZ_CORE_WARN(...)  ::Viz::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VIZ_CORE_INFO(...)  ::Viz::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VIZ_CORE_TRACE(...) ::Viz::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VIZ_CORE_FATAL(...) ::Viz::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define VIZ_ERROR(...) ::Viz::Log::GetClientLogger()->error(__VA_ARGS__)
#define VIZ_WARN(...)  ::Viz::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VIZ_INFO(...)  ::Viz::Log::GetClientLogger()->info(__VA_ARGS__)
#define VIZ_TRACE(...) ::Viz::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VIZ_FATAL(...) ::Viz::Log::GetClientLogger()->fatal(__VA_ARGS__)