/*
 * Time : 2025-07-11 10:44:22
 * URL  : https://leetcode.cn/problems/merge-intervals/
 */
#include "lc0xxx/lc00xx/lc005x/lc0056_merge_intervals.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

using namespace std;

std::vector<std::vector<int32_t>> LC0056_MergeIntervals::merge(std::vector<std::vector<int32_t>>& intervals)
{
    constexpr size_t START = 0;
    constexpr size_t END = 1;

    std::vector<std::vector<int32_t>> ans;
    std::sort(intervals.begin(), intervals.end());
    for (const auto& interval : intervals) {
        if (ans.empty() || ans.back()[END] < interval[START]) {
            ans.emplace_back(interval);
        } else {
            ans.back()[END] = max(ans.back()[END], interval[END]);
        }
    }
    return ans;
}
