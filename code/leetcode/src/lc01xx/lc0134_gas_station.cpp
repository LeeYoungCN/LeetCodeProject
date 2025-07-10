/*
 * Time : 2025-07-06 15:25:28
 * URL  : https://leetcode.cn/problems/gas-station/description/?envType=problem-list-v2&envId=greedy
 */
#include "lc01xx/lc0134_gas_station.h"

#include <cstdint>
#include <vector>

using namespace std;

int32_t LC0134_GasStation::canCompleteCircuit(std::vector<int32_t>& gas, std::vector<int32_t>& cost)
{
    int32_t totalSum = 0;
    int32_t start = -1;
    int32_t startSum = 0;
    for (uint32_t i = 0; i < gas.size(); i++) {
        if (start < 0 && gas[i] >= cost[i]) {
            start = static_cast<int32_t>(i);
        }
        if (start >= 0) {
            startSum += (gas[i] - cost[i]);
        }
        if (startSum < 0) {
            start = -1;
            startSum = 0;
        }
        totalSum += (gas[i] - cost[i]);
    }
    return (totalSum < 0 ? -1 : start);
}
