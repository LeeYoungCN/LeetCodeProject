/*
 * Time     : 2025-05-20 11:57:19
 * URL      : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
 * Problem  : 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 *            你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
 *            返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
 */

#include <cstdint>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include "lc0121_best_time_to_buy_and_sell_stock.h"

using namespace std;

int Lc0121_BestTimeToBuyAndSellStock::maxProfit(vector<int>& prices)
{
    int32_t ret = INT32_MIN;
    int32_t minPrice = __INT32_MAX__;
    for (uint32_t i = 0; i < prices.size(); ++i) {
        int currPrice = prices[i];
        minPrice = min(minPrice, currPrice);
        ret = max(ret, currPrice - minPrice);
    }
    return ret;
}

