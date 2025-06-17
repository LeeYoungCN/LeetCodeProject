#include "leetcode_utils.h"

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintVector(const std::vector<UtilsDebug *> &vec, uint32_t start, uint32_t end, bool hasIdx)
{
    cout << Vector2String(vec, start, end, hasIdx) << endl;
}

std::string Vector2String(const std::vector<UtilsDebug *> &vec, uint32_t start, uint32_t end, bool hasIdx)

{
    if (end == 0) {
        end = static_cast<uint32_t>(vec.size());
    }

    const uint32_t length = end - start;
    std::string str = "{";

    for (uint32_t i = 0; i < length; i++) {
        uint32_t index = i + start;
        if (hasIdx) {
            str += "[" + std::to_string(index) + "]=";
        }

        str += vec[i]->toString();
        if (i < length - 1) {
            str += ", ";
        }
    }
    str += "}";
    return str;
}
