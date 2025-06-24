/*
 * Time : 2025-06-24 11:50:45
 * URL  : https://leetcode.cn/problems/triangle/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc0120_triangle.h"

using namespace std;

class TEST_LC0120 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0120_Triangle*> m_testList;
    void RunTest(std::vector<std::vector<int>>& triangle, const int& expect);
};

void TEST_LC0120::SetUp()
{
    m_testList.push_back(new LC0120_Triangle());
}

void TEST_LC0120::TearDown()
{
    for (LC0120_Triangle* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0120::RunTest(std::vector<std::vector<int>>& triangle, const int& expect)
{
    for (LC0120_Triangle* inst : m_testList) {
        int result = inst->minimumTotal(triangle);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC0120, case1)
{
    std::vector<std::vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    const int expect = 11;
    RunTest(triangle, expect);
}

TEST_F(TEST_LC0120, case2)
{
    std::vector<std::vector<int>> triangle = {{-10}};
    const int expect = -10;
    RunTest(triangle, expect);
}
