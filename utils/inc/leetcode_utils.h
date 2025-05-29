#ifndef GRAPH_H
#define GRAPH_H

#include <cstdint>
#include <vector>

enum class GraphType : uint32_t { UNDIRECTED = 0, DIRECTED };

std::vector<std::vector<int32_t>> BuildGraph(const std::vector<std::vector<int32_t>>& edges,
                                             GraphType type = GraphType::UNDIRECTED);

#endif  // GRAPH_H
