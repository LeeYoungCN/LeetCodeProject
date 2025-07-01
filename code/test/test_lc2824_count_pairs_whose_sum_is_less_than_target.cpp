/*
 * Time : 2025-06-29 14:38:01
 * URL  : https://leetcode.cn/problems/count-pairs-whose-sum-is-less-than-target/description/
 */

#include <cstdint>
#include <vector>

#include "gtest/gtest.h"
#include "lc2824_count_pairs_whose_sum_is_less_than_target.h"
#include "leetcode_utils.hpp"

using namespace std;

class TEST_LC2824 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2824_CountPairsWhoseSumIsLessThanTarget*> m_testList;
    void RunTest(std::vector<int32_t>& nums, int32_t target, const int32_t& expect);
};

void TEST_LC2824::SetUp()
{
    m_testList.push_back(new LC2824_CountPairsWhoseSumIsLessThanTarget_Enum());
    m_testList.push_back(new LC2824_CountPairsWhoseSumIsLessThanTarget_Find());
    m_testList.push_back(new LC2824_CountPairsWhoseSumIsLessThanTarget_DoublePtr());
}

void TEST_LC2824::TearDown()
{
    for (LC2824_CountPairsWhoseSumIsLessThanTarget* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2824::RunTest(std::vector<int32_t>& nums, int32_t target, const int32_t& expect)
{
    for (LC2824_CountPairsWhoseSumIsLessThanTarget* inst : m_testList) {
        int32_t result = inst->countPairs(nums, target);
        EXPECT_EQ(expect, result) << "nums = " << Vector2String(nums) << endl << "target = " << target;
    }
}

TEST_F(TEST_LC2824, case1)
{
    std::vector<int32_t> nums = {-1, 1, 2, 3, 1};
    int32_t target = 2;
    const int32_t expect = 3;
    RunTest(nums, target, expect);
}

TEST_F(TEST_LC2824, case2)
{
    std::vector<int32_t> nums = {-6, 2, 5, -2, -7, -1, 3};
    int32_t target = -2;
    const int32_t expect = 10;
    RunTest(nums, target, expect);
}
