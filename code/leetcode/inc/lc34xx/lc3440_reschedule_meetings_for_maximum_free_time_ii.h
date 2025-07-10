/*
 * Time : 2025-07-10 10:54:41
 * URL  :
 * https://leetcode.cn/problems/reschedule-meetings-for-maximum-free-time-ii/description/?envType=daily-question&envId=2025-07-10
 */
#ifndef LC3440_RESCHEDULE_MEETINGS_FOR_MAXIMUM_FREE_TIME_II_H
#define LC3440_RESCHEDULE_MEETINGS_FOR_MAXIMUM_FREE_TIME_II_H

#include <cstdint>
#include <vector>

class LC3440_RescheduleMeetingsForMaximumFreeTimeII {
public:
    LC3440_RescheduleMeetingsForMaximumFreeTimeII() = default;
    virtual ~LC3440_RescheduleMeetingsForMaximumFreeTimeII() = default;
    int32_t maxFreeTime(int32_t eventTime, std::vector<int32_t>& startTime, std::vector<int32_t>& endTime);
};

#endif  // LC3440_RESCHEDULE_MEETINGS_FOR_MAXIMUM_FREE_TIME_II_H
