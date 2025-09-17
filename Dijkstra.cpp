#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

std::vector<int> Dijkstra(std::vector<std::vector<std::pair<int, int>>>& graph) {
    std::vector<int> dist(graph.size(), INT_MAX);
    dist[0] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    std::vector<std::vector<std::pair<int, int>>> graph1 = {
        { {1, 7}, {2, 9}, {5, 14} },
        { {0, 7}, {2, 10}, {3, 15} },
        { {0, 9}, {1, 10}, {3, 11}, {5, 2} },
        { {1, 15}, {2, 11}, {4, 6} },
        { {3, 6}, {5, 9} },
        { {0, 14}, {2, 2}, {4, 9} }
    };

    std::vector<std::vector<std::pair<int,int>>> graph2 = {
        {{1,2},{2,5}},           
        {{0,2},{2,4},{3,6}},     
        {{0,5},{1,4},{3,2},{4,7}}, 
        {{1,6},{2,2},{4,1}},     
        {{2,7},{3,1}}            
    };

    std::vector<std::vector<std::pair<int,int>>> graph3 = {
        {{1,1},{2,4}},   
        {{0,1},{2,2},{3,6}}, 
        {{0,4},{1,2},{3,3}}, 
        {{1,6},{2,3}}    
    };

    std::vector<std::vector<std::pair<int,int>>> graph4 = {
        {{1,3},{2,1}},        
        {{0,3},{2,7},{3,5}},  
        {{0,1},{1,7},{4,2}},  
        {{1,5},{5,7}},        
        {{2,2},{6,3}},        
        {{3,7},{6,1}},        
        {{4,3},{5,1}}         
    };

    std::vector<std::vector<std::pair<int,int>>> graph5 = {
        {{1,1},{2,1},{3,1},{4,1}},  
        {{0,1},{2,1},{3,1},{4,1}},  
        {{0,1},{1,1},{3,1},{4,1}},  
        {{0,1},{1,1},{2,1},{4,1}},  
        {{0,1},{1,1},{2,1},{3,1}}   
    };


    std::vector<std::vector<std::vector<std::pair<int,int>>>> gp{graph1, graph2, graph3, graph4, graph5};

    for (auto gr : gp) {
        for (auto i : Dijkstra(gr)) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};