/*
 * Time : 2025-05-22 15:45:08
 * URL  : https://leetcode.cn/problems/zero-array-transformation-iii/?envType=daily-questionURL_STRenvId=2025-05-22
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
#include <queue>
#include "lc3362_zero_array_transformation_iii.h"

using namespace std;

struct QuerySt {
    int32_t start;
    int32_t end;
    bool operator< (const QuerySt &other) const {
        return this->end < other.end;
    }
};

int LC3362_ZeroArrayTransformationIII::maxRemoval(std::vector<int>& nums, std::vector<std::vector<int>>& queries)
{
    auto compareQuertVec = [](const vector<int32_t> &a, const vector<int32_t> &b) {return a[0] < b[0];};
    sort(queries.begin(), queries.end(), compareQuertVec);
    
    const uint32_t START = 0;
    const uint32_t END = 1;

    priority_queue<QuerySt> maxHeap;
    int32_t length = nums.size();
    vector<int32_t> deltaArray(length + 1, 0);
    int32_t queryCnt = queries.size();
    int32_t operation = 0;
    int32_t queryIdx = 0;

    for (int32_t i = 0; i < length; ++i) {
        operation += deltaArray[i];
        while (queryIdx < queryCnt && queries[queryIdx][START] == i) {
            maxHeap.push({queries[queryIdx][START], queries[queryIdx][END]});
            ++queryIdx;
        }

        int32_t n = nums[i];
        while (!maxHeap.empty() && maxHeap.top().end >= i && operation < n) {
            deltaArray[maxHeap.top().end + 1] -= 1;
            maxHeap.pop();
            ++operation;
        }
        if (operation < n) {
            return -1;
        }
    }

    return maxHeap.size();
}

