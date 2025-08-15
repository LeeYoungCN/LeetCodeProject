/*
 * Time : 2025-07-13 17:59:31
 * URL  : https://leetcode.cn/problems/combination-sum-ii/description/
 */
#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc00xx/lc004x/lc0040_combination_sum_ii.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC0040 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0040_CombinationSumII*> m_testList;
    void RunTest(std::vector<int32_t>& candidates, int32_t target, std::vector<std::vector<int32_t>>& expect);
};

void TEST_LC0040::SetUp()
{
    m_testList.push_back(new LC0040_CombinationSumII());
}

void TEST_LC0040::TearDown()
{
    for (LC0040_CombinationSumII* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0040::RunTest(std::vector<int32_t>& candidates, int32_t target, std::vector<std::vector<int32_t>>& expect)
{
    for (LC0040_CombinationSumII* inst : m_testList) {
        std::vector<std::vector<int32_t>> result = inst->combinationSum2(candidates, target);
        ASSERT_EQ(result.size(), expect.size());
        sort(expect.begin(), expect.end());
        sort(result.begin(), result.end());
        for (size_t i = 0; i < expect.size(); ++i) {
            ASSERT_EQ(expect[i].size(), expect[i].size());
            sort(expect[i].begin(), expect[i].end());
            sort(result[i].begin(), result[i].end());
            for (size_t j = 0; j < expect[i].size(); ++j) {
                EXPECT_EQ(expect[i][j], result[i][j]);
            }
        }
    }
}

TEST_F(TEST_LC0040, case1)
{
    std::vector<int32_t> candidates = CreateIntVector("[10,1,2,7,6,1,5]");
    int32_t target = 8;
    std::vector<std::vector<int32_t>> expect = CreateIntMatrix("[[1,1,6],[1,2,5],[1,7],[2,6]]");
    RunTest(candidates, target, expect);
}

TEST_F(TEST_LC0040, case2)
{
    std::vector<int32_t> candidates = CreateIntVector("[2,5,2,1,2]");
    int32_t target = 5;
    std::vector<std::vector<int32_t>> expect = CreateIntMatrix("[[1,2,2],[5]]");
    RunTest(candidates, target, expect);
}
