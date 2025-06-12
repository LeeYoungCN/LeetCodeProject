/*
 * Time : 2025-06-02 03:20:20
 * URL  : https://leetcode.cn/problems/maximum-sum-with-at-most-k-elements/description/
 */
#include "lc3462_maximum_sum_with_at_most_k_elements.h"

#include <algorithm>
#include <cstdint>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

long long LC3462_MaximumSumWithAtMostKElements_Sort::maxSum(vector<vector<int>>& grid, vector<int>& limits, int k)
{
    const auto rowCnt = static_cast<uint32_t>(grid.size());
    vector<int64_t> valArray;

    for (uint32_t i = 0; i < rowCnt; i++) {
        sort(grid[i].begin(), grid[i].end(), greater<>());
        valArray.insert(valArray.end(), grid[i].begin(), grid[i].begin() + limits[i]);
    }
    sort(valArray.begin(), valArray.end(), greater<>());
    return reduce(valArray.begin(), valArray.begin() + k, 0LL);
}

long long LC3462_MaximumSumWithAtMostKElements_NthElement::maxSum(vector<vector<int>>& grid, vector<int>& limits, int k)
{
    const auto rowCnt = static_cast<uint32_t>(grid.size());
    vector<int64_t> valArray;

    for (uint32_t i = 0; i < rowCnt; i++) {
        nth_element(grid[i].begin(), grid[i].begin() + limits[i], grid[i].end(), greater());
        valArray.insert(valArray.end(), grid[i].begin(), grid[i].begin() + limits[i]);
    }

    nth_element(valArray.begin(), valArray.begin() + k, valArray.end(), greater<>());
    return reduce(valArray.begin(), valArray.begin() + k, 0LL);
}
