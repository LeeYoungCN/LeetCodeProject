/*
 * Time : 2025-06-03 00:02:53
 * URL  :
 * https://leetcode.cn/problems/maximum-candies-you-can-get-from-boxes/description/?envType=daily-questionURL_STRenvId=2025-06-03
 */
#include "lc1298_maximum_candies_you_can_get_from_boxes.h"

#include <cstdint>
#include <queue>
#include <vector>

using namespace std;

int LC1298_MaximumCandiesYouCanGetFromBoxes::maxCandies(std::vector<int>& status, std::vector<int>& candies,
                                                        std::vector<std::vector<int>>& keys,
                                                        std::vector<std::vector<int>>& containedBoxes,
                                                        std::vector<int>& initialBoxes)
{
    const int32_t OPEN = 1;
    const int32_t CLOSE = 0;

    const uint32_t boxCnt = (uint32_t)status.size();

    vector<bool> noKeyBox(boxCnt, false);
    queue<int32_t> boxQueue;
    for (int32_t box : initialBoxes) {
        boxQueue.push(box);
    }

    int32_t ans = 0;
    while (!boxQueue.empty()) {
        int currBox = boxQueue.front();
        boxQueue.pop();

        if (status[(uint32_t)currBox] == CLOSE) {
            noKeyBox[(uint32_t)currBox] = true;
            continue;
        }

        ans += candies[(uint32_t)currBox];
        for (int32_t box : containedBoxes[(uint32_t)currBox]) {
            boxQueue.push(box);
        }

        for (int32_t boxKey : keys[(uint32_t)currBox]) {
            status[(uint32_t)boxKey] = OPEN;
            if (noKeyBox[(uint32_t)boxKey]) {
                noKeyBox[(uint32_t)boxKey] = false;
                boxQueue.push(boxKey);
            }
        }
    }

    return ans;
}
