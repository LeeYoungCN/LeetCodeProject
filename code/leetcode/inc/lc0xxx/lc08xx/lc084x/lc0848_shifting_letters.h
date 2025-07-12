/*
 * Time : 2025-07-05 14:04:07
 * URL  : https://leetcode.cn/problems/shifting-letters/description/
 */
#ifndef LC0848_SHIFTING_LETTERS_H
#define LC0848_SHIFTING_LETTERS_H

#include <cstdint>
#include <string>
#include <vector>

class LC0848_ShiftingLetters {
public:
    LC0848_ShiftingLetters() = default;
    virtual ~LC0848_ShiftingLetters() = default;
    std::string shiftingLetters(std::string s, std::vector<int32_t>& shifts);
};

#endif  // LC0848_SHIFTING_LETTERS_H
