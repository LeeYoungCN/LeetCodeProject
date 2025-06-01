/*
 * Time : 2025-06-01 20:38:27
 * URL  : https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/description/
 */
#ifndef LC1423_MAXIMUM_POINTS_YOU_CAN_OBTAIN_FROM_CARDS_H
#define LC1423_MAXIMUM_POINTS_YOU_CAN_OBTAIN_FROM_CARDS_H

#include <vector>

class LC1423_MaximumPointsYouCanObtainFromCards {
public:
    LC1423_MaximumPointsYouCanObtainFromCards()          = default;
    virtual ~LC1423_MaximumPointsYouCanObtainFromCards() = default;
    int maxScore(std::vector<int>& cardPoints, int k);
};

#endif  // LC1423_MAXIMUM_POINTS_YOU_CAN_OBTAIN_FROM_CARDS_H
