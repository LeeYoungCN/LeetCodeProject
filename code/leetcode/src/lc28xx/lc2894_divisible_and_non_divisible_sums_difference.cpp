/*
 * Time : 2025-05-27 00:20:24
 * URL  :
 * https://leetcode.cn/problems/divisible-and-non-divisible-sums-difference/description/?envType=daily-questionURL_STRenvId=2025-05-27
 */
#include "lc28xx/lc2894_divisible_and_non_divisible_sums_difference.h"

#include <cstdint>

using namespace std;

int LC2894_DivisibleAndNonDivisibleSumsDifference::differenceOfSums(int n, int m)
{
    int32_t ans = 0;
    for (int32_t i = 1; i <= n; ++i) {
        if (i % m != 0) {
            ans += i;
        } else {
            ans -= i;
        }
    }
    return ans;
}
