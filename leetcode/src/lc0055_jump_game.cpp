/*
 * Time     : 2025-05-20 16:31:20
 * URL      : https://leetcode.cn/problems/jump-game/
 * Problem  : 给你一个非负整数数组 nums ，你最初位于数组的第一个下标
 * 。数组中的每个元素代表你在该位置可以跳跃的最大长度。 判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回
 * false 。
 */
#include "lc0055_jump_game.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

bool LC0055_JumpGame::canJump(std::vector<int>& nums)
{
    uint32_t distance = nums.size();
    uint32_t currMaxDistance = nums[0];
    for (uint32_t i = 0; i < distance; i++) {
        if (i > currMaxDistance) {
            return false;
        }
        currMaxDistance = max(currMaxDistance, nums[i] + i);
        if (currMaxDistance >= distance - 1) {
            return true;
        }
    }
    return false;
}
