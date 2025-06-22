/*
 * Time : 2025-06-22 18:18:39
 * URL  : https://leetcode.cn/problems/decode-ways/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#include "lc0091_decode_ways.h"

#include <cstdint>
#include <string>
#include <vector>

using namespace std;

int LC0091_DecodeWays::numDecodings(std::string s)
{
    if (s[0] == '0') {
        return 0;
    }
    const auto length = static_cast<uint32_t>(s.length());

    constexpr uint32_t shortIdx = 0;
    constexpr uint32_t longIdx = 1;

    vector<vector<string>> dpSuffix(2, vector<string>(length, ""));
    vector<vector<uint32_t>> dpLength(2, vector<uint32_t>(length, 0));

    dpSuffix[shortIdx][0] += s[0];
    dpLength[shortIdx][0] = 1;

    for (uint32_t i = 1; i < length; ++i) {
        char c = s[i];
        if (c == '0') {
            if (dpLength[shortIdx][i - 1] == 0 ||
                (dpSuffix[shortIdx][i - 1].back() != '1' && dpSuffix[shortIdx][i - 1].back() != '2')) {
                return 0;
            }
            dpLength[longIdx][i] = dpLength[shortIdx][i - 1];
            dpLength[shortIdx][i] = 0;
            dpSuffix[longIdx][i] = dpSuffix[shortIdx][i - 1] + c;
            dpSuffix[shortIdx][i] = "";
        } else {
            dpLength[shortIdx][i] = dpLength[shortIdx][i - 1] + dpLength[longIdx][i - 1];
            dpSuffix[shortIdx][i] += c;
            if (dpLength[shortIdx][i - 1] == 0) {
                continue;
            }
            if ((dpSuffix[shortIdx][i - 1].back() == '1' && (c >= '1' && c <= '9')) ||
                (dpSuffix[shortIdx][i - 1].back() == '2' && (c >= '1' && c <= '6'))) {
                dpLength[longIdx][i] = dpLength[shortIdx][i - 1];
                dpSuffix[longIdx][i] = dpSuffix[shortIdx][i - 1] + c;
            }
        }
    }
    return static_cast<int32_t>(dpLength[shortIdx][length - 1] + dpLength[longIdx][length - 1]);
}
