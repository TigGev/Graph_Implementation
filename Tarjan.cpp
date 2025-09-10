#include <iostream>
#include <vector>
#include <stack>

int id{};
std::vector<std::vector<int>> sccs;
std::stack<int> st;

void dfs(std::vector<std::vector<int>>& graph, int u, std::vector<int>& ids, std::vector<int>& ll, std::vector<bool>& onStack) {
    ll[u] = ids[u] = id++;
    st.push(u);
    onStack[u] = true;
    for (auto v : graph[u]) {
        if (ids[v] == -1) dfs(graph, v, ids, ll, onStack);
        if (onStack[v] == true) ll[u] = std::min(ll[u], ll[v]);
    }
    if (ll[u] == ids[u]) {
        std::vector<int> scc;
        while (true) {
            int v = st.top();
            scc.push_back(v);
            st.pop();
            onStack[u] = false;
            if (v == u) break;
        }
        sccs.push_back(scc);
    }
}

void tarjan(std::vector<std::vector<int>>& graph) {
    std::vector<int> ids(graph.size(), -1);
    std::vector<int> ll(graph.size(), -1);
    std::vector<bool> onStack(graph.size(), false);

    for (int u{}; u < graph.size(); ++u) {
        if (ids[u] == -1) {
            dfs(graph, u, ids, ll, onStack);
        }
    }
}

int main() {
    int n = 7;
    std::vector<std::vector<int>> graph(n);

    // Example graph
    graph[0] = {1, 2};
    graph[1] = {2, 3};
    graph[2] = {1, 4};
    graph[3] = {5};
    graph[4] = {3, 5};
    graph[5] = {4, 6};
    graph[6] = {};

    tarjan(graph);

    std::cout << "Strongly Connected Components:\n";
    for (auto& comp : sccs) {
        for (int v : comp) std::cout << v << " ";
        std::cout << "\n";
    }
}
