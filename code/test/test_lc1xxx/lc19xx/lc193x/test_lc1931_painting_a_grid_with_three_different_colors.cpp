/*
 * Time : 2025-05-30 22:54:18
 * URL  :
 * https://leetcode.cn/problems/painting-a-grid-with-three-different-colors/description/?envType=daily-questionURL_STRenvId=2025-05-18
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc1xxx/lc19xx/lc193x/lc1931_painting_a_grid_with_three_different_colors.h"

using namespace std;

class TEST_LC1931 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1931_PaintingAGridWithThreeDifferentColors *> m_testList;
    void RunTest(int m, int n, int expect);
};

void TEST_LC1931::SetUp()
{
    m_testList.push_back(new LC1931_PaintingAGridWithThreeDifferentColors_Number());
    m_testList.push_back(new LC1931_PaintingAGridWithThreeDifferentColors_Grid());
}

void TEST_LC1931::TearDown()
{
    for (LC1931_PaintingAGridWithThreeDifferentColors *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC1931::RunTest(int m, int n, int expect)
{
    for (LC1931_PaintingAGridWithThreeDifferentColors *inst : m_testList) {
        EXPECT_EQ(expect, inst->colorTheGrid(m, n));
    }
}

TEST_F(TEST_LC1931, 1X2)
{
    RunTest(1, 2, 6);
}

TEST_F(TEST_LC1931, 1X1)
{
    RunTest(1, 1, 3);
}

TEST_F(TEST_LC1931, 5X5)
{
    RunTest(5, 5, 580986);
}

TEST_F(TEST_LC1931, 2X2)
{
    RunTest(2, 2, 18);
}

TEST_F(TEST_LC1931, 3X3)
{
    RunTest(3, 3, 246);
}
