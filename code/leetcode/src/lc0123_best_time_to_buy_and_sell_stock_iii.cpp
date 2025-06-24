/*
 * Time : 2025-06-23 18:53:34
 * URL  :
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/?envType=problem-list-v2&envId=dynamic-programming
 */
#include "lc0123_best_time_to_buy_and_sell_stock_iii.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

enum DP_INDEX : uint32_t { BUY1 = 0, SELL1, BUY2, SELL2, CNT };

int LC0123_BestTimeToBuyAndSellStockIII::maxProfit(std::vector<int>& prices)
{
    const auto length = static_cast<uint32_t>(prices.size());

    vector<vector<int32_t>> dp(CNT, vector<int32_t>(length, 0));

    dp[BUY1][0] = -prices[0];
    dp[SELL1][0] = 0;
    dp[BUY2][0] = -prices[0];
    dp[SELL2][0] = 0;

    for (uint32_t i = 1; i < length; ++i) {
        dp[BUY1][i] = max(dp[BUY1][i - 1], -prices[i]);
        dp[SELL1][i] = max(dp[SELL1][i - 1], dp[BUY1][i - 1] + prices[i]);
        dp[BUY2][i] = max(dp[BUY2][i - 1], dp[SELL1][i - 1] - prices[i]);
        dp[SELL2][i] = max(dp[SELL2][i - 1], dp[BUY2][i - 1] + prices[i]);
    }

    return dp[SELL2][length - 1];
}
