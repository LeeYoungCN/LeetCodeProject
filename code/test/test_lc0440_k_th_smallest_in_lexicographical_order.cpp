/*
 * Time : 2025-06-09 00:44:38
 * URL  :
 * https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/description/?envType=daily-questionURL_STRenvId=2025-06-09
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc0440_k_th_smallest_in_lexicographical_order.h"

using namespace std;

class TEST_LC0440 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0440_KThSmallestInLexicographicalOrder *> m_testList;
    void RunTest(int n, int k, int expect);
};

void TEST_LC0440::SetUp()
{
    m_testList.push_back(new LC0440_KThSmallestInLexicographicalOrder());
}

void TEST_LC0440::TearDown()
{
    for (LC0440_KThSmallestInLexicographicalOrder *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0440::RunTest(int n, int k, int expect)
{
    for (LC0440_KThSmallestInLexicographicalOrder *inst : m_testList) {
        int result = inst->findKthNumber(n, k);
        EXPECT_EQ(expect, result) << "n = " << n << ", k = " << k;
    }
}

TEST_F(TEST_LC0440, case1)
{
    int n = 13;
    int k = 2;
    int expect = 10;
    RunTest(n, k, expect);
}

TEST_F(TEST_LC0440, case2)
{
    int n = 1;
    int k = 1;
    int expect = 1;
    RunTest(n, k, expect);
}

TEST_F(TEST_LC0440, case3)
{
    int n = 10;
    int k = 3;
    int expect = 2;
    RunTest(n, k, expect);
}

TEST_F(TEST_LC0440, case4)
{
    int n = 957747794;
    int k = 424238336;
    int expect = 481814499;
    RunTest(n, k, expect);
}

TEST_F(TEST_LC0440, case5)
{
    int n = 783368691;
    int k = 319151369;
    int expect = 387236228;
    RunTest(n, k, expect);
}
