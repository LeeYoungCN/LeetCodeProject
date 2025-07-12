/*
 * Time : 2025-06-01 21:43:59
 * URL  : https://leetcode.cn/problems/apple-redistribution-into-boxes/description/
 */
#include "lc3xxx/lc30xx/lc307x/lc3074_apple_redistribution_into_boxes.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

int LC3074_AppleRedistributionIntoBoxes::minimumBoxes(vector<int>& apple, vector<int>& capacity)
{
    int32_t appleCnt = accumulate(apple.begin(), apple.end(), 0);
    sort(capacity.begin(), capacity.end(), greater());

    for (size_t i = 0; i < capacity.size(); i++) {
        appleCnt -= capacity[i];
        if (appleCnt <= 0) {
            return static_cast<int32_t>(i) + 1;
        }
    }

    return static_cast<int32_t>(capacity.size());
}
