/*
 * Time : 2025-05-20 11:57:19
 * URL  : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
 */

#include "lc0121_best_time_to_buy_and_sell_stock.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

int LC0121_BestTimeToBuyAndSellStock::maxProfit(vector<int>& prices)
{
    int32_t ret = INT32_MIN;
    int32_t minPrice = INT32_MAX;
    for (int currPrice : prices) {
        minPrice = min(minPrice, currPrice);
        ret = max(ret, currPrice - minPrice);
    }
    return ret;
}
