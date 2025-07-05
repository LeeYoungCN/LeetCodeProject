/*
 * Time : 2025-06-29 18:45:48
 * URL  : https://leetcode.cn/problems/combination-sum/
 */
#include <algorithm>
#include <cstdint>
#include <vector>

#include "gtest/gtest.h"
#include "lc0039_combination_sum.h"

using namespace std;

class TEST_LC0039 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0039_CombinationSum*> m_testList;
    void RunTest(std::vector<int32_t>& candidates, int32_t target, std::vector<std::vector<int32_t>>& expect);
};

void TEST_LC0039::SetUp()
{
    m_testList.push_back(new LC0039_CombinationSum_DFS());
    m_testList.push_back(new LC0039_CombinationSum_Stack());
}

void TEST_LC0039::TearDown()
{
    for (LC0039_CombinationSum* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0039::RunTest(std::vector<int32_t>& candidates, int32_t target, std::vector<std::vector<int32_t>>& expect)
{
    for (LC0039_CombinationSum* inst : m_testList) {
        std::vector<std::vector<int32_t>> result = inst->combinationSum(candidates, target);
        ASSERT_EQ(expect.size(), result.size());
        sort(expect.begin(), expect.end());
        sort(result.begin(), result.end());
        for (uint32_t i = 0; i < expect.size(); ++i) {
            ASSERT_EQ(expect.at(i).size(), result.at(i).size());
            sort(expect.at(i).begin(), expect.at(i).end());
            sort(result.at(i).begin(), result.at(i).end());
            for (uint32_t j = 0; j < expect.at(i).size(); ++j) {
                EXPECT_EQ(expect.at(i).at(j), result.at(i).at(j));
            }
        }
    }
}

TEST_F(TEST_LC0039, case1)
{
    std::vector<int32_t> candidates = {2, 3, 6, 7};
    int32_t target = 7;
    std::vector<std::vector<int32_t>> expect = {{2, 2, 3}, {7}};
    RunTest(candidates, target, expect);
}

TEST_F(TEST_LC0039, case2)
{
    std::vector<int32_t> candidates = {2, 3, 5};
    int32_t target = 8;
    std::vector<std::vector<int32_t>> expect = {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}};
    RunTest(candidates, target, expect);
}

TEST_F(TEST_LC0039, case3)
{
    std::vector<int32_t> candidates = {2};
    int32_t target = 1;
    std::vector<std::vector<int32_t>> expect = {};
    RunTest(candidates, target, expect);
}
