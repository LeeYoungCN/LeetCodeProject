/*
 * Time : 2025-06-01 16:15:58
 * URL  :
 * https://leetcode.cn/problems/distribute-candies-among-children-ii/?envType=daily-questionURL_STRenvId=2025-06-01
 */
#include "lc2xxx/lc29xx/lc292x/lc2929_distribute_candies_among_children_ii.h"

#include <algorithm>
#include <cstdint>

using namespace std;

long long LC2929_DistributeCandiesAmongChildrenII::distributeCandies(int n, int limit)
{
    const int32_t min_t2 = n < limit ? 0 : n - limit;
    const int32_t min_t1 = min_t2 < limit ? 0 : min_t2 - limit;

    const int32_t max_t1 = limit < n ? limit : n;
    const int32_t max_t2 = max_t1 + limit < n ? max_t1 + limit : n;

    int32_t t1 = min_t1;

    int64_t ans = 0;
    for (; t1 <= max_t1; t1++) {
        ans += min(t1 + limit, max_t2) - max(t1, min_t2) + 1;
    }
    return ans;
}
