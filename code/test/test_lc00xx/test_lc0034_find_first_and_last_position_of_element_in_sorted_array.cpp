/*
 * Time : 2025-06-16 15:03:49
 * URL  :
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=problem-list-v2URL_STRenvId=binary-search
 */

#include <vector>

#include "gtest/gtest.h"
#include "lc00xx/lc0034_find_first_and_last_position_of_element_in_sorted_array.h"

using namespace std;

class TEST_LC0034 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0034_FindFirstAndLastPositionOfElementInSortedArray *> m_testList;
    void RunTest(vector<int> &nums, int target, const vector<int> &expect);
};

void TEST_LC0034::SetUp()
{
    m_testList.push_back(new LC0034_FindFirstAndLastPositionOfElementInSortedArray());
}

void TEST_LC0034::TearDown()
{
    for (LC0034_FindFirstAndLastPositionOfElementInSortedArray *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0034::RunTest(vector<int> &nums, int target, const vector<int> &expect)
{
    for (LC0034_FindFirstAndLastPositionOfElementInSortedArray *inst : m_testList) {
        vector<int> result = inst->searchRange(nums, target);
        ASSERT_EQ(expect.size(), result.size());
        for (size_t i = 0; i < expect.size(); i++) {
            EXPECT_EQ(expect[i], result[i]);
        }
    }
}

TEST_F(TEST_LC0034, case1)
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    const vector<int> expect = {3, 4};
    RunTest(nums, target, expect);
}

TEST_F(TEST_LC0034, case2)
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 6;
    const vector<int> expect = {-1, -1};
    RunTest(nums, target, expect);
}

TEST_F(TEST_LC0034, case3)
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 5;
    const vector<int> expect = {0, 0};
    RunTest(nums, target, expect);
}

TEST_F(TEST_LC0034, case4)
{
    vector<int> nums = {};
    int target = 5;
    const vector<int> expect = {-1, -1};
    RunTest(nums, target, expect);
}
