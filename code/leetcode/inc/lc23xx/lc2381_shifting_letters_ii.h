/*
 * Time : 2025-07-05 14:53:48
 * URL  : https://leetcode.cn/problems/shifting-letters-ii/description/
 */
#ifndef LC2381_SHIFTING_LETTERS_II_H
#define LC2381_SHIFTING_LETTERS_II_H

#include <cstdint>
#include <string>
#include <vector>

class LC2381_ShiftingLettersII {
public:
    LC2381_ShiftingLettersII() = default;
    virtual ~LC2381_ShiftingLettersII() = default;
    std::string shiftingLetters(std::string s, std::vector<std::vector<int32_t>>& shifts);
};

#endif  // LC2381_SHIFTING_LETTERS_II_H
