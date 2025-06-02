/*
 * Time : 2025-06-02 15:20:38
 * URL  : https://leetcode.cn/problems/minimum-cost-of-buying-candies-with-discount/description/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc2144_minimum_cost_of_buying_candies_with_discount.h"

using namespace std;

class TEST_LC2144 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2144_MinimumCostOfBuyingCandiesWithDiscount *> m_testList;
    void RunTest(std::vector<int> &cost, int expect);
};

void TEST_LC2144::SetUp()
{
    m_testList.push_back(new LC2144_MinimumCostOfBuyingCandiesWithDiscount());
}

void TEST_LC2144::TearDown()
{
    for (LC2144_MinimumCostOfBuyingCandiesWithDiscount *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2144::RunTest(std::vector<int> &cost, int expect)
{
    for (LC2144_MinimumCostOfBuyingCandiesWithDiscount *inst : m_testList) {
        EXPECT_EQ(expect, inst->minimumCost(cost));
    }
}

TEST_F(TEST_LC2144, case1)
{
    std::vector<int> cost = {1, 2, 3};
    int expect = 5;
    RunTest(cost, expect);
}

TEST_F(TEST_LC2144, case2)
{
    std::vector<int> cost = {6, 5, 7, 9, 2, 2};
    int expect = 23;
    RunTest(cost, expect);
}

TEST_F(TEST_LC2144, case3)
{
    std::vector<int> cost = {5, 5};
    int expect = 10;
    RunTest(cost, expect);
}
