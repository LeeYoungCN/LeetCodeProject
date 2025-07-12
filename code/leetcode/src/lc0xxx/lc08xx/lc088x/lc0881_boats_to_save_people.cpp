/*
 * Time : 2025-06-02 15:42:25
 * URL  : https://leetcode.cn/problems/boats-to-save-people/description/
 */
#include "lc0xxx/lc08xx/lc088x/lc0881_boats_to_save_people.h"

#include <algorithm>
#include <cstdint>
#include <functional>
#include <vector>

using namespace std;

int LC0881_BoatsToSavePeople::numRescueBoats(std::vector<int>& people, int limit)
{
    sort(people.begin(), people.end(), greater<>());
    uint32_t left = 0;
    uint32_t right = static_cast<uint32_t>(people.size()) - 1;
    int32_t ans = 0;
    while (left <= right) {
        const int32_t n = limit - people[left];
        ans++;
        left++;

        if (people[right] <= n) {
            right--;
        }
    }
    return ans;
}
