/*
 * Time : 2025-06-23 13:31:18
 * URL  :
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc01xx/lc012x/lc0122_best_time_to_buy_and_sell_stock_ii.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC0122 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0122_BestTimeToBuyAndSellStockII*> m_testList;
    void RunTest(std::vector<int>& prices, const int& expect);
};

void TEST_LC0122::SetUp()
{
    m_testList.push_back(new LC0122_BestTimeToBuyAndSellStockII_Greedy());
    m_testList.push_back(new LC0122_BestTimeToBuyAndSellStockII_DP());
}

void TEST_LC0122::TearDown()
{
    for (LC0122_BestTimeToBuyAndSellStockII* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0122::RunTest(std::vector<int>& prices, const int& expect)
{
    for (LC0122_BestTimeToBuyAndSellStockII* inst : m_testList) {
        int result = inst->maxProfit(prices);
        EXPECT_EQ(expect, result) << Vector2String(prices);
    }
}

TEST_F(TEST_LC0122, case1)
{
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    const int expect = 7;
    RunTest(prices, expect);
}

TEST_F(TEST_LC0122, case2)
{
    std::vector<int> prices = {1, 2, 3, 4, 5};
    const int expect = 4;
    RunTest(prices, expect);
}

TEST_F(TEST_LC0122, case3)
{
    std::vector<int> prices = {7, 6, 4, 3, 1};
    const int expect = 0;
    RunTest(prices, expect);
}
