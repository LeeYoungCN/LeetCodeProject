/*
 * Time : 2025-05-20 16:31:20
 * URL  : https://leetcode.cn/problems/jump-game/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc00xx/lc0055_jump_game.h"

using namespace std;

class TEST_LC0055 : public testing::Test {
protected:
    LC0055_JumpGame m_test;
    void RunTest(vector<int> &nums, bool expectResult)
    {
        bool result = m_test.canJump(nums);
        EXPECT_EQ(result, expectResult);
    }
};

TEST_F(TEST_LC0055, case1)
{
    vector<int> nums = {2, 3, 1, 1, 4};
    RunTest(nums, true);
}

TEST_F(TEST_LC0055, case2)
{
    vector<int> nums = {3, 2, 1, 0, 4};
    RunTest(nums, false);
}
