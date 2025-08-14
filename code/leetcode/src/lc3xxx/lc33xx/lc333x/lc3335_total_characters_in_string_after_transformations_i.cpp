/*
 * Time : 2025-08-14 08:45:21
 * URL  :
 * https://leetcode.cn/problems/total-characters-in-string-after-transformations-i/?envType=daily-question&envId=2025-08-14
 */
#include "lc3xxx/lc33xx/lc333x/lc3335_total_characters_in_string_after_transformations_i.h"

#include <cstdint>
#include <string>
#include <vector>

using namespace std;

int32_t LC3335_TotalCharactersInStringAfterTransformationsI::lengthAfterTransformations(std::string s, int32_t t)
{
    constexpr int32_t MOD = 1000000007;
    constexpr uint32_t CHAR_NUM = 26;
    std::vector<int32_t> charCnt(CHAR_NUM, 0);

    for (const auto& c : s) {
        charCnt[static_cast<uint32_t>(c - 'a')]++;
    }

    for (int32_t i = 0; i < t; i++) {
        std::vector<int32_t> next(CHAR_NUM, 0);
        for (uint32_t j = 1; j < CHAR_NUM; j++) {
            next[j] = charCnt[j - 1];
        }
        next[0] = charCnt[25];
        next[1] = (next[1] + charCnt[25]) % MOD;
        charCnt = std::move(next);
    }

    int32_t ans = 0;
    for (const auto& n : charCnt) {
        ans = (ans + n) % MOD;
    }
    return ans % MOD;
}
