/*
 * Time : 2025-06-20 00:23:10
 * URL  : https://leetcode.cn/problems/partition-array-such-that-maximum-difference-is-k/description/
 */

#include <vector>

#include "gtest/gtest.h"
#include "lc22xx/lc2294_partition_array_such_that_maximum_difference_is_k.h"

using namespace std;

class TEST_LC2294 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2294_PartitionArraySuchThatMaximumDifferenceIsK*> m_testList;
    void RunTest(vector<int>& nums, int k, const int& expect);
};

void TEST_LC2294::SetUp()
{
    m_testList.push_back(new LC2294_PartitionArraySuchThatMaximumDifferenceIsK());
}

void TEST_LC2294::TearDown()
{
    for (LC2294_PartitionArraySuchThatMaximumDifferenceIsK* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2294::RunTest(vector<int>& nums, int k, const int& expect)
{
    for (LC2294_PartitionArraySuchThatMaximumDifferenceIsK* inst : m_testList) {
        int result = inst->partitionArray(nums, k);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC2294, case1)
{
    vector<int> nums = {3, 6, 1, 2, 5};
    int k = 2;
    const int expect = 2;
    RunTest(nums, k, expect);
}

TEST_F(TEST_LC2294, case2)
{
    vector<int> nums = {1, 2, 3};
    int k = 1;
    const int expect = 2;
    RunTest(nums, k, expect);
}

TEST_F(TEST_LC2294, case3)
{
    vector<int> nums = {2, 2, 4, 5};
    int k = 0;
    const int expect = 3;
    RunTest(nums, k, expect);
}
