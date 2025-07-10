/*
 * Time : 2025-05-20 11:57:19
 * URL  : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
 */

#include <vector>

#include "gtest/gtest.h"
#include "lc01xx/lc0121_best_time_to_buy_and_sell_stock.h"

using namespace std;

class TEST_LC0121 : public testing::Test {
protected:
    LC0121_BestTimeToBuyAndSellStock m_test;
    void RunTest(vector<int>& nums, int expectResult);
};

void TEST_LC0121::RunTest(vector<int>& nums, int expectResult)
{
    EXPECT_EQ(expectResult, m_test.maxProfit(nums));
}

TEST_F(TEST_LC0121, case1)
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    RunTest(nums, 5);
}

TEST_F(TEST_LC0121, case2)
{
    vector<int> nums = {7, 6, 4, 3, 1};
    RunTest(nums, 0);
}
