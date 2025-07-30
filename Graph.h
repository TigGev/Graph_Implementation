#ifndef GRAPH_HEADER
#define GRAPH_HEADER
#include <vector>
#include <unordered_map>

class Graph {
    private:
        bool isDirected;
        std::unordered_map<int, std::vector<int>> adjList;
    public:
        Graph(bool direted = false) : isDirected(direted) {}

        void addVertex(int vertex);
        void addEdge(int src, int dest);
        void removeEdge(int src, int dest);
        std::vector<int> getNeighbors(int vertex) const;
        bool hasEdge(int src, int dest) const;
};

#endif