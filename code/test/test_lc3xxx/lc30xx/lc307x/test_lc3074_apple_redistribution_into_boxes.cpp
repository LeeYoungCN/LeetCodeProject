/*
 * Time : 2025-06-01 21:43:59
 * URL  : https://leetcode.cn/problems/apple-redistribution-into-boxes/description/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc3xxx/lc30xx/lc307x/lc3074_apple_redistribution_into_boxes.h"

using namespace std;

class TEST_LC3074 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3074_AppleRedistributionIntoBoxes*> m_testList;
    void RunTest(vector<int>& apple, vector<int>& capacity, int expect);
};

void TEST_LC3074::SetUp()
{
    m_testList.push_back(new LC3074_AppleRedistributionIntoBoxes());
}

void TEST_LC3074::TearDown()
{
    for (LC3074_AppleRedistributionIntoBoxes* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3074::RunTest(vector<int>& apple, vector<int>& capacity, int expect)
{
    for (LC3074_AppleRedistributionIntoBoxes* inst : m_testList) {
        EXPECT_EQ(expect, inst->minimumBoxes(apple, capacity));
    }
}

TEST_F(TEST_LC3074, case1)
{
    vector<int> apple = {1, 3, 2};
    vector<int> capacity = {4, 3, 1, 5, 2};

    int expect = 2;
    RunTest(apple, capacity, expect);
}

TEST_F(TEST_LC3074, case2)
{
    vector<int> apple = {5, 5, 5};
    vector<int> capacity = {2, 4, 2, 7};

    int expect = 4;
    RunTest(apple, capacity, expect);
}
