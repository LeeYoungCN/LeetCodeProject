#include "leetcode_utils/leetcode_utils_common.hpp"

#include <cstdint>
#include <string>

bool isNumber(uint32_t idx, const std::string& str)
{
    if (str[idx] == '-') {
        if (idx >= str.length() - 1) {
            return false;
        } else {
            idx++;
        }
    }
    return (str[idx] >= '0' && str[idx] <= '9');
}

bool isLowerAlpha(char c)
{
    return c >= 'a' && c <= 'z';
}

bool isUpperAlpha(char c)
{
    return c >= 'A' && c <= 'Z';
}

bool isAlpha(char c)
{
    return isLowerAlpha(c) || isUpperAlpha(c);
}
