#pragma once

#ifdef SHARD_PLATFORM_LINUX
#ifdef SHARD_BUILD_DLL
#define SHARD_API __attribute__((visibility("default")))
#else
#define SHARD_API
#endif
#else
#error Shard only supports Linux!
#endif

#ifdef SHARD_ENABLE_ASSERTS
#define SHARD_ASSERT(x, ...)                                   \
    {                                                          \
        if (!(x))                                              \
        {                                                      \
            SHARD_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            __builtin_trap();                                  \
        }                                                      \
    }
#define SHARD_CORE_ASSERT(x, ...)                                   \
    {                                                               \
        if (!(x))                                                   \
        {                                                           \
            SHARD_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            __builtin_trap();                                       \
        }                                                           \
    }
#else
#define SHARD_ASSERT(x, ...)
#define SHARD_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define SHARD_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)