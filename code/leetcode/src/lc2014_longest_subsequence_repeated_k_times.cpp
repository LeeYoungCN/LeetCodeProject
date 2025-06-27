/*
 * Time : 2025-06-27 18:01:21
 * URL  :
 * https://leetcode.cn/problems/longest-subsequence-repeated-k-times/solutions/1006067/mei-ju-pai-lie-zi-xu-lie-pi-pei-by-endle-oi2h/?envType=daily-question&envId=2025-06-27
 */
#include "lc2014_longest_subsequence_repeated_k_times.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool LC2014_LongestSubsequenceRepeatedKTimes::isKTimesSubStr(const string& currStr)
{
    uint32_t t = 0;
    uint32_t j = 0;

    for (uint32_t i = 0; i < rawStr.length(); ++i) {
        if (rawStr[i] == currStr[j]) {
            j++;
            if (j == currStr.length()) {
                j = 0;
                t++;
                if (t == kTimes) {
                    return true;
                }
            }
        }
    }
    return false;
}

void LC2014_LongestSubsequenceRepeatedKTimes::dfs(const std::vector<char>& charList, size_t maxLen,
                                                  std::vector<bool>& visitor, std::string& currStr, std::string& ans)
{
    if (currStr.size() == maxLen) {
        if (isKTimesSubStr(currStr)) {
            ans = max(ans, currStr);
        }
        return;
    }

    for (uint32_t i = 0; i < charList.size(); ++i) {
        if (visitor[i] || (i > 0 && charList[i] == charList[i - 1] && !visitor[i - 1])) {
            continue;
        }

        visitor[i] = true;
        currStr.push_back(charList[i]);
        dfs(charList, maxLen, visitor, currStr, ans);
        visitor[i] = false;
        currStr.pop_back();
    }
}

std::string LC2014_LongestSubsequenceRepeatedKTimes::longestSubsequenceRepeatedK(std::string s, int k)
{
    rawStr = std::move(s);
    kTimes = static_cast<uint32_t>(k);

    constexpr uint32_t CHAR_CNT = 26;
    uint32_t charCount[CHAR_CNT] = {0};
    for (const auto& chr : rawStr) {
        charCount[chr - 'a']++;
    }
    vector<char> charList;
    charList.reserve(rawStr.length());
    for (uint32_t i = 0; i < CHAR_CNT; ++i) {
        for (uint32_t j = 0; j < charCount[i] / kTimes; ++j) {
            charList.push_back(static_cast<char>('a' + i));
        }
    }
    string ans;
    for (size_t maxLen = charList.size(); maxLen > 0; --maxLen) {
        vector<bool> visitor(charList.size(), false);
        string currStr;
        currStr.reserve(maxLen);
        dfs(charList, maxLen, visitor, currStr, ans);
        if (!ans.empty()) {
            break;
        }
    }
    return ans;
}
