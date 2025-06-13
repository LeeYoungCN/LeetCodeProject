/*
 * Time : 2025-06-13 17:39:36
 * URL  : https://leetcode.cn/problems/house-robber-iv/description/
 */
#include "lc2560_house_robber_iv.h"

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <vector>

using namespace std;

int LC2560_HouseRobberIV::minCapability(vector<int> &nums, int k)
{
    int32_t left = *min_element(nums.begin(), nums.end());
    int32_t right = *max_element(nums.begin(), nums.end());

    function getRank = [&](int32_t num) -> int32_t {
        int32_t cnt = 1;
        bool isVisitPre = false;
        for (const int32_t n : nums) {
            if (!isVisitPre && n <= num) {
                cnt++;
                isVisitPre = true;
            } else {
                isVisitPre = false;
            }
        }
        return cnt;
    };

    while (left < right) {
        int32_t curr = (left + right) / 2;
        int32_t rank = getRank(curr);

        if (rank > k) {
            right = curr;
        } else {
            left = curr + 1;
        }
    }
    return left;
}
