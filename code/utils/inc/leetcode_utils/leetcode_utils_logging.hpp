#pragma once
#ifndef LEETCODE_UTILS_LOGGING_HPP
#define LEETCODE_UTILS_LOGGING_HPP

#include <format>

namespace leetcode_utils {
enum class LogLevel {
    DEBUG,  ///< 调试信息（仅开发/测试环境使用，包含详细调试数据）
    INFO,   ///< 一般信息（正常运行时的流程性信息，如服务启动成功）
    WARN,   ///< 警告信息（不影响主流程但需关注的异常，如配置项缺失使用默认值）
    ERR,    ///< 错误信息（功能异常但不导致程序退出，如单次接口调用失败）
    FATAL   ///< 致命错误（导致程序无法继续运行的严重异常，如核心资源初始化失败）
};

void SetDebugLogLevel(LogLevel level);

void LogInternal(LogLevel level, const char* file, int line, const char* func, const std::string& message);

template <typename... Args>
void CommonDebugLog(LogLevel level, const char* file, int line, const char* func, std::format_string<Args...> fmt,
                    Args&&... args)
{
    LogInternal(level, file, line, func, std::format(fmt, std::forward<Args>(args)...));
}
}  // namespace leetcode_utils

#define DEBUG_LOG(level, fmt, ...)                                                                           \
    do {                                                                                                     \
        leetcode_utils::CommonDebugLog(level, __FILE__, __LINE__, __func__, fmt __VA_OPT__(, ) __VA_ARGS__); \
    } while (0)

#define DEBUG_LOG_DBG(fmt, ...) DEBUG_LOG(leetcode_utils::LogLevel::DEBUG, fmt __VA_OPT__(, ) __VA_ARGS__);

#define DEBUG_LOG_INFO(fmt, ...) DEBUG_LOG(leetcode_utils::LogLevel::INFO, fmt __VA_OPT__(, ) __VA_ARGS__);

#define DEBUG_LOG_WARN(fmt, ...) DEBUG_LOG(leetcode_utils::LogLevel::WARN, fmt __VA_OPT__(, ) __VA_ARGS__);

#define DEBUG_LOG_ERR(fmt, ...) DEBUG_LOG(leetcode_utils::LogLevel::ERR, fmt __VA_OPT__(, ) __VA_ARGS__);

#define DEBUG_LOG_FATAL(fmt, ...)                                                   \
    do {                                                                            \
        DEBUG_LOG(leetcode_utils::LogLevel::FATAL, fmt __VA_OPT__(, ) __VA_ARGS__); \
        std::abort();                                                               \
    } while (0)

#endif  // LEETCODE_UTILS_LOGGING_HPP
