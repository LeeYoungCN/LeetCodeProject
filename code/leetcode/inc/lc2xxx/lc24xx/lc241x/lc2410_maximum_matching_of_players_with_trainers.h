/*
 * Time : 2025-07-13 12:37:24
 * URL  :
 * https://leetcode.cn/problems/maximum-matching-of-players-with-trainers/description/?envType=daily-question&envId=2025-07-13
 */
#ifndef LC2410_MAXIMUM_MATCHING_OF_PLAYERS_WITH_TRAINERS_H
#define LC2410_MAXIMUM_MATCHING_OF_PLAYERS_WITH_TRAINERS_H

#include <cstdint>
#include <vector>

class LC2410_MaximumMatchingOfPlayersWithTrainers {
public:
    LC2410_MaximumMatchingOfPlayersWithTrainers() = default;
    virtual ~LC2410_MaximumMatchingOfPlayersWithTrainers() = default;
    int32_t matchPlayersAndTrainers(std::vector<int32_t>& players, std::vector<int32_t>& trainers);
};

#endif  // LC2410_MAXIMUM_MATCHING_OF_PLAYERS_WITH_TRAINERS_H
