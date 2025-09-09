#include <iostream>
#include <vector>
#include <stack>

void dfs(std::vector<std::vector<int>>& graph, int u, std::vector<bool>& visited, std::stack<int>& st) {
    visited[u] = true;
    for (auto v : graph[u]) {
        if (!visited[v]) 
            dfs(graph, v, visited, st);
    }
    st.push(u);
}

void dfs(std::vector<std::vector<int>>& graph, int u, std::vector<bool>& visited, std::vector<int>& scc) {
    visited[u] = true;
    std::cout << "scc->" << u << std::endl;
    scc.push_back(u);
    for (auto v : graph[u]) {
        if (!visited[v]) 
            dfs(graph, v, visited, scc);
    }
}


void transpose_graph(std::vector<std::vector<int>>& graph, std::vector<std::vector<int>>& newGraph) {
    for (int u{}; u < graph.size(); ++u) {
        for (auto v : graph[u]) {
            newGraph[v].push_back(u);
        }
    }
}

std::vector<std::vector<int>> all_scc_in_graph(std::vector<std::vector<int>>& graph) {
    std::vector<bool> visited(graph.size(), false);
    std::stack<int> st;

    for (int u{}; u < graph.size(); ++u) {
        if (!visited[u])
            dfs(graph, u, visited, st);
    }

    std::vector<std::vector<int>> newGraph(graph.size());
    transpose_graph(graph, newGraph);

    std::vector<std::vector<int>> sccs;
    std::vector<int> scc;
    visited.clear();
    visited = std::vector<bool>(newGraph.size(), false);
    
    while(!st.empty()) {
        auto u = st.top();
        st.pop();
        if (!visited[u]) {
            dfs(newGraph, u, visited, scc);
        }
        if (!scc.empty()) sccs.push_back(scc);
        scc.clear();
    }

    return sccs;
}
