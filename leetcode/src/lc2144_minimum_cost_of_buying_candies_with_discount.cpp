/*
 * Time : 2025-06-02 15:20:38
 * URL  : https://leetcode.cn/problems/minimum-cost-of-buying-candies-with-discount/description/
 */
#include "lc2144_minimum_cost_of_buying_candies_with_discount.h"

#include <algorithm>
#include <cstdint>
#include <functional>
#include <vector>

using namespace std;

int LC2144_MinimumCostOfBuyingCandiesWithDiscount::minimumCost(std::vector<int>& cost)
{
    sort(cost.begin(), cost.end(), greater<int32_t>());
    int32_t ans = 0;
    for (uint32_t i = 0; i < (uint32_t)cost.size(); i++) {
        if (i % 3 == 2) {
            continue;
        }
        ans += cost[i];
    }
    return ans;
}
