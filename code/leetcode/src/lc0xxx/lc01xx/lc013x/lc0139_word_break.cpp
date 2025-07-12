/*
 * Time : 2025-06-24 16:21:12
 * URL  : https://leetcode.cn/problems/word-break/?envType=problem-list-v2&envId=dynamic-programming
 */
#include "lc0xxx/lc01xx/lc013x/lc0139_word_break.h"

#include <cstddef>
#include <string>
#include <vector>

using namespace std;

void dfs(const std::string &s, std::vector<std::string> &wordDict, size_t curr, vector<bool> &visitor)
{
    if (curr == s.length()) {
        visitor[s.length()] = true;
        return;
    }

    if (visitor[curr]) {
        return;
    }
    visitor[curr] = true;

    for (const auto &word : wordDict) {
        if (curr + word.length() <= s.length() && s.substr(curr, word.length()) == word) {
            dfs(s, wordDict, curr + word.length(), visitor);
        }
    }
}

bool LC0139_WordBreak::wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    vector<bool> visit(s.length() + 1, false);
    dfs(s, wordDict, 0, visit);
    return visit[s.length()];
}
