/*
 * Time : 2025-06-24 00:25:16
 * URL  :
 * https://leetcode.cn/problems/find-all-k-distant-indices-in-an-array/description/?envType=daily-question&envId=2025-06-24
 */
#ifndef LC2200_FIND_ALL_K_DISTANT_INDICES_IN_AN_ARRAY_H
#define LC2200_FIND_ALL_K_DISTANT_INDICES_IN_AN_ARRAY_H

#include <vector>

class LC2200_FindAllKDistantIndicesInAnArray {
public:
    LC2200_FindAllKDistantIndicesInAnArray() = default;
    virtual ~LC2200_FindAllKDistantIndicesInAnArray() = default;
    std::vector<int> findKDistantIndices(std::vector<int>& nums, int key, int k);
};

#endif  // LC2200_FIND_ALL_K_DISTANT_INDICES_IN_AN_ARRAY_H
