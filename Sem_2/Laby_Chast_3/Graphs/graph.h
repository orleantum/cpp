#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <set>
#include <vector>
#include <utility>

class Graph {
public:
    Graph();
    void addVertex();
    void removeVertex(int v);
    void addEdge(int from, int to, int weight);
    void removeEdge(int from, int to);
    void editWeight(int from, int to, int newWeight);

    void printDistanceMatrix();
    void printAdjacencyMatrix();
    std::map<std::pair<int, int>, int> floydWarshall();

    std::vector<int> bfs(int start);
    std::vector<int> dfs(int start);
    std::map<int, int> dijkstra(int start);

private:
    std::map<int, std::map<int, int>> adjacency;
    int nextVertexId = 0;
};

#endif
