// https://leetcode.cn/problems/painting-a-grid-with-three-different-colors/description/?envType=daily-questionURL_STRenvId=2025-05-18
#include <vector>
#include "gtest/gtest.h"
#include "lc1931_painting_a_grid_with_three_different_colors.h"

using namespace std;

class Test_Lc1931 : public testing::Test {
    protected:
        Lc1931_PaintingAGridWithThreeDifferentColors m_test;
        void RunTest(int m, int n, int result);
};

void Test_Lc1931::RunTest(int m, int n, int result)
{
    EXPECT_EQ(result, m_test.colorTheGrid(m, n));
}

TEST_F(Test_Lc1931, case1)
{
    RunTest(1, 2, 6);
}

TEST_F(Test_Lc1931, case2)
{
    RunTest(1, 1, 3);
}

TEST_F(Test_Lc1931, case3)
{
    RunTest(5, 5, 580986);
}

TEST_F(Test_Lc1931, case4)
{
    RunTest(2, 2, 18);
}

TEST_F(Test_Lc1931, case5)
{
    RunTest(3, 3, 246);
}
