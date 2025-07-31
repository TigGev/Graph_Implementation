#include <Graph.h>

void Graph::addVertex(int vertex) {
    if (adjList.find(vertex) == adjList.end()) {
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

void dfsHelper(const Graph& gp, int vertex, std::unordered_set<int>& visited) {
    visited.insert(vertex);
    std::cout << vertex << " ";

    auto it = gp.adjList.find(vertex);
    if (it != gp.adjList.end()) {
        for (int v : it->second) {
            if (visited.find(v) == visited.end()) {
                dfsHelper(gp, v, visited);
            }
        }
    }
}

void Graph::dfs() const {
    std::unordered_set<int> visited;
    for (const auto& v : adjList) {
        if (visited.find(v.first) == visited.end()) {
            dfsHelper(*this, v.first, visited);
        }
    }
    std::cout << std::endl;
}

int main() {
    Graph gp;
    gp.addVertex(0);
    gp.addVertex(1);
    gp.addVertex(2);
    gp.addVertex(3);
    gp.addVertex(4);
    gp.addVertex(5);

    gp.addEdge(0, 1);
    gp.addEdge(0, 2);
    gp.addEdge(0, 3);
    gp.addEdge(2, 3);
    gp.addEdge(1, 4);
    gp.addEdge(3, 5);

    gp.dfs();
}