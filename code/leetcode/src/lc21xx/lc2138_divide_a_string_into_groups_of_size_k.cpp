/*
 * Time : 2025-06-22 14:42:38
 * URL  :
 * https://leetcode.cn/problems/divide-a-string-into-groups-of-size-k/description/?envType=daily-question&envId=2025-06-22
 */
#include "lc21xx/lc2138_divide_a_string_into_groups_of_size_k.h"

#include <cstdint>
#include <string>
#include <vector>

using namespace std;

std::vector<std::string> LC2138_DivideAStringIntoGroupsOfSizeK::divideString(std::string s, int k, char fill)
{
    const auto length = static_cast<uint32_t>(s.length());

    vector<string> ans;
    for (uint32_t i = 0; i < length;) {
        string tmp(static_cast<uint32_t>(k), fill);
        for (uint32_t j = 0; j < static_cast<uint32_t>(k); j++) {
            if (i < length) {
                tmp[j] = s[i++];
            } else {
                break;
            }
        }
        ans.push_back(tmp);
    }

    return ans;
}
