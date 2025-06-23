/*
 * Time : 2025-06-23 13:31:18
 * URL  :
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#ifndef LC0122_BEST_TIME_TO_BUY_AND_SELL_STOCK_II_H
#define LC0122_BEST_TIME_TO_BUY_AND_SELL_STOCK_II_H

#include <vector>

class LC0122_BestTimeToBuyAndSellStockII {
public:
    LC0122_BestTimeToBuyAndSellStockII() = default;
    virtual ~LC0122_BestTimeToBuyAndSellStockII() = default;
    virtual int maxProfit(std::vector<int>& prices) = 0;
};

class LC0122_BestTimeToBuyAndSellStockII_Greedy : public LC0122_BestTimeToBuyAndSellStockII {
public:
    LC0122_BestTimeToBuyAndSellStockII_Greedy() = default;
    ~LC0122_BestTimeToBuyAndSellStockII_Greedy() override = default;
    int maxProfit(std::vector<int>& prices) final;
};

class LC0122_BestTimeToBuyAndSellStockII_DP : public LC0122_BestTimeToBuyAndSellStockII {
public:
    LC0122_BestTimeToBuyAndSellStockII_DP() = default;
    ~LC0122_BestTimeToBuyAndSellStockII_DP() override = default;
    int maxProfit(std::vector<int>& prices) final;
};

#endif  // LC0122_BEST_TIME_TO_BUY_AND_SELL_STOCK_II_H
