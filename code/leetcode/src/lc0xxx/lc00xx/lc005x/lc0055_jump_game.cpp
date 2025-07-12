/*
 * Time : 2025-05-20 16:31:20
 * URL  : https://leetcode.cn/problems/jump-game/
 */
#include "lc0xxx/lc00xx/lc005x/lc0055_jump_game.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

bool LC0055_JumpGame::canJump(std::vector<int>& nums)
{
    auto distance = static_cast<uint32_t>(nums.size());
    auto currMaxDistance = static_cast<uint32_t>(nums[0]);
    for (uint32_t i = 0; i < distance; i++) {
        if (i > currMaxDistance) {
            return false;
        }
        currMaxDistance = max(currMaxDistance, static_cast<uint32_t>(nums[i]) + i);
        if (currMaxDistance >= distance - 1) {
            return true;
        }
    }
    return false;
}
