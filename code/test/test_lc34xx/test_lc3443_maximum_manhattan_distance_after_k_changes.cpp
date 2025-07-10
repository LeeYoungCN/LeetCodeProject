/*
 * Time : 2025-06-20 00:29:16
 * URL  :
 * https://leetcode.cn/problems/maximum-manhattan-distance-after-k-changes/description/?envType=daily-questionURL_STRenvId=2025-06-20
 */

#include <vector>

#include "gtest/gtest.h"
#include "lc34xx/lc3443_maximum_manhattan_distance_after_k_changes.h"

using namespace std;

class TEST_LC3443 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3443_MaximumManhattanDistanceAfterKChanges *> m_testList;
    void RunTest(string s, int k, const int &expect);
};

void TEST_LC3443::SetUp()
{
    m_testList.push_back(new LC3443_MaximumManhattanDistanceAfterKChanges());
}

void TEST_LC3443::TearDown()
{
    for (LC3443_MaximumManhattanDistanceAfterKChanges *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3443::RunTest(string s, int k, const int &expect)
{
    for (LC3443_MaximumManhattanDistanceAfterKChanges *inst : m_testList) {
        int result = inst->maxDistance(s, k);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC3443, case1)
{
    string s = "NWSE";
    int k = 1;
    const int expect = 3;
    RunTest(s, k, expect);
}

TEST_F(TEST_LC3443, case2)
{
    string s = "NSWWEW";
    int k = 3;
    const int expect = 6;
    RunTest(s, k, expect);
}
