/*
 * Time : 2025-07-09 10:20:38
 * URL  :
 * https://leetcode.cn/problems/reschedule-meetings-for-maximum-free-time-i/description/?envType=daily-question&envId=2025-07-09
 */
#ifndef LC3439_RESCHEDULE_MEETINGS_FOR_MAXIMUM_FREE_TIME_I_H
#define LC3439_RESCHEDULE_MEETINGS_FOR_MAXIMUM_FREE_TIME_I_H

#include <cstdint>
#include <vector>

class LC3439_RescheduleMeetingsForMaximumFreeTimeI {
public:
    LC3439_RescheduleMeetingsForMaximumFreeTimeI() = default;
    virtual ~LC3439_RescheduleMeetingsForMaximumFreeTimeI() = default;
    int32_t maxFreeTime(int32_t eventTime, int32_t k, std::vector<int32_t>& startTime, std::vector<int32_t>& endTime);
};

#endif  // LC3439_RESCHEDULE_MEETINGS_FOR_MAXIMUM_FREE_TIME_I_H
