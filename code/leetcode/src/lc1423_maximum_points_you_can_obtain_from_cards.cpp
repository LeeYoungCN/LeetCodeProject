/*
 * Time : 2025-06-01 20:38:27
 * URL  : https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/description/
 */
#include "lc1423_maximum_points_you_can_obtain_from_cards.h"

#include <cstdint>
#include <cstdio>
#include <numeric>
#include <vector>
using namespace std;

int LC1423_MaximumPointsYouCanObtainFromCards::maxScore(vector<int>& cardPoints, int k)
{
    const auto totalLen = static_cast<uint32_t>(cardPoints.size());
    const uint32_t windowLen = totalLen - static_cast<uint32_t>(k);

    int32_t minSum = INT32_MAX;
    uint32_t start = 0;
    int32_t sum = 0;
    for (uint32_t i = 0; i < totalLen; i++) {
        const uint32_t end = i + 1;
        sum += cardPoints[i];
        if (end - start > windowLen) {
            sum -= cardPoints[start];
            start++;
        }
        if (end - start == windowLen) {
            minSum = min(sum, minSum);
        }
    }

    return (accumulate(cardPoints.begin(), cardPoints.end(), 0) - minSum);
}
