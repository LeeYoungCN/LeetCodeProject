#include "leetcode_utils.h"

#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector<vector<int32_t>> GetGraphByEdges(const vector<vector<int32_t>>& edges)
{
    const uint32_t START_NODE = 0;
    const uint32_t END_NODE = 1;

    uint32_t nodeCnt = (uint32_t)edges.size() + 1;
    vector<vector<int32_t>> graph(nodeCnt, vector<int32_t>());

    for (const vector<int32_t>& edge : edges) {
        int32_t start = edge[START_NODE];
        int32_t end = edge[END_NODE];

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    return graph;
}

string Vector2String(const vector<int32_t>& vec, bool hasIdx)
{
    const uint32_t length = vec.size();
    string str = "{";
    for (uint32_t i = 0; i < length; i++) {
        char tmp[512] = {'\0'};
        if (hasIdx) {
            sprintf(tmp, "[%u]=%d", i, vec[i]);
        } else {
            sprintf(tmp, "%d", vec[i]);
        }
        str += tmp;
        if (i < length - 1) {
            str += ", ";
        }
    }
    str += "{";
    return str;
}

void PrintVector(const vector<int32_t>& vec, bool hasIdx)
{
    printf("%s\n", Vector2String(vec, hasIdx).c_str());
}
