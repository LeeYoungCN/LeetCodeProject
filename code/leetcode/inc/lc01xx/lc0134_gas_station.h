/*
 * Time : 2025-07-06 15:25:28
 * URL  : https://leetcode.cn/problems/gas-station/description/?envType=problem-list-v2&envId=greedy
 */
#ifndef LC0134_GAS_STATION_H
#define LC0134_GAS_STATION_H

#include <cstdint>
#include <vector>

class LC0134_GasStation {
public:
    LC0134_GasStation() = default;
    virtual ~LC0134_GasStation() = default;
    int32_t canCompleteCircuit(std::vector<int32_t>& gas, std::vector<int32_t>& cost);
};

#endif  // LC0134_GAS_STATION_H
