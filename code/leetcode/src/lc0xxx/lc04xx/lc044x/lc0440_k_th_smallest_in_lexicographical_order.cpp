/*
 * Time : 2025-06-09 00:44:38
 * URL  :
 * https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/description/?envType=daily-questionURL_STRenvId=2025-06-09
 */
#include "lc0xxx/lc04xx/lc044x/lc0440_k_th_smallest_in_lexicographical_order.h"

#include <algorithm>
#include <cstdint>

using namespace std;

int64_t GetStep(int32_t prefix, int64_t limit)
{
    int64_t first = prefix;
    int64_t last = prefix;
    int64_t cnt = 0;
    while (first <= limit) {
        cnt += min(last, limit) - first + 1LL;
        first = first * 10;    // 10, 100, 1000 ...
        last = last * 10 + 9;  // 19, 199, 1999 ...
    }
    return cnt;
}

int32_t LC0440_KThSmallestInLexicographicalOrder::findKthNumber(int32_t n, int32_t k)
{
    int32_t curr = 1;
    int32_t currStep = 1;

    while (currStep < k) {
        auto step = static_cast<int32_t>(GetStep(curr, n));
        if (currStep + step <= k) {
            currStep += step;
            curr++;
        } else {
            curr *= 10;
            currStep++;
        }
    }

    return curr;
}
