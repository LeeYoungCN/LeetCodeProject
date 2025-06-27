/*
 * Time : 2025-06-28 00:18:24
 * URL  :
 * https://leetcode.cn/problems/find-subsequence-of-length-k-with-the-largest-sum/?envType=daily-question&envId=2025-06-28
 */
#include <cstdint>
#include <vector>

#include "gtest/gtest.h"
#include "lc2099_find_subsequence_of_length_k_with_the_largest_sum.h"

using namespace std;

class TEST_LC2099 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2099_FindSubsequenceOfLengthKWithTheLargestSum*> m_testList;
    void RunTest(std::vector<int>& nums, int k, const std::vector<int>& expect);
};

void TEST_LC2099::SetUp()
{
    m_testList.push_back(new LC2099_FindSubsequenceOfLengthKWithTheLargestSum());
}

void TEST_LC2099::TearDown()
{
    for (LC2099_FindSubsequenceOfLengthKWithTheLargestSum* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2099::RunTest(std::vector<int>& nums, int k, const std::vector<int>& expect)
{
    for (LC2099_FindSubsequenceOfLengthKWithTheLargestSum* inst : m_testList) {
        std::vector<int> result = inst->maxSubsequence(nums, k);
        ASSERT_EQ(expect.size(), result.size());
        for (uint32_t i = 0; i < expect.size(); ++i) {
            EXPECT_EQ(expect[i], result[i]);
        }
    }
}

TEST_F(TEST_LC2099, case1)
{
    std::vector<int> nums{2, 1, 3, 3};
    int k = 2;
    const std::vector<int> expect = {3, 3};
    RunTest(nums, k, expect);
}

TEST_F(TEST_LC2099, case2)
{
    std::vector<int> nums{-1, -2, 3, 4};
    int k = 3;
    const std::vector<int> expect = {-1, 3, 4};
    RunTest(nums, k, expect);
}
