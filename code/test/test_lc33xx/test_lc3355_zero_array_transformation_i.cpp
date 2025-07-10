/*
 * Time : 2025-05-20 00:24:41
 * URL  :
 * https://leetcode.cn/problems/zero-array-transformation-i/description/?envType=daily-questionURL_STRenvId=2025-05-20
 */

#include <vector>

#include "gtest/gtest.h"
#include "lc33xx/lc3355_zero_array_transformation_i.h"

using namespace std;

class TEST_LC3355 : public testing::Test {
protected:
    LC3355_ZeroArrayTransformationI m_test;
};

TEST_F(TEST_LC3355, case1)
{
    vector<int> nums = {1, 0, 1};
    vector<vector<int>> queries = {{0, 2}};
    EXPECT_TRUE(m_test.isZeroArray(nums, queries));
}

TEST_F(TEST_LC3355, case2)
{
    vector<int> nums = {4, 3, 2, 1};
    vector<vector<int>> queries = {{1, 3}, {0, 2}};
    EXPECT_FALSE(m_test.isZeroArray(nums, queries));
}
