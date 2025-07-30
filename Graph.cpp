#include <Graph.h>

void Graph::addVertex(int vertex) {
    if (adjList.find(vertex) != adjList.end()) {
        adjList[vertex] = std::vector<int>();
    }
}

void Graph::addEdge(int src, int dest) {
    addVertex(src);
    addVertex(dest);

    adjList[src].push_back(dest);
    if (!isDirected) adjList[dest].push_back(src);
}

void Graph::removeEdge(int src, int dest) {
    if (adjList.find(src) == adjList.end()) {
        return;
    }

    for (auto it = adjList[src].begin(); it != adjList[src].end(); ++it) {
        if (*it == dest) {
            adjList[src].erase(it);
            break;
        }
    }

    if (!isDirected && adjList.find(dest) != adjList.end()) {
        for (auto it = adjList[dest].begin(); it != adjList[dest].end(); ++it) {
            if (*it == src) {
                adjList[dest].erase(it);
                break;
            }
        }
    }
}

std::vector<int> Graph::getNeighbors(int vertex) const {
    if (adjList.find(vertex) == adjList.end()) {
        throw std::out_of_range("Vertex not found");
    }
    return adjList.at(vertex);
}

bool Graph::hasEdge(int src, int dest) const {
    auto it = adjList.find(src);
    if (it == adjList.end()) {
        return false;
    }

    auto& list = it->second;
    for (auto i = list.begin(); i != list.end(); ++i) {
        if (*i == dest) return true;
    }

    return false;
}
