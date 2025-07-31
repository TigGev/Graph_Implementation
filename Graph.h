#ifndef GRAPH_HEADER
#define GRAPH_HEADER
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

// void dfs();
// void bfs();
// int getNumComponents();
// bool hasCycle();
// std::vector<int> getShortestPath(int src, int dest) const;

class Graph {
    private:
        bool isDirected;
        std::unordered_map<int, std::vector<int>> adjList;

    
        friend void dfsHelper(const Graph& gp, int vertex, std::unordered_set<int>& visited);
        friend void bfs(Graph& gp);
        friend int getNumComponents(Graph& gp);
        friend bool hasCycle(Graph& gp);
    public:
        Graph(bool direted = false) : isDirected(direted) {}

        void addVertex(int vertex);
        void addEdge(int src, int dest);
        void removeEdge(int src, int dest);
        std::vector<int> getNeighbors(int vertex) const;
        bool hasEdge(int src, int dest) const;

        void dfs() const;
};

#endif