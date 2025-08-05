/*
 * Time : 2025-08-05 10:10:01
 * URL  : https://leetcode.cn/problems/fruits-into-baskets-ii/?envType=daily-question&envId=2025-08-05
 */
#include "lc3xxx/lc34xx/lc347x/lc3477_fruits_into_baskets_ii.h"

#include <cstdint>
#include <vector>

using namespace std;

int32_t LC3477_FruitsIntoBasketsII::numOfUnplacedFruits(std::vector<int32_t>& fruits, std::vector<int32_t>& baskets)
{
    uint32_t cnt = 0;
    for (const auto& fruit : fruits) {
        for (int& basket : baskets) {
            if (fruit <= basket) {
                basket = 0;
                cnt++;
                break;
            }
        }
    }

    return static_cast<int32_t>(fruits.size() - cnt);
}
