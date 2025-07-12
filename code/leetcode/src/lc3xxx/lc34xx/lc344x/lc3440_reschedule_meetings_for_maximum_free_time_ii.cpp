/*
 * Time : 2025-07-10 10:54:41
 * URL  :
 * https://leetcode.cn/problems/reschedule-meetings-for-maximum-free-time-ii/description/?envType=daily-question&envId=2025-07-10
 */
#include "lc3xxx/lc34xx/lc344x/lc3440_reschedule_meetings_for_maximum_free_time_ii.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

using namespace std;

int32_t LC3440_RescheduleMeetingsForMaximumFreeTimeII::maxFreeTime(int32_t eventTime, std::vector<int32_t>& startTime,
                                                                   std::vector<int32_t>& endTime)
{
    vector<int32_t> deltaArray(startTime.size() + 1);
    for (size_t i = 0; i <= startTime.size(); ++i) {
        if (i == 0) {
            deltaArray[i] = startTime[i];
        } else if (i == startTime.size()) {
            deltaArray[i] = eventTime - endTime.back();
        } else {
            deltaArray[i] = startTime[i] - endTime[i - 1];
        }
    }

    vector<bool> q(startTime.size(), false);
    int32_t leftMax = deltaArray.front();
    int32_t rightMax = deltaArray.back();

    for (size_t i = 1; i < startTime.size(); i++) {
        int32_t event1 = endTime[i] - startTime[i];
        if (event1 <= leftMax) {
            q[i] = true;
        }
        leftMax = max(leftMax, deltaArray[i]);

        size_t j = startTime.size() - i - 1;
        int32_t event2 = endTime[j] - startTime[j];
        if (event2 <= rightMax) {
            q[j] = true;
        }
        rightMax = max(rightMax, deltaArray[j + 1]);
    }

    int32_t ans = 0;
    for (size_t i = 0; i < deltaArray.size() - 1; i++) {
        int32_t event = endTime[i] - startTime[i];
        if (q[i]) {
            ans = max(ans, deltaArray[i] + deltaArray[i + 1] + event);
        } else {
            ans = max(ans, deltaArray[i] + deltaArray[i + 1]);
        }
    }
    return ans;
}
