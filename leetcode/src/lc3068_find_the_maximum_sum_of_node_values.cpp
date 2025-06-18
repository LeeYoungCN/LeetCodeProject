/*
 * Time : 2025-05-23 01:03:47
 * URL  :
 * https://leetcode.cn/problems/find-the-maximum-sum-of-node-values/description/?envType=daily-questionURL_STRenvId=2025-05-23
 */
#include "lc3068_find_the_maximum_sum_of_node_values.h"

#include <algorithm>
#include <cstdint>
#include <functional>
#include <vector>

using namespace std;

long long LC3068_FindTheMaximumSumOfNodeValues_Greedy::maximumValueSum(vector<int> &nums, int k,
                                                                       [[maybe_unused]] vector<vector<int>> &edges)
{
    const auto length = static_cast<uint32_t>(nums.size());

    int64_t ret = 0;
    vector<int64_t> diffArray(length, 0);

    for (uint32_t i = 0; i < length; i++) {
        diffArray[i] = (nums[i] ^ k) - nums[i];
        ret += nums[i];
    }

    sort(diffArray.begin(), diffArray.end(), greater<>());

    for (uint32_t i = 1; i < length; i += 2) {
        const int64_t sum = diffArray[i] + diffArray[i - 1];
        if (sum >= 0) {
            ret += sum;
        } else {
            break;
        }
    }
    return ret;
}

long long LC3068_FindTheMaximumSumOfNodeValues_DFS::maximumValueSum(std::vector<int> &nums, int k,
                                                                    std::vector<std::vector<int>> &edges)
{
    auto totalNode = static_cast<uint32_t>(nums.size());
    vector<vector<uint32_t>> grid(totalNode);

    for (const vector<int32_t> &edge : edges) {
        constexpr uint32_t START_IDX = 0;
        constexpr uint32_t END_IDX = 1;
        auto start = static_cast<uint32_t>(edge[START_IDX]);
        auto end = static_cast<uint32_t>(edge[END_IDX]);
        grid[start].push_back(end);
        grid[end].push_back(start);
    }

    vector<vector<int64_t>> dp = {
        vector<int64_t>(totalNode, 0),         // not flip
        vector<int64_t>(totalNode, INT64_MIN)  // flip
    };

    constexpr uint32_t NOT_FLIP_IDX = 0;
    constexpr uint32_t FLIP_IDX = 1;

    auto dfs = [&](auto &&dfs, uint32_t curr, uint32_t parent) -> void {
        for (uint32_t child : grid[curr]) {
            if (child == parent) {
                continue;
            }
            dfs(dfs, child, curr);
            const int64_t notFlip =
                max(dp[FLIP_IDX][curr] + dp[FLIP_IDX][child], dp[NOT_FLIP_IDX][curr] + dp[NOT_FLIP_IDX][child]);
            const int64_t flip =
                max(dp[NOT_FLIP_IDX][curr] + dp[FLIP_IDX][child], dp[FLIP_IDX][curr] + dp[NOT_FLIP_IDX][child]);

            dp[NOT_FLIP_IDX][curr] = notFlip;
            dp[FLIP_IDX][curr] = flip;
        }

        const int64_t oldNotflip = dp[NOT_FLIP_IDX][curr];
        const int64_t oldFlip = dp[FLIP_IDX][curr];

        dp[NOT_FLIP_IDX][curr] = max(oldNotflip + nums[curr], oldFlip + (nums[curr] ^ k));
        dp[FLIP_IDX][curr] = max(oldNotflip + (nums[curr] ^ k), oldFlip + nums[curr]);
    };

    dfs(dfs, 0, totalNode);
    return dp[NOT_FLIP_IDX][0];
}

long long LC3068_FindTheMaximumSumOfNodeValues_DP::maximumValueSum(
    std::vector<int> &nums, int k, [[maybe_unused]] std::vector<std::vector<int>> &edges)
{
    const auto total = static_cast<uint32_t>(nums.size());

    constexpr uint32_t EVE_IDX = 0;
    constexpr uint32_t ODD_IDX = 1;

    vector<vector<int64_t>> dp = {vector<int64_t>(total), vector<int64_t>(total)};

    for (uint32_t i = 0; i < total; i++) {
        const int32_t n = nums[i];
        if (i == 0) {
            dp[EVE_IDX][i] = n;
            dp[ODD_IDX][i] = (n ^ k);
        } else {
            dp[EVE_IDX][i] = max(dp[EVE_IDX][i - 1] + n, dp[ODD_IDX][i - 1] + (n ^ k));
            dp[ODD_IDX][i] = max(dp[ODD_IDX][i - 1] + n, dp[EVE_IDX][i - 1] + (n ^ k));
        }
    }
    return dp[EVE_IDX][total - 1];
}
