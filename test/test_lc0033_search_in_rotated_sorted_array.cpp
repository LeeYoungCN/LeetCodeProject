/*
 * Time : 2025-06-16 17:41:26
 * URL  : https://leetcode.cn/problems/search-in-rotated-sorted-array/description/
 */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "gtest/gtest.h"
#include "lc0033_search_in_rotated_sorted_array.h"
#include "leetcode_utils.h"

using namespace std;

class TEST_LC0033 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0033_SearchInRotatedSortedArray*> m_testList;
    void RunTest(vector<int>& nums, int target, const int& expect);
};

void TEST_LC0033::SetUp()
{
    m_testList.push_back(new LC0033_SearchInRotatedSortedArray());
}

void TEST_LC0033::TearDown()
{
    for (LC0033_SearchInRotatedSortedArray* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0033::RunTest(vector<int>& nums, int target, const int& expect)
{
    for (LC0033_SearchInRotatedSortedArray* inst : m_testList) {
        int result = inst->search(nums, target);
        EXPECT_EQ(expect, result) << "nums: " << Vector2String(nums) << ", target = " << target;
    }
}

TEST_F(TEST_LC0033, case1)
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    const int expect = 4;
    RunTest(nums, target, expect);
}

TEST_F(TEST_LC0033, case2)
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 3;
    const int expect = -1;
    RunTest(nums, target, expect);
}

TEST_F(TEST_LC0033, case3)
{
    vector<int> nums = {1};
    int target = 0;
    const int expect = -1;
    RunTest(nums, target, expect);
}
