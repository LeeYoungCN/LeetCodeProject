/*
 * Time : 2025-06-02 00:20:13
 * URL  : https://leetcode.cn/problems/candy/description/?envType=daily-questionURL_STRenvId=2025-06-02
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc0135_candy.h"

using namespace std;

class TEST_LC0135 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0135_Candy *> m_testList;
    void RunTest(std::vector<int> &ratings, int expect);
};

void TEST_LC0135::SetUp()
{
    m_testList.push_back(new LC0135_Candy_Stack());
    m_testList.push_back(new LC0135_Candy_TwoTraverse());
    m_testList.push_back(new LC0135_Candy_OneTraverse());
}

void TEST_LC0135::TearDown()
{
    for (LC0135_Candy *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0135::RunTest(std::vector<int> &ratings, int expect)
{
    for (LC0135_Candy *inst : m_testList) {
        EXPECT_EQ(expect, inst->candy(ratings));
    }
}

TEST_F(TEST_LC0135, case1)
{
    std::vector<int> ratings = {1, 0, 2};

    int expect = 5;
    RunTest(ratings, expect);
}

TEST_F(TEST_LC0135, case2)
{
    std::vector<int> ratings = {1, 2, 2};

    int expect = 4;
    RunTest(ratings, expect);
}

TEST_F(TEST_LC0135, case3)
{
    std::vector<int> ratings = {1, 3, 2, 2, 1};

    int expect = 7;
    RunTest(ratings, expect);
}
