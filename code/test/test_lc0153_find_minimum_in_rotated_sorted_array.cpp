/*
 * Time : 2025-06-17 17:27:54
 * URL  :
 * https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/?envType=problem-list-v2URL_STRenvId=binary-search
 */
#include <algorithm>
#include <vector>

#include "gtest/gtest.h"
#include "lc0153_find_minimum_in_rotated_sorted_array.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC0153 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0153_FindMinimumInRotatedSortedArray*> m_testList;
    void RunTest(vector<int>& nums);
};

void TEST_LC0153::SetUp()
{
    m_testList.push_back(new LC0153_FindMinimumInRotatedSortedArray_F1());
    m_testList.push_back(new LC0153_FindMinimumInRotatedSortedArray_F2());
}

void TEST_LC0153::TearDown()
{
    for (LC0153_FindMinimumInRotatedSortedArray* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0153::RunTest(vector<int>& nums)
{
    for (LC0153_FindMinimumInRotatedSortedArray* inst : m_testList) {
        int result = inst->findMin(nums);
        sort(nums.begin(), nums.end());
        EXPECT_EQ(nums[0], result) << Vector2String(nums);
    }
}

TEST_F(TEST_LC0153, case1)
{
    vector<int> nums = {3, 4, 5, 1, 2};
    RunTest(nums);
}

TEST_F(TEST_LC0153, case2)
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    RunTest(nums);
}

TEST_F(TEST_LC0153, case3)
{
    vector<int> nums = {11, 13, 15, 17};
    RunTest(nums);
}

TEST_F(TEST_LC0153, case5)
{
    vector<int> nums = {10, 5, 3, 2, 1};
    RunTest(nums);
}

TEST_F(TEST_LC0153, case6)
{
    vector<int> nums = {10};
    RunTest(nums);
}

TEST_F(TEST_LC0153, case7)
{
    vector<int> nums = {10, 9};
    RunTest(nums);
}
