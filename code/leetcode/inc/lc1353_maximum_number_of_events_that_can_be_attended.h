/*
 * Time : 2025-07-07 09:05:44
 * URL  :
 * https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/description/?envType=daily-question&envId=2025-07-07
 */
#ifndef LC1353_MAXIMUM_NUMBER_OF_EVENTS_THAT_CAN_BE_ATTENDED_H
#define LC1353_MAXIMUM_NUMBER_OF_EVENTS_THAT_CAN_BE_ATTENDED_H

#include <cstdint>
#include <vector>

class LC1353_MaximumNumberOfEventsThatCanBeAttended {
public:
    LC1353_MaximumNumberOfEventsThatCanBeAttended() = default;
    virtual ~LC1353_MaximumNumberOfEventsThatCanBeAttended() = default;
    int32_t maxEvents(std::vector<std::vector<int32_t>>& events);
};

#endif  // LC1353_MAXIMUM_NUMBER_OF_EVENTS_THAT_CAN_BE_ATTENDED_H
