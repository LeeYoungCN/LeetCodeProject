/*
 * Time : 2025-07-09 10:20:38
 * URL  :
 * https://leetcode.cn/problems/reschedule-meetings-for-maximum-free-time-i/description/?envType=daily-question&envId=2025-07-09
 */
#include "lc34xx/lc3439_reschedule_meetings_for_maximum_free_time_i.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

using namespace std;

int32_t LC3439_RescheduleMeetingsForMaximumFreeTimeI::maxFreeTime(int32_t eventTime, int32_t k,
                                                                  std::vector<int32_t>& startTime,
                                                                  std::vector<int32_t>& endTime)
{
    int32_t ans = 0;
    vector<int32_t> deltaArray;
    deltaArray.reserve(startTime.size() + 1);
    for (size_t i = 0; i <= startTime.size(); i++) {
        if (i == 0) {
            deltaArray.push_back(startTime[i]);
        } else if (i == startTime.size()) {
            deltaArray.push_back(eventTime - endTime[i - 1]);
        } else {
            deltaArray.push_back(startTime[i] - endTime[i - 1]);
        }
    }

    int32_t preSum = 0;
    for (size_t i = 0; i < deltaArray.size(); i++) {
        preSum += deltaArray[i];
        if (i >= static_cast<size_t>(k)) {
            ans = max(ans, preSum);
            preSum -= deltaArray[i - static_cast<size_t>(k)];
        }
    }

    return ans;
}
