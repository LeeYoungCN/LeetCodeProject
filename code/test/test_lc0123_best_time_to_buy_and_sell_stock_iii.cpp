/*
 * Time : 2025-06-23 18:53:34
 * URL  :
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/?envType=problem-list-v2&envId=dynamic-programming
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc0123_best_time_to_buy_and_sell_stock_iii.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC0123 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0123_BestTimeToBuyAndSellStockIII*> m_testList;
    void RunTest(std::vector<int>& prices, const int& expect);
};

void TEST_LC0123::SetUp()
{
    m_testList.push_back(new LC0123_BestTimeToBuyAndSellStockIII());
}

void TEST_LC0123::TearDown()
{
    for (LC0123_BestTimeToBuyAndSellStockIII* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0123::RunTest(std::vector<int>& prices, const int& expect)
{
    for (LC0123_BestTimeToBuyAndSellStockIII* inst : m_testList) {
        int result = inst->maxProfit(prices);
        EXPECT_EQ(expect, result) << Vector2String(prices);
    }
}

TEST_F(TEST_LC0123, case1)
{
    std::vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    const int expect = 6;
    RunTest(prices, expect);
}

TEST_F(TEST_LC0123, case2)
{
    std::vector<int> prices = {1, 2, 3, 4, 5};
    const int expect = 4;
    RunTest(prices, expect);
}

TEST_F(TEST_LC0123, case3)
{
    std::vector<int> prices = {7, 6, 4, 3, 1};
    const int expect = 0;
    RunTest(prices, expect);
}

TEST_F(TEST_LC0123, case4)
{
    std::vector<int> prices = {1};
    const int expect = 0;
    RunTest(prices, expect);
}
