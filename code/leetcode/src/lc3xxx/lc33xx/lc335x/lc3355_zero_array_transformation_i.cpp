/*
 * Time : 2025-05-20 00:40:44
 * URL  :
 * https://leetcode.cn/problems/zero-array-transformation-i/description/?envType=daily-questionURL_STRenvId=2025-05-20
 */

#include "lc3xxx/lc33xx/lc335x/lc3355_zero_array_transformation_i.h"

#include <cstdint>
#include <vector>

using namespace std;

bool LC3355_ZeroArrayTransformationI::isZeroArray(vector<int>& nums, vector<vector<int>>& queries)
{
    vector<int32_t> deltaArray(nums.size() + 1, 0);
    for (const vector<int>& query : queries) {
        const auto left = static_cast<uint32_t>(query[0]);
        const auto right = static_cast<uint32_t>(query[1]);
        deltaArray[left] += 1;
        deltaArray[right + 1] -= 1;
    }
    int32_t currOperNum = 0;
    for (uint32_t i = 0; i < nums.size(); ++i) {
        currOperNum += deltaArray[i];
        if (currOperNum < nums[i]) {
            return false;
        }
    }
    return true;
}
