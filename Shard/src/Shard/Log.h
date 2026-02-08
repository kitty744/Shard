#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <memory>

namespace Shard
{

    class SHARD_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

}

// Core log macros
#define SHARD_CORE_TRACE(...) ::Shard::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SHARD_CORE_INFO(...) ::Shard::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SHARD_CORE_WARN(...) ::Shard::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SHARD_CORE_ERROR(...) ::Shard::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SHARD_CORE_CRITICAL(...) ::Shard::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define SHARD_TRACE(...) ::Shard::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SHARD_INFO(...) ::Shard::Log::GetClientLogger()->info(__VA_ARGS__)
#define SHARD_WARN(...) ::Shard::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SHARD_ERROR(...) ::Shard::Log::GetClientLogger()->error(__VA_ARGS__)
#define SHARD_CRITICAL(...) ::Shard::Log::GetClientLogger()->critical(__VA_ARGS__)