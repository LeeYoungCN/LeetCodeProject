/*
 * Time : 2025-06-27 17:46:05
 * URL  : https://leetcode.cn/problems/permutations/description/
 */
#include <algorithm>
#include <cstdint>
#include <vector>

#include "gtest/gtest.h"
#include "lc00xx/lc0046_permutations.h"

using namespace std;

class TEST_LC0046 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0046_Permutations*> m_testList;
    void RunTest(std::vector<int>& nums, std::vector<std::vector<int>>& expect);
};

void TEST_LC0046::SetUp()
{
    m_testList.push_back(new LC0046_Permutations());
}

void TEST_LC0046::TearDown()
{
    for (LC0046_Permutations* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0046::RunTest(std::vector<int>& nums, std::vector<std::vector<int>>& expect)
{
    for (LC0046_Permutations* inst : m_testList) {
        std::vector<std::vector<int>> result = inst->permute(nums);
        ASSERT_EQ(result.size(), expect.size());
        sort(result.begin(), result.end());
        sort(expect.begin(), expect.end());
        for (uint32_t i = 0; i < expect.size(); i++) {
            for (uint32_t j = 0; j < expect[i].size(); ++j) {
                EXPECT_EQ(expect[i][j], result[i][j]);
            }
        }
    }
}

TEST_F(TEST_LC0046, case1)
{
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> expect = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    RunTest(nums, expect);
}

TEST_F(TEST_LC0046, case2)
{
    std::vector<int> nums = {0, 1};
    std::vector<std::vector<int>> expect = {{0, 1}, {1, 0}};
    RunTest(nums, expect);
}

TEST_F(TEST_LC0046, case3)
{
    std::vector<int> nums = {0};
    std::vector<std::vector<int>> expect = {{0}};
    RunTest(nums, expect);
}
