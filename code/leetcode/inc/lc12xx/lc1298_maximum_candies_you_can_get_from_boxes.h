/*
 * Time : 2025-06-03 00:02:53
 * URL  :
 * https://leetcode.cn/problems/maximum-candies-you-can-get-from-boxes/description/?envType=daily-questionURL_STRenvId=2025-06-03
 */
#ifndef LC1298_MAXIMUM_CANDIES_YOU_CAN_GET_FROM_BOXES_H
#define LC1298_MAXIMUM_CANDIES_YOU_CAN_GET_FROM_BOXES_H

#include <vector>

class LC1298_MaximumCandiesYouCanGetFromBoxes {
public:
    LC1298_MaximumCandiesYouCanGetFromBoxes() = default;
    virtual ~LC1298_MaximumCandiesYouCanGetFromBoxes() = default;
    int maxCandies(std::vector<int>& status, std::vector<int>& candies, std::vector<std::vector<int>>& keys,
                   std::vector<std::vector<int>>& containedBoxes, std::vector<int>& initialBoxes);
};

#endif  // LC1298_MAXIMUM_CANDIES_YOU_CAN_GET_FROM_BOXES_H
