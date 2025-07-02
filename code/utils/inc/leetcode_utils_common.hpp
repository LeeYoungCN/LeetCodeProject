#ifndef LEETCODE_UTILS_COMMON_HPP
#define LEETCODE_UTILS_COMMON_HPP

#define LOG(fmt, ...)                                        \
    do {                                                     \
        printf("[%s:%d %s] ", __FILE__, __LINE__, __func__); \
        printf(fmt, __VA_ARGS__);                            \
        printf("\n");                                        \
    } while (0);

#endif  // LEETCODE_UTILS_COMMON_HPP
