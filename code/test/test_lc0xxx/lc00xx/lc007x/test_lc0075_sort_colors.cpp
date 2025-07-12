// https://leetcode.cn/problems/sort-colors/description/?envType=daily-question&envId=2025-05-17
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc00xx/lc007x/lc0075_sort_colors.h"

using namespace std;

class TEST_LC0075 : public testing::Test {
protected:
    LC0075_SortColors m_test;
    void RunTest(vector<int>& nums, const vector<int>& expectResult);
};

void TEST_LC0075::RunTest(vector<int>& nums, const vector<int>& expectResult)
{
    const size_t l = nums.size();
    m_test.sortColors(nums);
    for (size_t i = 0; i < l; i++) {
        EXPECT_EQ(nums.at(i), expectResult.at(i));
    }
}

TEST_F(TEST_LC0075, case1)
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    vector<int> expectResult = {0, 0, 1, 1, 2, 2};
    RunTest(nums, expectResult);
}

TEST_F(TEST_LC0075, case2)
{
    vector<int> nums = {2, 0, 1};
    vector<int> expectResult = {0, 1, 2};
    RunTest(nums, expectResult);
}

TEST_F(TEST_LC0075, case3)
{
    vector<int> nums = {3, 2, 1, 0};
    vector<int> expectResult = {0, 1, 2, 3};
    RunTest(nums, expectResult);
}
