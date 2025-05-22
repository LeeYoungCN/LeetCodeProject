/*
 * Time : 2025-05-22 15:54:36
 * URL  : https://leetcode.cn/problems/zero-array-transformation-ii/description/
 */
#ifndef LC3356_ZERO_ARRAY_TRANSFORMATION_II_H
#define LC3356_ZERO_ARRAY_TRANSFORMATION_II_H

#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>

class LC3356_ZeroArrayTransformationII {
    public:
        LC3356_ZeroArrayTransformationII() = default;
        virtual ~LC3356_ZeroArrayTransformationII() = default;
        virtual int minZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) = 0;
    protected:
        bool isZeroArray(const std::vector<int32_t>& nums, const std::vector<std::vector<int32_t>>& queries,
                         uint32_t step);
};

class LC3356_ZeroArrayTransformationII_Array : public LC3356_ZeroArrayTransformationII {
    int minZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries);
};

#endif // LC3356_ZERO_ARRAY_TRANSFORMATION_II_H