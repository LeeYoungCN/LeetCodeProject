#ifndef GRAPH_H
#define GRAPH_H

#include <cstdint>
#include <string>
#include <vector>

std::vector<std::vector<int32_t>> GetGraphByEdges(const std::vector<std::vector<int32_t>> &edges);

std::string Vector2String(const std::vector<int32_t> &vec, bool hasIdx = false);
void PrintVector(const std::vector<int32_t>& vec, bool hasIdx);

#endif  // GRAPH_H
