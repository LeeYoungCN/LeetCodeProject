/*
 * Time : 2025-07-11 00:37:53
 * URL  : https://leetcode.cn/problems/count-days-without-meetings/description/?envType=daily-question&envId=2025-07-11
 */
#include "lc31xx/lc3169_count_days_without_meetings.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

int32_t LC3169_CountDaysWithoutMeetings::countDays(int32_t days, std::vector<std::vector<int32_t>> &meetings)
{
    constexpr size_t START = 0;
    constexpr size_t END = 1;
    std::sort(meetings.begin(), meetings.end());
    int32_t meetDays = 0;
    int32_t currEnd = 0;
    for (size_t i = 0; i < meetings.size(); ++i) {
        if (i == 0 || meetings[i][START] > currEnd) {
            meetDays += meetings[i][END] - meetings[i][START] + 1;
            currEnd = meetings[i][END];
        } else if (meetings[i][END] > currEnd) {
            meetDays += meetings[i][END] - currEnd;
            currEnd = meetings[i][END];
        }
    }
    return days - meetDays;
}
