// https://leetcode.cn/problems/jump-game/
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Lc0050 {
public:
    bool canJump(vector<int>& nums) {
        return true;
    }
};

class TestLc0050 : public testing::Test {
protected:
    Lc0050 m_test;
    void RunTest(vector<int> &nums, bool expectResult)
    {
        bool result = m_test.canJump(nums);
        EXPECT_EQ(result, expectResult);
    }
};

TEST_F(TestLc0050, Case1)
{
    vector<int> nums = {2, 3, 1, 1, 4};
    RunTest(nums, true);
}
