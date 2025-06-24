/*
 * Time : 2025-06-24 16:21:12
 * URL  : https://leetcode.cn/problems/word-break/?envType=problem-list-v2&envId=dynamic-programming
 */
#ifndef LC0139_WORD_BREAK_H
#define LC0139_WORD_BREAK_H

#include <string>
#include <vector>

class LC0139_WordBreak {
public:
    LC0139_WordBreak() = default;
    virtual ~LC0139_WordBreak() = default;
    bool wordBreak(std::string s, std::vector<std::string>& wordDict);
};

#endif  // LC0139_WORD_BREAK_H
