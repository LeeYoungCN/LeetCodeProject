/*
 * Time : 2025-06-01 23:45:39
 * URL  : https://leetcode.cn/problems/reduce-array-size-to-the-half/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc13xx/lc1338_reduce_array_size_to_the_half.h"

using namespace std;

class TEST_LC1338 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1338_ReduceArraySizeToTheHalf *> m_testList;
    void RunTest(std::vector<int> &arr, int expect);
};

void TEST_LC1338::SetUp()
{
    m_testList.push_back(new LC1338_ReduceArraySizeToTheHalf());
}

void TEST_LC1338::TearDown()
{
    for (LC1338_ReduceArraySizeToTheHalf *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC1338::RunTest(std::vector<int> &arr, int expect)
{
    for (LC1338_ReduceArraySizeToTheHalf *inst : m_testList) {
        EXPECT_EQ(expect, inst->minSetSize(arr));
    }
}

TEST_F(TEST_LC1338, case1)
{
    std::vector<int> arr = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};

    int expect = 2;
    RunTest(arr, expect);
}

TEST_F(TEST_LC1338, case2)
{
    std::vector<int> arr = {7, 7, 7, 7, 7, 7};

    int expect = 1;
    RunTest(arr, expect);
}
