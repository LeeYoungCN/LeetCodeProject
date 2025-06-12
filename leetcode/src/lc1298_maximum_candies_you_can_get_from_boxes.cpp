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

namespace {
constexpr int32_t OPEN = 1;
constexpr int32_t CLOSE = 0;
}  // namespace

int LC1298_MaximumCandiesYouCanGetFromBoxes::maxCandies(std::vector<int>& status, std::vector<int>& candies,
                                                        std::vector<std::vector<int>>& keys,
                                                        std::vector<std::vector<int>>& containedBoxes,
                                                        std::vector<int>& initialBoxes)
{
    const auto boxCnt = static_cast<uint32_t>(status.size());

    vector<bool> noKeyBox(boxCnt, false);
    queue<int32_t> boxQueue;
    for (int32_t box : initialBoxes) {
        boxQueue.push(box);
    }

    int32_t ans = 0;
    while (!boxQueue.empty()) {
        int currBox = boxQueue.front();
        boxQueue.pop();

        if (status[static_cast<uint32_t>(currBox)] == CLOSE) {
            noKeyBox[static_cast<uint32_t>(currBox)] = true;
            continue;
        }

        ans += candies[static_cast<uint32_t>(currBox)];
        for (const int32_t box : containedBoxes[static_cast<uint32_t>(currBox)]) {
            boxQueue.push(box);
        }

        for (const int32_t boxKey : keys[static_cast<uint32_t>(currBox)]) {
            status[static_cast<uint32_t>(boxKey)] = OPEN;
            if (noKeyBox[static_cast<uint32_t>(boxKey)]) {
                noKeyBox[static_cast<uint32_t>(boxKey)] = false;
                boxQueue.push(boxKey);
            }
        }
    }

    return ans;
}
