/*
 * Time : 2025-07-13 21:48:24
 * URL  : https://leetcode.cn/problems/remove-duplicate-letters/?envType=problem-list-v2&envId=monotonic-stack
 */
#include "lc0xxx/lc03xx/lc031x/lc0316_remove_duplicate_letters.h"

#include <cstdint>
#include <string>

using namespace std;

#define IDX(chr) (static_cast<std::size_t>((chr) - 'a'))

std::string LC0316_RemoveDuplicateLetters::removeDuplicateLetters(std::string s)
{
    constexpr uint32_t CHAR_NUM = 26;

    uint32_t charCount[CHAR_NUM] = {0};
    bool isInStack[CHAR_NUM] = {false};

    for (const auto& c : s) {
        charCount[IDX(c)]++;
    }

    std::string ans;
    ans.reserve(s.size());

    for (const auto& c : s) {
        charCount[IDX(c)]--;
        if (isInStack[IDX(c)]) {
            continue;
        }
        while (!ans.empty() && c < ans.back() && charCount[IDX(ans.back())] > 0) {
            isInStack[IDX(ans.back())] = false;
            ans.pop_back();
        }
        ans.push_back(c);
        isInStack[IDX(c)] = true;
    }

    return ans;
}
