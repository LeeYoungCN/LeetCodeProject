/*
 * Time : 2025-07-05 10:37:30
 * URL  :
 * https://leetcode.cn/problems/find-lucky-integer-in-an-array/description/?envType=daily-question&envId=2025-07-05
 */
#include "lc13xx/lc1394_find_lucky_integer_in_an_array.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

int32_t LC1394_FindLuckyIntegerInAnArray::findLucky(std::vector<int32_t>& arr)
{
    sort(arr.begin(), arr.end());
    int32_t ans = -1;
    int32_t pre = arr[0];
    int32_t cnt = 0;
    for (const auto& n : arr) {
        if (n == pre) {
            cnt++;
        } else {
            if (pre == cnt) {
                ans = pre;
            }
            pre = n;
            cnt = 1;
        }
    }
    if (pre == cnt) {
        ans = pre;
    }
    return ans;
}
