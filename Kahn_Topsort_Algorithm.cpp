#ifndef KAHN_ALGORITHM
#define KAHN_ALGORITHM
#include <iostream>
#include <vector>
#include <queue>

std::vector<int> Kahn_topsort_algorithm(std::vector<std::vector<int>>& graph) {
     std::vector<int> inDegree(graph.size());
     for (auto adj : graph) {
        for (auto v : adj) {
            inDegree[v]++;
        }
     }

    std::queue<int> q;
    for (int i = 0; i < inDegree.size(); ++i) {
        if (inDegree[i] == 0) q.push(i);
    }

    std::vector<int> topsort;

    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        topsort.push_back(u);
        for (auto v : graph[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) q.push(v);
        }
    }
    if (topsort.size() != graph.size()) throw std::invalid_argument("Graph has a cycle");
    return topsort;
}
#endif