#ifndef LEETCODE_UTILS_COMMON_HPP
#define LEETCODE_UTILS_COMMON_HPP

#include <cstdint>
#include <string>

#define LOG(fmt, ...)                                        \
    do {                                                     \
        printf("[%s:%d %s] ", __FILE__, __LINE__, __func__); \
        printf(fmt, __VA_ARGS__);                            \
        printf("\n");                                        \
    } while (0);

bool isNumber(uint32_t idx, const std::string& str);
bool isLowerAlpha(char c);
bool isUpperAlpha(char c);
bool isAlpha(char c);

#endif  // LEETCODE_UTILS_COMMON_HPP
