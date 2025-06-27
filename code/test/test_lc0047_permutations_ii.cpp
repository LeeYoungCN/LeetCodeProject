/*
 * Time : 2025-06-27 17:05:51
 * URL  : https://leetcode.cn/problems/permutations-ii/description/
 */
#include <algorithm>
#include <cstdint>
#include <vector>

#include "gtest/gtest.h"
#include "lc0047_permutations_ii.h"

using namespace std;

class TEST_LC0047 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0047_PermutationsII*> m_testList;
    void RunTest(std::vector<int>& nums, std::vector<std::vector<int>>& expect);
};

void TEST_LC0047::SetUp()
{
    m_testList.push_back(new LC0047_PermutationsII());
}

void TEST_LC0047::TearDown()
{
    for (LC0047_PermutationsII* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0047::RunTest(std::vector<int>& nums, std::vector<std::vector<int>>& expect)
{
    for (LC0047_PermutationsII* inst : m_testList) {
        std::vector<std::vector<int>> result = inst->permuteUnique(nums);
        ASSERT_EQ(result.size(), expect.size());
        ranges::sort(result);
        ranges::sort(expect);
        for (uint32_t i = 0; i < expect.size(); i++) {
            for (uint32_t j = 0; j < expect[i].size(); ++j) {
                EXPECT_EQ(expect[i][j], result[i][j]);
            }
        }
    }
}

TEST_F(TEST_LC0047, case1)
{
    std::vector<int> nums = {1, 1, 2};
    std::vector<std::vector<int>> expect = {{1, 1, 2}, {1, 2, 1}, {2, 1, 1}};
    RunTest(nums, expect);
}

TEST_F(TEST_LC0047, case2)
{
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> expect = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    RunTest(nums, expect);
}
