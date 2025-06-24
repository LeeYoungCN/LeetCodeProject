/*
 * Time : 2025-06-12 10:00:49
 * URL  :
 * https://leetcode.cn/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/?envType=daily-questionURL_STRenvId=2025-06-12
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc3423_maximum_difference_between_adjacent_elements_in_a_circular_array.h"

using namespace std;

class TEST_LC3423 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3423_MaximumDifferenceBetweenAdjacentElementsInACircularArray *> m_testList;
    void RunTest(vector<int> &nums, int expect);
};

void TEST_LC3423::SetUp()
{
    m_testList.push_back(new LC3423_MaximumDifferenceBetweenAdjacentElementsInACircularArray());
}

void TEST_LC3423::TearDown()
{
    for (LC3423_MaximumDifferenceBetweenAdjacentElementsInACircularArray *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3423::RunTest(vector<int> &nums, int expect)
{
    for (LC3423_MaximumDifferenceBetweenAdjacentElementsInACircularArray *inst : m_testList) {
        int result = inst->maxAdjacentDistance(nums);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC3423, case1)
{
    vector<int> nums = {1, 2, 4};
    int expect = 3;
    RunTest(nums, expect);
}

TEST_F(TEST_LC3423, case2)
{
    vector<int> nums = {-5, -10, -5};
    int expect = 5;
    RunTest(nums, expect);
}
