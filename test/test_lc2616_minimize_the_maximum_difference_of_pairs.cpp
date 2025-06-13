/*
 * Time : 2025-06-13 14:04:58
 * URL  :
 * https://leetcode.cn/problems/minimize-the-maximum-difference-of-pairs/description/?envType=daily-questionURL_STRenvId=2025-06-13
 */
#include "gtest/gtest.h"
#include "lc2616_minimize_the_maximum_difference_of_pairs.h"
#include "leetcode_utils.h"

using namespace std;

class TEST_LC2616 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2616_MinimizeTheMaximumDifferenceOfPairs *> m_testList;
    void RunTest(vector<int> &nums, int p, int expect);
};

void TEST_LC2616::SetUp()
{
    m_testList.push_back(new LC2616_MinimizeTheMaximumDifferenceOfPairs());
}

void TEST_LC2616::TearDown()
{
    for (LC2616_MinimizeTheMaximumDifferenceOfPairs *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2616::RunTest(vector<int> &nums, int p, int expect)
{
    for (LC2616_MinimizeTheMaximumDifferenceOfPairs *inst : m_testList) {
        int result = inst->minimizeMax(nums, p);
        EXPECT_EQ(expect, result) << Vector2String(nums);
    }
}

TEST_F(TEST_LC2616, case1)
{
    vector<int> nums = {10, 1, 2, 7, 1, 3};
    int p = 2;
    int expect = 1;
    RunTest(nums, p, expect);
}

TEST_F(TEST_LC2616, case2)
{
    vector<int> nums = {4, 2, 1, 2};
    int p = 1;
    int expect = 0;
    RunTest(nums, p, expect);
}
