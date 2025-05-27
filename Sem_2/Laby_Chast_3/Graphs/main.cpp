#include "graph.h"
#include <iostream>

int main() {
    Graph g;
    // Добавляем 6 вершин
    for (int i = 1; i <= 6; ++i) g.addVertex();

    // Добавляем рёбра из картинки
    g.addEdge(1, 2, 11);
    g.addEdge(1, 6, 7);
    g.addEdge(2, 4, 6);
    g.addEdge(3, 1, 21);
    g.addEdge(3, 6, 20);
    g.addEdge(3, 5, 3);
    g.addEdge(4, 3, 8);
    g.addEdge(4, 5, 15);

    // Теперь продолжаем как раньше
    int choice;
    while (true) {
        std::cout << "\nМеню:\n"
                  << "1. BFS\n"
                  << "2. DFS\n"
                  << "3. Dijkstra\n"
                  << "4. Добавить вершину\n"
                  << "5. Удалить вершину\n"
                  << "6. Добавить ребро\n"
                  << "7. Удалить ребро\n"
                  << "8. Изменить вес ребра\n"
                  << "9. Печать матрицы расстояний\n"
                  << "10. Печать матрицы смежности\n"
                  << "11. Алгоритм Флойда-Уоршелла\n"
                  << "0. Выйти\n"
                  << "Выбор: ";
        std::cin >> choice;

        int u, v, w;
        switch (choice) {
            case 1:
                std::cout << "Начало: "; std::cin >> u;
                for (int i : g.bfs(u)) std::cout << i << " ";
                std::cout << "\n";
                break;
            case 2:
                std::cout << "Начало: "; std::cin >> u;
                for (int i : g.dfs(u)) std::cout << i << " ";
                std::cout << "\n";
                break;
            case 3:
                std::cout << "Начало: "; std::cin >> u;
                for (auto [vertex, dist] : g.dijkstra(u))
                    std::cout << "Вершина " << vertex << ": " << dist << "\n";
                break;
            case 4:
                g.addVertex();
                std::cout << "Вершина добавлена.\n";
                break;
            case 5:
                std::cout << "Удалить вершину: "; std::cin >> u;
                g.removeVertex(u);
                std::cout << "Вершина удалена.\n";
                break;
            case 6:
                std::cout << "Из: "; std::cin >> u;
                std::cout << "В: "; std::cin >> v;
                std::cout << "Вес: "; std::cin >> w;
                g.addEdge(u, v, w);
                std::cout << "Ребро добавлено.\n";
                break;
            case 7:
                std::cout << "Из: "; std::cin >> u;
                std::cout << "В: "; std::cin >> v;
                g.removeEdge(u, v);
                std::cout << "Ребро удалено.\n";
                break;
            case 8:
                std::cout << "Из: "; std::cin >> u;
                std::cout << "В: "; std::cin >> v;
                std::cout << "Новый вес: "; std::cin >> w;
                g.editWeight(u, v, w);
                std::cout << "Вес изменен.\n";
                break;
            case 9:
                g.printDistanceMatrix();
                break;
            case 10:
                g.printAdjacencyMatrix();
                break;
            case 11:
                for (auto [key, val] : g.floydWarshall()) {
                    std::cout << "Из " << key.first << " в " << key.second << ": ";
                    if (val >= std::numeric_limits<int>::max() / 2)
                        std::cout << "INF";
                    else
                        std::cout << val;
                    std::cout << "\n";
                }
                break;
            case 0:
                return 0;
            default:
                std::cout << "Неверный выбор.\n";
        }
    }
}
