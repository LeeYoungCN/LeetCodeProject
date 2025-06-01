/*
 * Time : 2025-06-01 16:15:58
 * URL  :
 * https://leetcode.cn/problems/distribute-candies-among-children-ii/?envType=daily-questionURL_STRenvId=2025-06-01
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc2929_distribute_candies_among_children_ii.h"

using namespace std;

class TEST_LC2929 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2929_DistributeCandiesAmongChildrenII *> m_testList;
    void RunTest(int n, int limit, long long expect);
};

void TEST_LC2929::SetUp()
{
    m_testList.push_back(new LC2929_DistributeCandiesAmongChildrenII());
}

void TEST_LC2929::TearDown()
{
    for (LC2929_DistributeCandiesAmongChildrenII *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2929::RunTest(int n, int limit, long long expect)
{
    for (LC2929_DistributeCandiesAmongChildrenII *inst : m_testList) {
        EXPECT_EQ(expect, inst->distributeCandies(n, limit));
    }
}

TEST_F(TEST_LC2929, case1)
{
    int n = 5;
    int limit = 2;
    long long expect = 3;
    RunTest(n, limit, expect);
}

TEST_F(TEST_LC2929, case2)
{
    int n = 3;
    int limit = 3;
    long long expect = 10;
    RunTest(n, limit, expect);
}
