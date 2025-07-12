/*
 * Time : 2025-06-17 23:18:53
 * URL  :
 * https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/description/?envType=problem-list-v2URL_STRenvId=binary-search
 */
#include <algorithm>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc01xx/lc015x/lc0154_find_minimum_in_rotated_sorted_array_ii.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC0154 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0154_FindMinimumInRotatedSortedArrayII *> m_testList;
    void RunTest(vector<int> &nums);
};

void TEST_LC0154::SetUp()
{
    m_testList.push_back(new LC0154_FindMinimumInRotatedSortedArrayII_F1());
    m_testList.push_back(new LC0154_FindMinimumInRotatedSortedArrayII_F2());
}

void TEST_LC0154::TearDown()
{
    for (LC0154_FindMinimumInRotatedSortedArrayII *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0154::RunTest(vector<int> &nums)
{
    for (LC0154_FindMinimumInRotatedSortedArrayII *inst : m_testList) {
        int result = inst->findMin(nums);
        sort(nums.begin(), nums.end());
        EXPECT_EQ(nums[0], result) << Vector2String(nums);
    }
}

TEST_F(TEST_LC0154, case1)
{
    vector<int> nums = {1, 3, 5};
    RunTest(nums);
}

TEST_F(TEST_LC0154, case2)
{
    vector<int> nums = {1, 1, 1, 3, 3, 3, 5};
    RunTest(nums);
}

TEST_F(TEST_LC0154, case3)
{
    vector<int> nums = {5, 4, 3, 2, 1};
    RunTest(nums);
}

TEST_F(TEST_LC0154, case4)
{
    vector<int> nums = {5, 5, 5, 4, 3, 2, 2, 1, 1, 1};
    RunTest(nums);
}

TEST_F(TEST_LC0154, case5)
{
    vector<int> nums = {3, 4, 5, 0, 1, 2};
    RunTest(nums);
}

TEST_F(TEST_LC0154, case6)
{
    vector<int> nums = {2, 2, 2, 0, 1};
    RunTest(nums);
}

TEST_F(TEST_LC0154, case7)
{
    vector<int> nums = {3, 4, 5, 0, 1, 2, 2, 2};
    RunTest(nums);
}

TEST_F(TEST_LC0154, case8)
{
    vector<int> nums = {5, 5, 5, 0, 1, 2, 5, 5, 5};
    RunTest(nums);
}

TEST_F(TEST_LC0154, case9)
{
    vector<int> nums = {5, 5, 5, 5, 5, 5};
    RunTest(nums);
}

TEST_F(TEST_LC0154, case10)
{
    vector<int> nums = {5};
    RunTest(nums);
}

TEST_F(TEST_LC0154, case11)
{
    vector<int> nums = {5, 6};
    RunTest(nums);
}

TEST_F(TEST_LC0154, case12)
{
    vector<int> nums = {6, 5};
    RunTest(nums);
}

TEST_F(TEST_LC0154, case13)
{
    vector<int> nums = {3, 3, 1, 3};
    RunTest(nums);
}
