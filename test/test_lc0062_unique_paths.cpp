/*
 * Time : 2025-06-20 16:59:36
 * URL  : https://leetcode.cn/problems/unique-paths/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc0062_unique_paths.h"

using namespace std;

class TEST_LC0062 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0062_UniquePaths *> m_testList;
    void RunTest(int m, int n, const int &expect);
};

void TEST_LC0062::SetUp()
{
    m_testList.push_back(new LC0062_UniquePaths());
}

void TEST_LC0062::TearDown()
{
    for (LC0062_UniquePaths *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0062::RunTest(int m, int n, const int &expect)
{
    for (LC0062_UniquePaths *inst : m_testList) {
        int result = inst->uniquePaths(m, n);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC0062, case1)
{
    int m = 3;
    int n = 7;
    const int expect = 28;
    RunTest(m, n, expect);
}

TEST_F(TEST_LC0062, case2)
{
    int m = 3;
    int n = 2;
    const int expect = 3;
    RunTest(m, n, expect);
}

TEST_F(TEST_LC0062, case3)
{
    int m = 7;
    int n = 3;
    const int expect = 28;
    RunTest(m, n, expect);
}

TEST_F(TEST_LC0062, case4)
{
    int m = 3;
    int n = 3;
    const int expect = 6;
    RunTest(m, n, expect);
}
