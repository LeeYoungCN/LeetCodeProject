/*
 * Time : 2025-08-05 10:10:01
 * URL  : https://leetcode.cn/problems/fruits-into-baskets-ii/?envType=daily-question&envId=2025-08-05
 */
#ifndef LC3477_FRUITS_INTO_BASKETS_II_H
#define LC3477_FRUITS_INTO_BASKETS_II_H

#include <cstdint>
#include <vector>

class LC3477_FruitsIntoBasketsII {
public:
    LC3477_FruitsIntoBasketsII() = default;
    virtual ~LC3477_FruitsIntoBasketsII() = default;
    int32_t numOfUnplacedFruits(std::vector<int32_t>& fruits, std::vector<int32_t>& baskets);
};

#endif  // LC3477_FRUITS_INTO_BASKETS_II_H
