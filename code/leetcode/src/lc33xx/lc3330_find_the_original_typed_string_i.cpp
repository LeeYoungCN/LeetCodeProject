/*
 * Time : 2025-07-01 09:00:08
 * URL  : https://leetcode.cn/problems/find-the-original-typed-string-i/?envType=daily-question&envId=2025-07-01
 */
#include "lc33xx/lc3330_find_the_original_typed_string_i.h"

#include <cstdint>
#include <string>

using namespace std;

int32_t LC3330_FindTheOriginalTypedStringI::possibleStringCount(std::string word)
{
    char preChar = '\0';
    int32_t preCnt = 1;
    int32_t ans = 1;
    for (const auto& c : word) {
        if (c != preChar) {
            ans += preCnt - 1;
            preChar = c;
            preCnt = 1;
        } else {
            ++preCnt;
        }
    }
    return ans + preCnt - 1;
}
