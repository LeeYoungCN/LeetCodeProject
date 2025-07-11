/*
 * Time : 2025-07-11 00:37:53
 * URL  : https://leetcode.cn/problems/count-days-without-meetings/description/?envType=daily-question&envId=2025-07-11
 */
#ifndef LC3169_COUNT_DAYS_WITHOUT_MEETINGS_H
#define LC3169_COUNT_DAYS_WITHOUT_MEETINGS_H

#include <cstdint>
#include <vector>

class LC3169_CountDaysWithoutMeetings {
public:
    LC3169_CountDaysWithoutMeetings() = default;
    virtual ~LC3169_CountDaysWithoutMeetings() = default;
    int32_t countDays(int32_t days, std::vector<std::vector<int32_t>>& meetings);
};

#endif  // LC3169_COUNT_DAYS_WITHOUT_MEETINGS_H
