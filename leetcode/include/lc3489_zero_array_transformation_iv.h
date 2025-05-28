/*
 * Time : 2025-05-27 16:34:50
 * URL  : https://leetcode.cn/problems/zero-array-transformation-iv/
 */
#ifndef LC3489_ZERO_ARRAY_TRANSFORMATION_IV_H
#define LC3489_ZERO_ARRAY_TRANSFORMATION_IV_H

#include <vector>

class LC3489_ZeroArrayTransformationIV {
public:
    LC3489_ZeroArrayTransformationIV() = default;
    virtual ~LC3489_ZeroArrayTransformationIV() = default;
    int minZeroArray(std::vector<int> &nums, std::vector<std::vector<int>> &queries);

private:
    int GetStep(unsigned int idx, const std::vector<int> &nums, const std::vector<std::vector<int>> &queries);
};

#endif  // LC3489_ZERO_ARRAY_TRANSFORMATION_IV_H
