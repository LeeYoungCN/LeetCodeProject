/*
 * Time : 2025-06-15 19:50:29
 * URL  :
 * https://leetcode.cn/problems/max-difference-you-can-get-from-changing-an-integer/description/?envType=daily-questionURL_STRenvId=2025-06-15
 */
#include "lc14xx/lc1432_max_difference_you_can_get_from_changing_an_integer.h"

#include <cstdint>

using namespace std;

int LC1432_MaxDifferenceYouCanGetFromChangingAnInteger::maxDiff(int num)
{
    constexpr int32_t TEN = 10;
    constexpr int32_t NINE = 9;

    int32_t times = 1;
    while (num / times > NINE) {
        times *= TEN;
    }

    int32_t maxNum = 0;
    int32_t minNum = 0;

    constexpr int32_t maxDigitY = 9;
    int32_t maxDigitX = -1;
    int32_t minDigitX = -1;
    int32_t minDigitY = 1;

    for (uint32_t idex = 0; times > 0; idex++) {
        int32_t currDigit = num / times;

        if (maxDigitX < 0 && currDigit < NINE) {
            maxDigitX = currDigit;
        }

        if (minDigitX < 0) {
            if (idex == 0 && currDigit != 1) {
                minDigitX = currDigit;
                minDigitY = 1;
            }
            if (idex != 0 && currDigit > 1) {
                minDigitX = currDigit;
                minDigitY = 0;
            }
        }

        maxNum += (currDigit == maxDigitX ? maxDigitY : currDigit) * times;
        minNum += (currDigit == minDigitX ? minDigitY : currDigit) * times;

        num %= times;
        times /= TEN;
    }

    return maxNum - minNum;
}
