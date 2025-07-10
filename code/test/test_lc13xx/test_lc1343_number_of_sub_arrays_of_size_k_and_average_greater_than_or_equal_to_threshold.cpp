/*
 * Time : 2025-05-31 22:32:25
 * URL  :
 * https://leetcode.cn/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc13xx/lc1343_number_of_sub_arrays_of_size_k_and_average_greater_than_or_equal_to_threshold.h"

using namespace std;

class TEST_LC1343 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1343_NumberOfSubArraysOfSizeKAndAverageGreaterThanOrEqualToThreshold *> m_testList;
    void RunTest(vector<int> &arr, int k, int threshold, int expect);
};

void TEST_LC1343::SetUp()
{
    m_testList.push_back(new LC1343_NumberOfSubArraysOfSizeKAndAverageGreaterThanOrEqualToThreshold());
}

void TEST_LC1343::TearDown()
{
    for (LC1343_NumberOfSubArraysOfSizeKAndAverageGreaterThanOrEqualToThreshold *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC1343::RunTest(vector<int> &arr, int k, int threshold, int expect)
{
    for (LC1343_NumberOfSubArraysOfSizeKAndAverageGreaterThanOrEqualToThreshold *inst : m_testList) {
        EXPECT_EQ(expect, inst->numOfSubarrays(arr, k, threshold));
    }
}

TEST_F(TEST_LC1343, case1)
{
    vector<int> arr = {2, 2, 2, 2, 5, 5, 5, 8};
    int k = 3;
    int threshold = 4;
    int expect = 3;
    RunTest(arr, k, threshold, expect);
}

TEST_F(TEST_LC1343, case3)
{
    vector<int> arr = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
    int k = 3;
    int threshold = 5;
    int expect = 6;
    RunTest(arr, k, threshold, expect);
}
