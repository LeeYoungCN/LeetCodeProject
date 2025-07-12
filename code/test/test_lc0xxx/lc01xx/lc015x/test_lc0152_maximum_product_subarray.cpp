/*
 * Time : 2025-05-20 15:14:30
 * URL  : https://leetcode.cn/problems/maximum-product-subarray/
 */

#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc01xx/lc015x/lc0152_maximum_product_subarray.h"

using namespace std;

class TEST_LC0152 : public testing::Test {
protected:
    LC00152_MaximumProductSubarray m_test;
    void RunTest(vector<int>& nums, int expectResult);
};

void TEST_LC0152::RunTest(vector<int>& nums, int expectResult)
{
    EXPECT_EQ(expectResult, m_test.maxProduct(nums));
}

TEST_F(TEST_LC0152, case1)
{
    vector<int> nums = {2, 3, -2, 4};
    RunTest(nums, 6);
}

TEST_F(TEST_LC0152, case2)
{
    vector<int> nums = {-2, 0, -1};
    RunTest(nums, 0);
}
