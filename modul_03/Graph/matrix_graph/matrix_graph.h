//
// Created by Андрей on 06.12.18.
//

#ifndef PROJECT_MATRIX_GRAPH_H
#define PROJECT_MATRIX_GRAPH_H

#include "../graph.hpp"
#include <iostream>

class MatrixGraph : public IGraph {
public:
    explicit MatrixGraph(size_t vertices_count);
    explicit MatrixGraph(const IGraph*  graph);

    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to) override ;

    virtual size_t VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;

    void Print();

private:
    std::vector<std::vector<bool>> edges_;
};

#endif //PROJECT_MATRIX_GRAPH_H
