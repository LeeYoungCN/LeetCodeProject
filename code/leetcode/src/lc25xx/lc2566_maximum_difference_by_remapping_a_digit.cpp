/*
 * Time : 2025-06-14 02:00:32
 * URL  :
 * https://leetcode.cn/problems/maximum-difference-by-remapping-a-digit/description/?envType=daily-questionURL_STRenvId=2025-06-14
 */
#include "lc25xx/lc2566_maximum_difference_by_remapping_a_digit.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <string>

using namespace std;

int LC2566_MaximumDifferenceByRemappingADigit_Math::minMaxDifference(int num)
{
    constexpr const int32_t TEN = 10;
    constexpr const int32_t NINE = 9;

    int32_t times = 1;
    while (num / times > NINE) {
        times *= TEN;
    }

    const int32_t fistMaxDigit = num / times;
    int32_t fistMinDigit = -1;
    int32_t maxNum = 0;
    int32_t minNum = 0;

    while (times >= 1) {
        int32_t currDigit = num / times;

        if (fistMinDigit < 0 && currDigit < NINE) {
            fistMinDigit = currDigit;
        }

        maxNum += (currDigit == fistMinDigit ? NINE : currDigit) * times;
        minNum += (currDigit != fistMaxDigit ? currDigit : 0) * times;

        num %= times;
        times /= TEN;
    }

    return maxNum - minNum;
}

int LC2566_MaximumDifferenceByRemappingADigit_String::minMaxDifference(int num)
{
    string maxStr = to_string(num);
    size_t pos = maxStr.find_first_not_of('9');
    if (pos != string::npos) {
        char n = maxStr.at(pos);
        replace(maxStr.begin(), maxStr.end(), n, '9');
    }
    string minStr = to_string(num);
    char n = minStr[0];
    replace(minStr.begin(), minStr.end(), n, '0');

    return stoi(maxStr) - stoi(minStr);
}
