/*
 * Time : 2025-06-11 09:53:03
 * URL  :
 * https://leetcode.cn/problems/maximum-difference-between-even-and-odd-frequency-ii/?envType=daily-questionURL_STRenvId=2025-06-11
 */
#include "lc3445_maximum_difference_between_even_and_odd_frequency_ii.h"

#include <cstdint>

using namespace std;

#define REVERSE(x) ((x) ^ 0b10)

int32_t LC3445_MaximumDifferenceBetweenEvenAndOddFrequencyII::maxDifference(string s, int32_t k)
{
    const char MIN_CHAR = '0';
    const char MAX_CHAR = '4';

    auto GetStatus = [](int32_t a, int32_t b) -> int32_t { return (((a & 0b1) << 1) | ((b & 0b1) << 0)); };

    const auto length = static_cast<uint32_t>(s.size());

    int32_t ans = INT32_MIN;

    for (char a = MIN_CHAR; a <= MAX_CHAR; ++a) {
        for (char b = MIN_CHAR; b <= MAX_CHAR; ++b) {
            if (a == b) {
                continue;
            }
            int32_t minLeft[4] = {INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX};

            int32_t rightA = 0;
            int32_t rightB = 0;
            int32_t leftA = 0;
            int32_t leftB = 0;

            uint32_t left = 0;
            for (uint32_t right = 0; right < length; ++right) {
                rightA += (s[right] == a ? 1 : 0);
                rightB += (s[right] == b ? 1 : 0);

                while (right - left + 1 >= static_cast<uint32_t>(k) && rightB > leftB && rightA > leftA) {
                    int32_t lStatus = GetStatus(leftA, leftB);
                    minLeft[lStatus] = min(minLeft[lStatus], leftA - leftB);
                    leftA += (s[left] == a ? 1 : 0);
                    leftB += (s[left] == b ? 1 : 0);
                    ++left;
                }

                int32_t rStatus = GetStatus(rightA, rightB);
                if (minLeft[REVERSE(rStatus)] != INT32_MAX) {
                    ans = max(ans, rightA - rightB - minLeft[REVERSE(rStatus)]);
                }
            }
        }
    }

    return ans;
}
