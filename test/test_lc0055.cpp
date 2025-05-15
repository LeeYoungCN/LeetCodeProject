// https://leetcode.cn/problems/jump-game/
#include <vector>
#include "gtest/gtest.h"
#include "lc0055_jump_game.h"

using namespace std;


class Test_Lc0055 : public testing::Test {
protected:
    Lc0055Solution m_test;
    void RunTest(vector<int> &nums, bool expectResult)
    {
        bool result = m_test.canJump(nums);
        EXPECT_EQ(result, expectResult);
    }
};

TEST_F(Test_Lc0055, Case1)
{
    vector<int> nums = {2, 3, 1, 1, 4};
    RunTest(nums, true);
}
