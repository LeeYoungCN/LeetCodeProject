/*
 * Time : 2025-08-05 11:20:31
 * URL  : https://leetcode.cn/problems/fruit-into-baskets/?envType=daily-question&envId=2025-08-05
 */
#include "lc0xxx/lc09xx/lc090x/lc0904_fruit_into_baskets.h"

#include <algorithm>
#include <array>
#include <cstdint>
#include <vector>

using namespace std;

int32_t LC0904_FruitIntoBaskets::totalFruit(std::vector<int32_t>& fruits)
{
    int32_t ans = 0;
    std::array<pair<int32_t, int32_t>, 2> basket{make_pair(fruits[0], 1), make_pair(-1, 0)};

    uint32_t preIdx = 0;
    uint32_t left = 0;

    for (uint32_t i = 1; i < fruits.size(); i++) {
        if (fruits[i] == basket[0].first) {
            basket[0].second++;
            preIdx = 0;
        } else if (fruits[i] == basket[1].first) {
            basket[1].second++;
            preIdx = 1;
        } else {
            ans = max(basket[0].second + basket[1].second, ans);
            while (left != i && basket[1 - preIdx].second != 0) {
                if (fruits[left] == basket[preIdx].first) {
                    basket[preIdx].second--;
                } else {
                    basket[1 - preIdx].second--;
                }
                left++;
            }
            preIdx = 1 - preIdx;
            basket[preIdx].first = fruits[i];
            basket[preIdx].second = 1;
        }
    }
    ans = max(basket[0].second + basket[1].second, ans);
    return ans;
}
