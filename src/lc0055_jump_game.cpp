// https://leetcode.cn/problems/jump-game/
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int size = nums.size();
        vector<int> maxDistance = vector<int>(size);
        for (int i = 0; i < size; ++i) {
            if (i == 0) {
                maxDistance[i] = nums[i];
            } else {
                maxDistance[i] = max(maxDistance[i - 1], nums[i] + i);
            }
            if (maxDistance[i] >= size - 1) {
                return true;
            } else if (maxDistance[i] <= i) {
                return false;
            }
        }
        return false;
    }
};

class Test_Lc0055 : public testing::Test {
protected:
    Solution m_test;
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
