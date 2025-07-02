#include "leetcode_utils_vector.hpp"

#include <cstdint>
#include <string>
#include <vector>

#include "leetcode_utils_common.hpp"

std::string Vector2String(const std::vector<std::string> &vec, uint32_t start, uint32_t end, bool hasIdx)
{
    if (vec.empty()) {
        return "{}";
    }
    if (end == 0) {
        end = static_cast<uint32_t>(vec.size());
    }
    end = std::min(end, static_cast<uint32_t>(vec.size()));
    if (start >= end) {
        LOG("Invalid param. start=%u, end=%u.", start, end);
        return "{}";
    }
    const uint32_t length = end - start;
    std::string str = "{";

    for (uint32_t i = 0; i < length; i++) {
        uint32_t index = i + start;

        if (hasIdx) {
            str += "[" + std::to_string(index) + "]=";
        }

        str += vec[index];
        if (i < length - 1) {
            str += ", ";
        }
    }
    str += "}";
    return str;
}
