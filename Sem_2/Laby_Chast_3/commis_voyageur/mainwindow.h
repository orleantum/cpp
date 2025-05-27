#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QMap>
#include <QVector>

struct Edge {
    int from;
    int to;
    int weight;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addNodeButton_clicked();
    void on_addEdgeButton_clicked();
    void on_removeEdgeButton_clicked();
    void on_solveTSPButton_clicked();

private:
    QGraphicsView *graphicsView;
    QGraphicsScene *scene;
    int nodeCount;
    QVector<QGraphicsEllipseItem*> nodes;
    QVector<Edge> edges;
    QMap<QPair<int, int>, QGraphicsLineItem*> edgeItems;
    QVector<QVector<int>> adjacencyMatrix;

    void initializeDefaultGraph();

    void drawGraph();
    void solveTSP();

    QVector<QGraphicsTextItem*> nodeLabels; // Для хранения подписей вершин

};

#endif // MAINWINDOW_H
