#include "leetcode_utils.h"

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<uint32_t>> GetGraphByEdges(const vector<vector<int32_t>> &edges)
{
    const uint32_t START_NODE = 0;
    const uint32_t END_NODE = 1;

    uint32_t nodeCnt = (uint32_t)edges.size() + 1;
    vector<vector<uint32_t>> graph(nodeCnt, vector<uint32_t>());

    for (const vector<int32_t> &edge : edges) {
        uint32_t start = (uint32_t)edge[START_NODE];
        uint32_t end = (uint32_t)edge[END_NODE];

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    return graph;
}

void PrintVector(const std::vector<UtilsDegbug *> &vec, uint32_t start, uint32_t end, bool hasIdx)
{
    cout << Vector2String(vec, start, end, hasIdx) << endl;
}

std::string Vector2String(const std::vector<UtilsDegbug *> &vec, uint32_t start, uint32_t end, bool hasIdx)

{
    if (end == 0) {
        end = (uint32_t)vec.size();
    }

    const uint32_t length = end - start;
    std::string str = "{";

    for (uint32_t i = 0; i < length; i++) {
        uint32_t index = i + start;
        if (hasIdx) {
            str += "[" + std::to_string(index) + "]=";
        }

        str += vec[i]->ToString();
        if (i < length - 1) {
            str += ", ";
        }
    }
    str += "}";
    return str;
}
