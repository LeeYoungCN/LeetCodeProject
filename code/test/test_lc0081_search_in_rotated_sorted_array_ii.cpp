/*
 * Time : 2025-06-16 21:43:17
 * URL  :
 * https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/description/?envType=problem-list-v2URL_STRenvId=binary-search
 */

#include <cstdint>
#include <vector>

#include "gtest/gtest.h"
#include "lc0081_search_in_rotated_sorted_array_ii.h"
#include "leetcode_utils.hpp"

using namespace std;

class TEST_LC0081 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0081_SearchInRotatedSortedArrayII*> m_testList;
    void RunTest(vector<int32_t>& nums, int32_t target, const bool& expect);
};

void TEST_LC0081::SetUp()
{
    m_testList.push_back(new LC0081_SearchInRotatedSortedArrayII_DFS());
    m_testList.push_back(new LC0081_SearchInRotatedSortedArrayII_Loop());
}

void TEST_LC0081::TearDown()
{
    for (LC0081_SearchInRotatedSortedArrayII* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0081::RunTest(vector<int32_t>& nums, int32_t target, const bool& expect)
{
    for (LC0081_SearchInRotatedSortedArrayII* inst : m_testList) {
        bool result = inst->search(nums, target);
        EXPECT_EQ(expect, result) << "nums = " << Vector2String(nums) << ", target = " << target;
    }
}

TEST_F(TEST_LC0081, case1)
{
    vector<int32_t> nums = {2, 5, 6, 0, 0, 1, 2};
    int32_t target = 0;
    const bool expect = true;
    RunTest(nums, target, expect);
}

TEST_F(TEST_LC0081, case2)
{
    vector<int32_t> nums = {2, 5, 6, 0, 0, 1, 2};
    int32_t target = 3;
    const bool expect = false;
    RunTest(nums, target, expect);
}

TEST_F(TEST_LC0081, case3)
{
    vector<int32_t> nums = {1, 0, 1, 1, 1};
    int32_t target = 0;
    const bool expect = true;
    RunTest(nums, target, expect);
}
