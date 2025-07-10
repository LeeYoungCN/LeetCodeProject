/*
 * Time : 2025-06-20 00:29:16
 * URL  :
 * https://leetcode.cn/problems/maximum-manhattan-distance-after-k-changes/description/?envType=daily-questionURL_STRenvId=2025-06-20
 */
#include "lc34xx/lc3443_maximum_manhattan_distance_after_k_changes.h"

#include <algorithm>
#include <cstdint>
#include <string>

using namespace std;

int LC3443_MaximumManhattanDistanceAfterKChanges::maxDistance(string s, int k)
{
    int32_t ans = 0;
    int32_t north = 0;
    int32_t south = 0;
    int32_t west = 0;
    int32_t east = 0;
    for (char dir : s) {
        switch (dir) {
            case 'N':
                north++;
                break;
            case 'S':
                south++;
                break;
            case 'W':
                west++;
                break;
            case 'E':
                east++;
                break;
            default:
                break;
        }

        int32_t delta1 = min({north, south, k});
        int32_t delta2 = min({west, east, k - delta1});

        ans = max(ans, (abs(north - south) + 2 * delta1 + abs(west - east) + 2 * delta2));
    }

    return ans;
}
