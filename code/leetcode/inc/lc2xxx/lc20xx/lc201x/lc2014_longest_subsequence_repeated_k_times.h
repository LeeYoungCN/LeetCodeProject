/*
 * Time : 2025-06-27 18:01:21
 * URL  :
 * https://leetcode.cn/problems/longest-subsequence-repeated-k-times/solutions/1006067/mei-ju-pai-lie-zi-xu-lie-pi-pei-by-endle-oi2h/?envType=daily-question&envId=2025-06-27
 */
#ifndef LC2014_LONGEST_SUBSEQUENCE_REPEATED_K_TIMES_H
#define LC2014_LONGEST_SUBSEQUENCE_REPEATED_K_TIMES_H

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

class LC2014_LongestSubsequenceRepeatedKTimes {
public:
    LC2014_LongestSubsequenceRepeatedKTimes() = default;
    virtual ~LC2014_LongestSubsequenceRepeatedKTimes() = default;
    std::string longestSubsequenceRepeatedK(std::string s, int k);

private:
    void dfs(const std::vector<char>& charList, size_t maxLen, std::vector<bool>& visitor, std::string& currStr,
             std::string& ans);
    bool isKTimesSubStr(const std::string& currStr);
    std::string rawStr;
    uint32_t kTimes = 0;
};

#endif  // LC2014_LONGEST_SUBSEQUENCE_REPEATED_K_TIMES_H
