/*
 * Time : 2025-06-22 14:42:38
 * URL  :
 * https://leetcode.cn/problems/divide-a-string-into-groups-of-size-k/description/?envType=daily-question&envId=2025-06-22
 */
#ifndef LC2138_DIVIDE_A_STRING_INTO_GROUPS_OF_SIZE_K_H
#define LC2138_DIVIDE_A_STRING_INTO_GROUPS_OF_SIZE_K_H

#include <string>
#include <vector>

class LC2138_DivideAStringIntoGroupsOfSizeK {
public:
    LC2138_DivideAStringIntoGroupsOfSizeK() = default;
    virtual ~LC2138_DivideAStringIntoGroupsOfSizeK() = default;
    std::vector<std::string> divideString(std::string s, int k, char fill);
};

#endif  // LC2138_DIVIDE_A_STRING_INTO_GROUPS_OF_SIZE_K_H
