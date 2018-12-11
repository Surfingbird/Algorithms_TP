//
// Created by Андрей on 11.12.18.
//

#ifndef SHORTWAY_MATRIXMANYGRAPH_H
#define SHORTWAY_MATRIXMANYGRAPH_H

#include <iostream>
#include <vector>

class GraphPoint {
public:
    GraphPoint() = delete;
    explicit GraphPoint(int number) : point_number(number) {}
    ~GraphPoint() = default;

    std::string colour = "white";
    int length = 0;
    int point_number;
};


class MatrixManyGraph {
public:
    MatrixManyGraph() = delete;
    explicit MatrixManyGraph(int point_count);
    MatrixManyGraph(const MatrixManyGraph&) = delete;
    MatrixManyGraph& operator=(const MatrixManyGraph&) = delete;
    ~MatrixManyGraph() = default;

    friend int search_way_02(int search_from, int search_to, MatrixManyGraph &graph);

    void AddEdge(int from, int to);
    void GetNextVertices(int vertex, std::vector<int> &vertices) ;

    friend std::ostream& operator << (std::ostream &os, MatrixManyGraph &shortWayGraph);

private:
    std::vector<std::vector<int>> matrix_;
    std::vector<GraphPoint> vertices_;
};

#endif //SHORTWAY_MATRIXMANYGRAPH_H
