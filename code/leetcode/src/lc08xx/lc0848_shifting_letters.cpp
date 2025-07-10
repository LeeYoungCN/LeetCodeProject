/*
 * Time : 2025-07-05 14:04:07
 * URL  : https://leetcode.cn/problems/shifting-letters/description/
 */
#include "lc08xx/lc0848_shifting_letters.h"

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

std::string LC0848_ShiftingLetters::shiftingLetters(std::string s, std::vector<int32_t>& shifts)
{
    for (size_t n = shifts.size(); n > 0; --n) {
        if (n != shifts.size()) {
            shifts[n - 1] += shifts[n] % 26;
        }
        s[n - 1] = static_cast<char>('a' + (s[n - 1] - 'a' + shifts[n - 1]) % 26);
    }
    return s;
}
