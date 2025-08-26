#include "leetcode_utils/leetcode_utils_logging.hpp"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#elif defined(__linux__) || defined(linux)
#include <sys/syscall.h>
#include <unistd.h>
#elif defined(__APPLE__)
#include <pthread.h>
#else
#error "Unsupport system"
#endif

#include <chrono>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <ctime>
#include <filesystem>
#include <format>
#include <iostream>
#include <mutex>

namespace {
leetcode_utils::LogLevel g_logLevel = leetcode_utils::LogLevel::INFO;
}

namespace leetcode_utils {

inline const char* logLevelToStr(LogLevel level)
{
    switch (level) {
        case LogLevel::DEBUG:
            return "DEBUG";
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARN:
            return "WARN";
        case LogLevel::ERR:
            return "ERROR";
        case LogLevel::FATAL:
            return "FATAL";
        default:
            return "UNKNOWN";
    }
}

size_t GetCurrentThreadIdInternal()
{
#if defined(_WIN32) || defined(_WIN64)
    return static_cast<size_t>(GetCurrentThreadId());
#elif defined(__linux__) || defined(linux)
    return static_cast<size_t>(syscall(SYS_gettid));
#elif defined(__APPLE__)
    uint64_t tid;
    pthread_threadid_np(nullptr, &tid);
    return static_cast<size_t>(tid);
#else
    return 0;
#endif
}

std::string TimeString()
{
    const std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm ltm{};
#if defined(_WIN32) || defined(_WIN64)
    // Windows 使用 localtime_s
    localtime_s(&ltm, &now);
#else
    // Linux/macOS 使用 localtime_r
    localtime_r(&now, &ltm);
#endif
    std::stringstream timeSs;

    timeSs << std::put_time(&ltm, "%Y-%m-%d %H:%M:%S");

    return timeSs.str();
}

std::string formatLog(LogLevel level, const char* file, int line, const char* func, const std::string& message)
{
    return std::format("[{}] [{}] [Tid: {:#x}] [{}:{}] [{}] {}",
                       TimeString(),
                       logLevelToStr(level),
                       GetCurrentThreadIdInternal(),
                       std::filesystem::path(file).filename().string(),
                       line,
                       func,
                       message);
}

void LogInternal(LogLevel level, const char* file, int line, const char* func, const std::string& message)
{
    if (level < g_logLevel) {
        return;
    }

    std::string logStr = formatLog(level, file, line, func, message);
    std::cout << logStr << std::endl;
}

void SetDebugLogLevel(LogLevel level)
{
    g_logLevel = level;
}
}  // namespace leetcode_utils
