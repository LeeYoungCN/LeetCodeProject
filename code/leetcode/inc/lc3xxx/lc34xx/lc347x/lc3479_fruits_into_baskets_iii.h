/*
 * Time : 2025-08-12 09:27:14
 * URL  : https://leetcode.cn/problems/fruits-into-baskets-iii/?envType=daily-question&envId=2025-08-12
 */
#ifndef LC3479_FRUITS_INTO_BASKETS_III_H
#define LC3479_FRUITS_INTO_BASKETS_III_H

#include <cstdint>
#include <vector>

class LC3479_FruitsIntoBasketsIII {
public:
    LC3479_FruitsIntoBasketsIII() = default;
    virtual ~LC3479_FruitsIntoBasketsIII() = default;
    virtual int32_t numOfUnplacedFruits(std::vector<int32_t>& fruits, std::vector<int32_t>& baskets) = 0;
};

class LC3479_FruitsIntoBasketsIII_Node final : public LC3479_FruitsIntoBasketsIII {
public:
    LC3479_FruitsIntoBasketsIII_Node() = default;
    ~LC3479_FruitsIntoBasketsIII_Node() final = default;
    int32_t numOfUnplacedFruits(std::vector<int32_t>& fruits, std::vector<int32_t>& baskets) override;
};

#endif  // LC3479_FRUITS_INTO_BASKETS_III_H
