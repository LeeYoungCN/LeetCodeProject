/*
 * Time : 2025-06-01 20:38:27
 * URL  : https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/description/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc1xxx/lc14xx/lc142x/lc1423_maximum_points_you_can_obtain_from_cards.h"

using namespace std;

class TEST_LC1423 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1423_MaximumPointsYouCanObtainFromCards *> m_testList;
    void RunTest(vector<int> &cardPoints, int k, int expect);
};

void TEST_LC1423::SetUp()
{
    m_testList.push_back(new LC1423_MaximumPointsYouCanObtainFromCards());
}

void TEST_LC1423::TearDown()
{
    for (LC1423_MaximumPointsYouCanObtainFromCards *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC1423::RunTest(vector<int> &cardPoints, int k, int expect)
{
    for (LC1423_MaximumPointsYouCanObtainFromCards *inst : m_testList) {
        EXPECT_EQ(expect, inst->maxScore(cardPoints, k));
    }
}

TEST_F(TEST_LC1423, case1)
{
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    int expect = 12;
    RunTest(cardPoints, k, expect);
}

TEST_F(TEST_LC1423, case2)
{
    vector<int> cardPoints = {2, 2, 2};
    int k = 2;
    int expect = 4;
    RunTest(cardPoints, k, expect);
}

TEST_F(TEST_LC1423, case3)
{
    vector<int> cardPoints = {9, 7, 7, 9, 7, 7, 9};
    int k = 7;
    int expect = 55;
    RunTest(cardPoints, k, expect);
}

TEST_F(TEST_LC1423, case4)
{
    vector<int> cardPoints = {1, 1000, 1};
    int k = 1;
    int expect = 1;
    RunTest(cardPoints, k, expect);
}
TEST_F(TEST_LC1423, case5)
{
    vector<int> cardPoints = {1, 79, 80, 1, 1, 1, 200, 1};
    int k = 3;
    int expect = 202;
    RunTest(cardPoints, k, expect);
}
