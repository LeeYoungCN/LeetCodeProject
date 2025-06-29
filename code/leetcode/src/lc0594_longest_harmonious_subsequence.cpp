/*
 * Time : 2025-06-30 00:24:59
 * URL  : https://leetcode.cn/problems/longest-harmonious-subsequence/?envType=daily-question&envId=2025-06-30
 */
#include "lc0594_longest_harmonious_subsequence.h"

#include <algorithm>
#include <cstdint>
#include <map>
#include <vector>

using namespace std;

int32_t LC0594_LongestHarmoniousSubsequence::findLHS(std::vector<int32_t>& nums)
{
    map<int32_t, int32_t> numMap;
    for (const auto& n : nums) {
        numMap[n]++;
    }
    int32_t ans = 0;

    auto preIt = numMap.begin();
    auto it = preIt;

    for (++it; it != numMap.end(); ++it) {
        if (it->first == preIt->first + 1) {
            ans = max(it->second + preIt->second, ans);
        }
        preIt = it;
    }

    return ans;
}
