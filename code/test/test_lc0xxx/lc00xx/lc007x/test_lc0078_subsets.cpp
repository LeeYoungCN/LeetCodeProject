/*
 * Time : 2025-07-05 17:33:28
 * URL  : https://leetcode.cn/problems/subsets/description/
 */
#include <algorithm>
#include <cstdint>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc00xx/lc007x/lc0078_subsets.h"
#include "leetcode_utils_vector.hpp"

using namespace std;

class TEST_LC0078 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0078_Subsets*> m_testList;
    void RunTest(std::vector<int32_t>& nums, std::vector<std::vector<int32_t>>& expect);
};

void TEST_LC0078::SetUp()
{
    m_testList.push_back(new LC0078_Subsets_Enum());
    m_testList.push_back(new LC0078_Subsets_DFS());
}

void TEST_LC0078::TearDown()
{
    for (LC0078_Subsets* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0078::RunTest(std::vector<int32_t>& nums, std::vector<std::vector<int32_t>>& expect)
{
    for (LC0078_Subsets* inst : m_testList) {
        std::vector<std::vector<int32_t>> result = inst->subsets(nums);
        ASSERT_EQ(expect.size(), result.size());
        sort(expect.begin(), expect.end());
        sort(result.begin(), result.end());
        for (uint32_t i = 0; i < expect.size(); ++i) {
            ASSERT_EQ(expect[i].size(), result[i].size());
            for (uint32_t j = 0; j < expect[i].size(); ++j) {
                EXPECT_EQ(expect[i][j], result[i][j]);
            }
        }
    }
}

TEST_F(TEST_LC0078, case1)
{
    std::vector<int32_t> nums = String2VecInt("[1,2,3]");
    std::vector<std::vector<int32_t>> expect = String2MatrixInt("[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]");
    RunTest(nums, expect);
}

TEST_F(TEST_LC0078, case2)
{
    std::vector<int32_t> nums = String2VecInt("[0]");
    std::vector<std::vector<int32_t>> expect = String2MatrixInt("[[],[0]]");
    RunTest(nums, expect);
}
