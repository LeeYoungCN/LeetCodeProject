/*
 * Time : 2025-06-23 18:53:34
 * URL  :
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/?envType=problem-list-v2&envId=dynamic-programming
 */
#ifndef LC0123_BEST_TIME_TO_BUY_AND_SELL_STOCK_III_H
#define LC0123_BEST_TIME_TO_BUY_AND_SELL_STOCK_III_H

#include <vector>

class LC0123_BestTimeToBuyAndSellStockIII {
public:
    LC0123_BestTimeToBuyAndSellStockIII() = default;
    virtual ~LC0123_BestTimeToBuyAndSellStockIII() = default;
    int maxProfit(std::vector<int>& prices);
};

#endif  // LC0123_BEST_TIME_TO_BUY_AND_SELL_STOCK_III_H
