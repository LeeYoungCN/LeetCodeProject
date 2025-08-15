#include "leetcode_utils_vector.hpp"

#include <cstdint>
#include <string>
#include <vector>

#include "leetcode_utils_common.hpp"

std::string Vector2String(const std::vector<std::string>& vec, uint32_t start, uint32_t end, bool hasIdx)
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

std::vector<std::string> CreateStringVector(const std::string& str)
{
    std::vector<std::string> ans;
    uint32_t start = 0;

    for (uint32_t i = 1; i < str.length(); ++i) {
        if (start == 0 && (isAlpha(str[i]) || isNumber(i, str))) {
            start = i;
        } else if (start != 0 && !isAlpha(str[i]) && !isNumber(i, str)) {
            ans.emplace_back(str.substr(start, i - start));
            start = 0;
        }
    }
    if (start != 0) {
        ans.emplace_back(str.substr(start, str.length() - start));
    }
    return ans;
}

std::vector<int32_t> CreateIntVector(const std::string& str)
{
    std::vector<int32_t> ans;
    uint32_t start = 0;

    for (uint32_t i = 1; i < str.length(); ++i) {
        if (start == 0 && isNumber(i, str)) {
            start = i;
        } else if (!isNumber(i, str) && start != 0) {
            ans.emplace_back(std::stoi(str.substr(start, i - start)));
            start = 0;
        }
    }
    if (start != 0) {
        ans.emplace_back(std::stoi(str.substr(start, str.length() - start)));
    }
    return ans;
}

std::vector<std::vector<int32_t>> CreateIntMatrix(const std::string& str)
{
    std::vector<std::vector<int32_t>> ans;
    std::vector<size_t> bracketStack;
    for (size_t i = 1; i < str.length(); i++) {
        if (str[i] == '[') {
            bracketStack.push_back(i);
        } else if (str[i] == ']' && !bracketStack.empty()) {
            size_t start = bracketStack.back();
            bracketStack.pop_back();
            ans.emplace_back(CreateIntVector(str.substr(start, i - start)));
        }
    }
    return ans;
}
