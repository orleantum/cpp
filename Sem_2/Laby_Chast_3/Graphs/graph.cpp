#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
#include <limits>

Graph::Graph() {}

void Graph::addVertex() {
    adjacency[nextVertexId];
    nextVertexId++;
}

void Graph::removeVertex(int v) {
    adjacency.erase(v);
    for (auto& [from, edges] : adjacency)
        edges.erase(v);
}

void Graph::addEdge(int from, int to, int weight) {
    adjacency[from][to] = weight;
}

void Graph::removeEdge(int from, int to) {
    if (adjacency.count(from))
        adjacency[from].erase(to);
}

void Graph::editWeight(int from, int to, int newWeight) {
    if (adjacency.count(from) && adjacency[from].count(to))
        adjacency[from][to] = newWeight;
}

std::vector<int> Graph::bfs(int start) {
    std::vector<int> result;
    std::set<int> visited;
    std::queue<int> q;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        result.push_back(v);
        for (const auto& [to, _] : adjacency[v]) {
            if (!visited.count(to)) {
                q.push(to);
                visited.insert(to);
            }
        }
    }
    return result;
}

std::vector<int> Graph::dfs(int start) {
    std::vector<int> result;
    std::set<int> visited;
    std::stack<int> s;

    s.push(start);
    visited.insert(start);

    while (!s.empty()) {
        int v = s.top(); s.pop();
        result.push_back(v);
        for (const auto& [to, _] : adjacency[v]) {
            if (!visited.count(to)) {
                s.push(to);
                visited.insert(to);
            }
        }
    }
    return result;
}

std::map<int, int> Graph::dijkstra(int start) {
    std::map<int, int> dist;
    std::set<int> visited;

    for (const auto& [v, _] : adjacency)
        dist[v] = std::numeric_limits<int>::max();
    dist[start] = 0;

    while (visited.size() < adjacency.size()) {
        int u = -1;
        int minDist = std::numeric_limits<int>::max();
        for (const auto& [v, d] : dist) {
            if (!visited.count(v) && d < minDist) {
                minDist = d;
                u = v;
            }
        }
        if (u == -1) break;
        visited.insert(u);

        for (const auto& [to, weight] : adjacency[u]) {
            int alt = dist[u] + weight;
            if (alt < dist[to])
                dist[to] = alt;
        }
    }

    return dist;
}

std::map<std::pair<int, int>, int> Graph::floydWarshall() {
    std::map<std::pair<int, int>, int> dist;

    for (const auto& [from, _] : adjacency) {
        for (const auto& [to, _] : adjacency) {
            if (from == to)
                dist[{from, to}] = 0;
            else if (adjacency[from].count(to))
                dist[{from, to}] = adjacency[from][to];
            else
                dist[{from, to}] = std::numeric_limits<int>::max() / 2;
        }
    }

    for (const auto& [k, _] : adjacency) {
        for (const auto& [i, _] : adjacency) {
            for (const auto& [j, _] : adjacency) {
                if (dist[{i, k}] + dist[{k, j}] < dist[{i, j}])
                    dist[{i, j}] = dist[{i, k}] + dist[{k, j}];
            }
        }
    }

    return dist;
}

void Graph::printDistanceMatrix() {
    auto dist = floydWarshall();
    std::cout << "Distance matrix:\n";
    for (const auto& [i, _] : adjacency) {
        for (const auto& [j, _] : adjacency) {
            int d = dist[{i, j}];
            if (d >= (std::numeric_limits<int>::max() / 2))
                std::cout << "INF\t";
            else
                std::cout << d << "\t";
        }
        std::cout << "\n";
    }
}

void Graph::printAdjacencyMatrix() {
    std::cout << "Adjacency matrix:\n";
    for (const auto& [i, edges] : adjacency) {
        for (const auto& [j, _] : adjacency) {
            std::cout << (edges.count(j) ? edges.at(j) : 0) << "\t";
        }
        std::cout << "\n";
    }
}
