/*
 * Time : 2025-06-23 13:31:18
 * URL  :
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#include "lc01xx/lc0122_best_time_to_buy_and_sell_stock_ii.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

int LC0122_BestTimeToBuyAndSellStockII_Greedy::maxProfit(std::vector<int>& prices)
{
    int32_t ans = 0;

    for (auto it = prices.begin() + 1; it < prices.end(); ++it) {
        ans += max(0, *it - *(it - 1));
    }

    return ans;
}

int LC0122_BestTimeToBuyAndSellStockII_DP::maxProfit(std::vector<int>& prices)
{
    constexpr uint32_t buyIdx = 0;
    constexpr uint32_t sellIdx = 1;
    constexpr uint32_t statusCnt = 2;

    const auto length = static_cast<uint32_t>(prices.size());
    vector<vector<int32_t>> dp(statusCnt, vector<int32_t>(length, 0));

    dp[buyIdx][0] = -prices[0];
    dp[sellIdx][0] = 0;

    for (uint32_t i = 1; i < length; ++i) {
        dp[buyIdx][i] = max(dp[buyIdx][i - 1], dp[sellIdx][i - 1] - prices[i]);
        dp[sellIdx][i] = max(dp[sellIdx][i - 1], dp[buyIdx][i - 1] + prices[i]);
    }

    return dp[sellIdx][length - 1];
}
