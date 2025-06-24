/*
 * Time : 2025-06-24 11:06:59
 * URL  : https://leetcode.cn/problems/pascals-triangle/?envType=problem-list-v2&envId=dynamic-programming
 */

#include <cstdint>
#include <vector>

#include "gtest/gtest.h"
#include "lc0118_pascals_triangle.h"

using namespace std;

class TEST_LC0118 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0118_PascalsTriangle *> m_testList;
    void RunTest(int numRows, const std::vector<std::vector<int>> &expect);
};

void TEST_LC0118::SetUp()
{
    m_testList.push_back(new LC0118_PascalsTriangle());
}

void TEST_LC0118::TearDown()
{
    for (LC0118_PascalsTriangle *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0118::RunTest(int numRows, const std::vector<std::vector<int>> &expect)
{
    for (LC0118_PascalsTriangle *inst : m_testList) {
        std::vector<std::vector<int>> result = inst->generate(numRows);
        ASSERT_EQ(expect.size(), result.size());
        for (uint32_t i = 0; i < expect.size(); ++i) {
            ASSERT_EQ(expect[i].size(), result[i].size());
            for (uint32_t j = 0; j < expect[i].size(); ++j) {
                EXPECT_EQ(expect[i][j], result[i][j]);
            }
        }
    }
}

TEST_F(TEST_LC0118, case1)
{
    int numRows = 5;
    const std::vector<std::vector<int>> expect = {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
    RunTest(numRows, expect);
}

TEST_F(TEST_LC0118, case2)
{
    int numRows = 1;
    const std::vector<std::vector<int>> expect = {{1}};
    RunTest(numRows, expect);
}
