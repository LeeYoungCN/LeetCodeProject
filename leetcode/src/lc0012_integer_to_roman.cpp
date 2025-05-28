// https://leetcode.cn/problems/integer-to-roman/description/
#include "lc0012_integer_to_roman.h"

#include <cstdint>
#include <string>
#include <vector>

using namespace std;

string LC0012_IntegerToRoman::intToRoman(int num)
{
    vector<vector<const char *>> table{
        {"", "M", "MM", "MMM", "", "", "", "", "", ""},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
    };
    string result = "";
    uint32_t mod = 1000;
    for (uint32_t i = 0; num > 0; i++) {
        uint32_t x = num / mod;
        num = num % mod;
        mod /= 10;
        result += (table[i][x]);
    }
    return result;
}
