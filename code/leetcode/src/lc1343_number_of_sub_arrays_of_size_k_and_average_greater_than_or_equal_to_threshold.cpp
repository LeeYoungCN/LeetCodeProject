/*
 * Time : 2025-05-31 22:32:25
 * URL  :
 * https://leetcode.cn/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/
 */
#include "lc1343_number_of_sub_arrays_of_size_k_and_average_greater_than_or_equal_to_threshold.h"

#include <cstdint>
#include <vector>

using namespace std;

int LC1343_NumberOfSubArraysOfSizeKAndAverageGreaterThanOrEqualToThreshold::numOfSubarrays(vector<int>& arr, int k,
                                                                                           int threshold)
{
    const auto length = static_cast<uint32_t>(arr.size());
    const auto window = static_cast<uint32_t>(k);
    const int32_t target = (k * threshold);

    int32_t ans = 0;
    int32_t sum = 0;
    for (uint32_t i = 0, start = 0; i < length; i++) {
        const uint32_t end = i + 1;
        sum += arr[i];

        if (end - start > window) {
            sum -= arr[start];
            start++;
        }

        if (sum >= target && end - start == window) {
            ans++;
        }
    }
    return ans;
}
