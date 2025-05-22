/*
 * Time : 2025-05-22 15:54:36
 * URL  : https://leetcode.cn/problems/zero-array-transformation-ii/description/
 */
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include "lc3356_zero_array_transformation_ii.h"

// vector<int32_t> nums = {2, 0, 2};
// vector<vector<int32_t>> queries = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};

using namespace std;

bool LC3356_ZeroArrayTransformationII_Array::isZeroArray(const vector<int32_t>& nums,
                                                         const vector<vector<int32_t>>& queries,
                                                         uint32_t step)
{
    uint32_t length = nums.size();
    vector<int32_t> deltaArray(length + 1, 0);

    for (uint32_t i = 0; i < step; i++) {
        vector<int32_t> query = queries[i];
        int32_t delta = query[DELTA_IDX];
        uint32_t start = query[START_IDX];
        uint32_t end = query[END_IDX];

        deltaArray[start] += delta;
        deltaArray[end + 1] -= delta;
    }
    int32_t currOper = 0;
    for (uint32_t i = 0; i < length; i++) {
        currOper += deltaArray[i];
        if (currOper < nums[i]) {
            return false;
        }
    }
    return true;
}

int LC3356_ZeroArrayTransformationII_Array::minZeroArray(std::vector<int>& nums,
                                                         std::vector<std::vector<int>>& queries)
{
    uint32_t maxStep = queries.size();
    uint32_t left = 0;
    uint32_t right = maxStep + 1;

    while(left < right) {
        uint32_t k = (left + right) / 2;
        if (isZeroArray(nums, queries, k)) {
            right = k;
        } else {
            left = k + 1;
        }
    }
    return (int32_t)(left > maxStep ? -1 : left);
}


int LC3356_ZeroArrayTransformationII_Greedy::minZeroArray(std::vector<int>& nums,
                                                          std::vector<std::vector<int>>& queries)
{
    int32_t queryIdx = 0;
    int32_t length = nums.size();
    int32_t queryCnt = queries.size();
    int32_t operation = 0;

    vector<int32_t> deltaArray(length + 1, 0);
    for (uint32_t i = 0; i < length; ++i) {
        int32_t n = nums[i];
        operation += deltaArray[i];

        while (queryIdx < queryCnt && operation < n) {
            vector<int32_t> query = queries[queryIdx];
            int32_t start = query[START_IDX];
            int32_t end   = query[END_IDX];
            int32_t delta = query[DELTA_IDX];
            deltaArray[start]   += delta;
            deltaArray[end + 1] -= delta;

            if (start <= i && i <= end) {
                operation += delta;
            }
            queryIdx++;
        }
        if (operation < n) {
            return -1;
        }
    }

    return queryIdx;
}