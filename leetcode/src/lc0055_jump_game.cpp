// https://leetcode.cn/problems/jump-game/
#include <cstdint>
#include <vector>
#include "lc0055_jump_game.h"

using namespace std;


bool LC0055Solution::canJump(vector<int>& nums) {
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

