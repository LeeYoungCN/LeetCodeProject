/*
 * Time : 2025-07-05 14:53:48
 * URL  : https://leetcode.cn/problems/shifting-letters-ii/description/
 */
#include "lc2381_shifting_letters_ii.h"

#include <cstdint>
#include <string>
#include <vector>

using namespace std;

std::string LC2381_ShiftingLettersII::shiftingLetters(std::string s, std::vector<std::vector<int32_t>> &shifts)
{
    constexpr size_t START = 0;
    constexpr size_t END = 1;
    constexpr uint32_t DIR = 2;
    constexpr int32_t CHR_CNT = 26;

    vector<int32_t> prefixSum(s.size() + 1);
    for (const auto &vec : shifts) {
        int delta = (vec[DIR] == 0 ? -1 : 1);
        prefixSum[static_cast<size_t>(vec[START])] += delta;
        prefixSum[static_cast<size_t>(vec[END] + 1)] -= delta;
    }

    int32_t sum = 0;
    for (uint32_t i = 0; i < s.length(); i++) {
        sum = (sum + prefixSum[i]) % static_cast<int32_t>(CHR_CNT);
        s[i] = static_cast<char>('a' + (s[i] - 'a' + (CHR_CNT + sum)) % CHR_CNT);
    }

    return s;
}
