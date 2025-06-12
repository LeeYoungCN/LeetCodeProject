/*
 * Time : 2025-05-27 16:34:50
 * URL  : https://leetcode.cn/problems/zero-array-transformation-iv/
 */
#include "lc3489_zero_array_transformation_iv.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

int32_t LC3489_ZeroArrayTransformationIV::GetStep(uint32_t idx, const vector<int32_t> &nums,
                                                  const vector<vector<int32_t>> &queries)
{
    auto target = static_cast<uint32_t>(nums[idx]);
    if (target == 0) {
        return 0;
    }

    auto queryCnt = static_cast<uint32_t>(queries.size());

    vector<bool> dp(static_cast<uint32_t>(target) + 1, false);
    dp.at(0) = true;

    for (uint32_t i = 0; i < queryCnt; i++) {
        if (idx < static_cast<uint32_t>(queries[i][0]) || idx > static_cast<uint32_t>(queries[i][1])) {
            continue;
        }

        auto val = static_cast<uint32_t>(queries[i][2]);
        if (val == 0) {
            continue;
        }

        for (uint32_t j = target; j >= val; --j) {
            dp.at(j) = dp.at(j) || dp.at(j - val);
        }

        if (dp.at(target)) {
            return static_cast<int32_t>(i) + 1;
        }
    }
    return -1;
}

int LC3489_ZeroArrayTransformationIV::minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
{
    auto numCnt = static_cast<uint32_t>(nums.size());
    int32_t ans = 0;
    for (uint32_t i = 0; i < numCnt; i++) {
        int32_t step = GetStep(i, nums, queries);
        if (step < 0) {
            return -1;
        }
        ans = max(ans, step);
    }
    return ans;
}
