/*
 * Time : 2025-07-07 09:05:44
 * URL  :
 * https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/description/?envType=daily-question&envId=2025-07-07
 */
#include "lc13xx/lc1353_maximum_number_of_events_that_can_be_attended.h"

#include <cstdint>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

int32_t LC1353_MaximumNumberOfEventsThatCanBeAttended::maxEvents(std::vector<std::vector<int32_t>>& events)
{
    constexpr uint32_t START = 0;
    constexpr uint32_t END = 1;
    priority_queue<vector<int32_t>, vector<vector<int32_t>>, greater<>> startHeap;
    priority_queue<int32_t, vector<int32_t>, greater<>> endHeap;
    for (const auto& event : events) {
        startHeap.emplace(event);
    }
    uint32_t ans = 0;
    int32_t currDay = 0;
    while (!startHeap.empty()) {
        while (!endHeap.empty() && endHeap.top() < currDay) {
            endHeap.pop();
        }
        if (currDay < startHeap.top()[START]) {
            if (!endHeap.empty()) {
                endHeap.pop();
                currDay++;
            } else {
                currDay = startHeap.top()[START] + 1;
                startHeap.pop();
            }
            ans++;
        } else {
            endHeap.emplace(startHeap.top()[END]);
            startHeap.pop();
        }
    }
    while (!endHeap.empty()) {
        if (currDay <= endHeap.top()) {
            currDay++;
            ans++;
        }
        endHeap.pop();
    }

    return static_cast<int32_t>(ans);
}
