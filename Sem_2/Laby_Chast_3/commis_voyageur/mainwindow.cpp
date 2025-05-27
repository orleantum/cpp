#include "mainwindow.h"
#include <QGraphicsTextItem>
#include <QInputDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QRandomGenerator>
#include <limits>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), nodeCount(0) {

    // Создаем виджеты
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    graphicsView = new QGraphicsView(this);
    scene = new QGraphicsScene(this);
    graphicsView->setScene(scene);
    graphicsView->setMinimumSize(600, 400);
    scene->setBackgroundBrush(Qt::white);  // Белый фон сцены
    graphicsView->setStyleSheet("background-color: white;");  // Белый фон для области просмотра


    QPushButton *addNodeButton = new QPushButton("Добавить вершину");
    QPushButton *addEdgeButton = new QPushButton("Добавить ребро");
    QPushButton *removeEdgeButton = new QPushButton("Удалить ребро");
    QPushButton *solveTSPButton = new QPushButton("Решить TSP");

    layout->addWidget(graphicsView);
    layout->addWidget(addNodeButton);
    layout->addWidget(addEdgeButton);
    layout->addWidget(removeEdgeButton);
    layout->addWidget(solveTSPButton);

    setCentralWidget(centralWidget);

    // Соединяем кнопки
    connect(addNodeButton, &QPushButton::clicked, this, &MainWindow::on_addNodeButton_clicked);
    connect(addEdgeButton, &QPushButton::clicked, this, &MainWindow::on_addEdgeButton_clicked);
    connect(removeEdgeButton, &QPushButton::clicked, this, &MainWindow::on_removeEdgeButton_clicked);
    connect(solveTSPButton, &QPushButton::clicked, this, &MainWindow::on_solveTSPButton_clicked);

    initializeDefaultGraph();

}

MainWindow::~MainWindow() {}

void MainWindow::on_addNodeButton_clicked() {
    int x = QRandomGenerator::global()->bounded(400);
    int y = QRandomGenerator::global()->bounded(400);
    QGraphicsEllipseItem *node = scene->addEllipse(x, y, 30, 30, QPen(), QBrush(Qt::yellow));
    QGraphicsTextItem *label = scene->addText(QString::number(nodeCount));
    label->setDefaultTextColor(Qt::black);
    label->setPos(x + 10, y + 5);

    nodes.append(node);
    nodeLabels.append(label);
    nodeCount++;


    int newSize = nodeCount;
    adjacencyMatrix.resize(newSize);
    for (auto &row : adjacencyMatrix) row.resize(newSize, std::numeric_limits<int>::max());
    for (int i = 0; i < newSize; ++i) adjacencyMatrix[i][i] = 0;
}

void MainWindow::on_addEdgeButton_clicked() {
    bool ok1, ok2, ok3;
    int from = QInputDialog::getInt(this, "From Node", "From:", 0, 0, nodeCount-1, 1, &ok1);
    int to = QInputDialog::getInt(this, "To Node", "To:", 0, 0, nodeCount-1, 1, &ok2);
    int weight = QInputDialog::getInt(this, "Weight", "Weight:", 1, 1, 1000, 1, &ok3);
    if (ok1 && ok2 && ok3) {
        adjacencyMatrix[from][to] = weight;
        adjacencyMatrix[to][from] = weight; // симметричный граф
        edges.append({from, to, weight});
        drawGraph();
    }
}

void MainWindow::on_removeEdgeButton_clicked() {
    bool ok1, ok2;
    int from = QInputDialog::getInt(this, "From Node", "From:", 0, 0, nodeCount-1, 1, &ok1);
    int to = QInputDialog::getInt(this, "To Node", "To:", 0, 0, nodeCount-1, 1, &ok2);
    if (ok1 && ok2) {
        adjacencyMatrix[from][to] = std::numeric_limits<int>::max();
        adjacencyMatrix[to][from] = std::numeric_limits<int>::max();
        drawGraph();
    }
}

void MainWindow::drawGraph() {
    for (auto item : edgeItems) scene->removeItem(item);
    edgeItems.clear();

    for (const Edge &e : edges) {
        if (adjacencyMatrix[e.from][e.to] != std::numeric_limits<int>::max()) {
            QPointF p1 = nodes[e.from]->rect().center() + nodes[e.from]->pos();
            QPointF p2 = nodes[e.to]->rect().center() + nodes[e.to]->pos();
            QGraphicsLineItem *line = scene->addLine(QLineF(p1, p2), QPen(Qt::black, 2));
            edgeItems[{e.from, e.to}] = line;
            auto text = scene->addText(QString::number(e.weight));
            text->setPos((p1 + p2) / 2);
        }
    }
}

void MainWindow::on_solveTSPButton_clicked() {
    solveTSP();
}

void MainWindow::solveTSP() {
    int n = nodeCount;
    QVector<bool> visited(n, false);
    QVector<int> path(n + 1);
    int bestCost = std::numeric_limits<int>::max();
    QVector<int> bestPath;

    std::function<void(int, int, int)> dfs = [&](int pos, int count, int cost) {
        if (cost >= bestCost) return;
        if (count == n && adjacencyMatrix[pos][0] < std::numeric_limits<int>::max()) {
            int totalCost = cost + adjacencyMatrix[pos][0];
            if (totalCost < bestCost) {
                bestCost = totalCost;
                bestPath = path.mid(0, count);
                bestPath.append(0);
            }
            return;
        }
        for (int next = 0; next < n; ++next) {
            if (!visited[next] && adjacencyMatrix[pos][next] < std::numeric_limits<int>::max()) {
                visited[next] = true;
                path[count] = next;
                dfs(next, count + 1, cost + adjacencyMatrix[pos][next]);
                visited[next] = false;
            }
        }
    };

    visited[0] = true;
    path[0] = 0;
    dfs(0, 1, 0);

    if (bestPath.isEmpty()) {
        QMessageBox::information(this, "TSP Result", "No tour found.");
    } else {
        QString result = "Best tour: ";
        for (int node : bestPath) result += QString::number(node) + " -> ";
        result.chop(4);
        result += "\nCost: " + QString::number(bestCost);
        QMessageBox::information(this, "TSP Result", result);
    }
}

void MainWindow::initializeDefaultGraph() {
    QVector<QPair<int, int>> positions = {
        {100, 100}, {300, 100}, {500, 100}, {200, 300}, {400, 300}, {300, 500}
    };

    // Создаем 6 вершин
    for (int i = 0; i < positions.size(); ++i) {
        auto [x, y] = positions[i];
        QGraphicsEllipseItem *node = scene->addEllipse(x, y, 30, 30, QPen(), QBrush(Qt::yellow));
        QGraphicsTextItem *label = scene->addText(QString::number(i));
        label->setDefaultTextColor(Qt::black);
        label->setPos(x + 10, y + 5);
        nodes.append(node);
        nodeLabels.append(label);
        nodeCount++;
    }


    // Инициализация матрицы смежности
    adjacencyMatrix.resize(nodeCount);
    for (auto &row : adjacencyMatrix) row.resize(nodeCount, std::numeric_limits<int>::max());
    for (int i = 0; i < nodeCount; ++i) adjacencyMatrix[i][i] = 0;

    // Добавляем рёбра
    struct { int from, to, weight; } edgesToAdd[] = {
        {0,1,11}, {1,0,11}, {0,5,7}, {5,0,7}, {0,2,21}, {2,0,21},
        {0,3,13}, {3,0,13}, {0,4,9}, {4,0,9}, {1,3,6}, {3,1,6},
        {1,2,14}, {2,1,14}, {1,4,10}, {4,1,10}, {1,5,12}, {5,1,12},
        {2,3,8}, {3,2,8}, {2,4,3}, {4,2,3}, {2,5,20}, {5,2,20},
        {3,4,15}, {4,3,15}, {3,5,11}, {5,3,11}, {4,5,18}, {5,4,18}
    };

    for (auto &e : edgesToAdd) {
        adjacencyMatrix[e.from][e.to] = e.weight;
        edges.append({e.from, e.to, e.weight});
    }

    drawGraph();
}
