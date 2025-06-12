/*
 * Time : 2025-06-06 15:36:48
 * URL  : https://leetcode.cn/problems/find-original-array-from-doubled-array/description/
 */
#ifndef LC2007_FIND_ORIGINAL_ARRAY_FROM_DOUBLED_ARRAY_H
#define LC2007_FIND_ORIGINAL_ARRAY_FROM_DOUBLED_ARRAY_H

#include <vector>

class LC2007_FindOriginalArrayFromDoubledArray {
public:
    LC2007_FindOriginalArrayFromDoubledArray() = default;
    virtual ~LC2007_FindOriginalArrayFromDoubledArray() = default;
    virtual std::vector<int> findOriginalArray(std::vector<int>& changed) = 0;
};

class LC2007_FindOriginalArrayFromDoubledArray_Map : public LC2007_FindOriginalArrayFromDoubledArray {
public:
    LC2007_FindOriginalArrayFromDoubledArray_Map() = default;
    virtual ~LC2007_FindOriginalArrayFromDoubledArray_Map() override = default;
    std::vector<int> findOriginalArray(std::vector<int>& changed) final;
};

#endif  // LC2007_FIND_ORIGINAL_ARRAY_FROM_DOUBLED_ARRAY_H
