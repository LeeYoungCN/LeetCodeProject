/*
 * Time : 2025-06-10 09:25:33
 * URL  :
 * https://leetcode.cn/problems/maximum-difference-between-even-and-odd-frequency-i/description/?envType=daily-questionURL_STRenvId=2025-06-10
 */
#include "lc3xxx/lc34xx/lc344x/lc3442_maximum_difference_between_even_and_odd_frequency_i.h"

#include <algorithm>
#include <climits>
#include <cstdint>
#include <unordered_map>

using namespace std;

int32_t LC3442_MaximumDifferenceBetweenEvenAndOddFrequencyI::maxDifference(string s)
{
    int32_t oddMax = INT32_MIN;
    int32_t eveMin = INT32_MAX;

    unordered_map<char, int32_t> charMap;
    for (const char c : s) {
        charMap[c]++;
    }

    for (auto &[_, cnt] : charMap) {
        if (cnt % 2 == 1) {
            oddMax = max(cnt, oddMax);

        } else {
            eveMin = min(cnt, eveMin);
        }
    }

    return oddMax - eveMin;
}
