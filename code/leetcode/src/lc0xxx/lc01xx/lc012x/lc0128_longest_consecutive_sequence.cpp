/*
 * Time : 2025-06-06 11:46:02
 * URL  : https://leetcode.cn/problems/longest-consecutive-sequence/description/
 */
#include "lc0xxx/lc01xx/lc012x/lc0128_longest_consecutive_sequence.h"

#include <cstdint>
#include <unordered_set>
#include <vector>

using namespace std;

int LC0128_LongestConsecutiveSequence::longestConsecutive(vector<int>& nums)
{
    unordered_set<int32_t> numSet(nums.begin(), nums.end());
    int32_t ans = 0;
    for (int32_t x : numSet) {
        if (numSet.find(x - 1) != numSet.end()) {
            continue;
        }

        int32_t y = x;
        while (numSet.find(++y) != numSet.end()) {
        }
        ans = max(ans, y - x);
    }
    return ans;
}
