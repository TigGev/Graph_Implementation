# Graph Implementation

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/TigGev/Graph_Implementation/blob/main/LICENSE)
[![Language: C++](https://img.shields.io/badge/language-C%2B%2B-blue.svg)](https://github.com/TigGev/Graph_Implementation)
[![Project Status](https://img.shields.io/badge/status-active-brightgreen.svg)](https://github.com/TigGev/Graph_Implementation)
[![GitHub Stars](https://img.shields.io/github/stars/TigGev/Graph_Implementation.svg?style=social)](https://github.com/TigGev/Graph_Implementation/stargazers)
[![GitHub Forks](https://img.shields.io/github/forks/TigGev/Graph_Implementation.svg?style=social)](https://github.com/TigGev/Graph_Implementation/network)

A C++-based implementation of graph data structures and algorithms, supporting directed/undirected and weighted/unweighted graphs with traversal and path-finding algorithms.

## 🚀 Features

- **Graph Representations**: Adjacency list and matrix
- **Operations**: Add/remove vertices and edges
- **Algorithms**: DFS, BFS, Dijkstra’s, Bellman-Ford
- **Cycle Detection**: For directed and undirected graphs
- **Modular Design**: Extensible for additional algorithms


## ⚙️ Build & Run

### Requirements
- C++ compiler (e.g., g++ 9+ with C++17 support)
- Make
- Optional: Valgrind for memory testing

### Build
```bash
git clone https://github.com/TigGev/Graph_Implementation.git
cd Graph_Implementation
make
```

### Run Examples
```bash
# Run simple graph demo
./build/simple_graph

# Run weighted graph demo
./build/weighted_graph
```

## 📖 Usage Example

### Creating a Simple Graph
```cpp
#include "graph.hpp"

int main() {
    Graph g(5); // 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    std::cout << "BFS from vertex 0:\n";
    g.bfs(0);

    return 0;
}
```

### Dijkstra’s Algorithm
```cpp
#include "graph.hpp"

int main() {
    WeightedGraph g(4);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);

    std::vector<int> distances = g.dijkstra(0);
    std::cout << "Shortest distances from vertex 0: ";
    for (int d : distances) {
        std::cout << d << " ";
    }
    std::cout << "\n";

    return 0;
}
```

## 🧪 Testing
Run the test suite to verify functionality:
```bash
make test
./build/test_suite
```

## 🛠️ Future Improvements
- Add A*, Floyd-Warshall, or MST algorithms
- Support graph I/O (e.g., JSON, CSV)
- Integrate Graphviz for visualization
- Optimize with priority queues or bitsets
- Expand unit tests with a framework (e.g., Catch2)

## 🤝 Contributing
1. Fork the repository
2. Create a feature branch (`git checkout -b feature/new-algorithm`)
3. Commit changes (`git commit -m 'Add new algorithm'`)
4. Push to the branch (`git push origin feature/new-algorithm`)
5. Open a Pull Request

Follow C++17 standards and include tests.

## 📄 License
Licensed under the MIT License. See [LICENSE](LICENSE) for details.

## 📞 Contact
Maintained by [TigGev](https://github.com/TigGev).  
Open an issue for questions or suggestions.

---

*Built with ❤️ for learning graph algorithms in C++.*