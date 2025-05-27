/*
 * Time : 2025-05-27 18:47:36
 * URL  : https://leetcode.cn/problems/partition-equal-subset-sum/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc0426_partition_equal_subset_sum.h"

using namespace std;

class TEST_LC0426 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0426_PartitionEqualSubsetSum *> m_testList;
    void RunTest(std::vector<int> &nums, bool expect) const;
};

void TEST_LC0426::SetUp()
{
    m_testList.push_back(new LC0426_PartitionEqualSubsetSum_DP1());
    m_testList.push_back(new LC0426_PartitionEqualSubsetSum_DP2());
}

void TEST_LC0426::TearDown()
{
    for (LC0426_PartitionEqualSubsetSum *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0426::RunTest(std::vector<int> &nums, bool expect) const
{
    for (LC0426_PartitionEqualSubsetSum *inst : m_testList) {
        EXPECT_EQ(expect, inst->canPartition(nums));
    }
}

TEST_F(TEST_LC0426, case1)
{
    vector<int> nums = {1, 5, 11, 5};
    RunTest(nums, true);
}

TEST_F(TEST_LC0426, case2)
{
    vector<int> nums = {1, 2, 3, 5};
    RunTest(nums, false);
}

TEST_F(TEST_LC0426, case3)
{
    vector<int> nums = {1, 1};
    RunTest(nums, true);
}
