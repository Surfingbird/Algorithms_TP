//
// Created by Андрей on 06.12.18.
//

#include "matrix_graph.h"
#include "assert.h"

MatrixGraph::MatrixGraph(size_t vertices_count)
        : edges_(vertices_count)
{
    for (int i = 0; i < edges_.size(); ++i) {
        for (int j = 0; j < edges_.size(); ++j) {
            edges_[i].push_back(false);
        }
    }
}

MatrixGraph::MatrixGraph(const IGraph *graph) {

    for (int i = 0; i < graph->VerticesCount(); ++i) {
        for (int j = 0; j < graph->VerticesCount(); ++j) {
            edges_[i].push_back(false);
        }
    }

    for (int i = 0; i < graph->VerticesCount(); ++i) {
        std::vector<int> vertices;

        graph->GetNextVertices(i, vertices);

        for (auto j = vertices.begin(); j != vertices.end(); ++j) edges_[i][*j] = true;
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < VerticesCount());
    assert(to >= 0 && to < VerticesCount());

    edges_[from][to] = true;
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex >= 0 && vertex < VerticesCount());

    for (int i = 0; i < edges_.size(); ++i) {
        if (edges_[i][vertex]) vertices.push_back(i);
    }
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex >= 0 && vertex < VerticesCount());

    for (int i = 0; i < edges_.size(); ++i) {
        if (edges_[vertex][i]) vertices.push_back(i);
    }
}

void MatrixGraph::Print() {
    for (int i = 0; i < edges_.size(); ++i) {
        std::cout << " in : {";
        for (int j= 0; j < edges_.size(); ++j) {
            if (edges_[j][i])  std::cout << j << ", ";
        }
        std::cout << "} " << "-->" << i << "-->" << " out : {";
        for (int j= 0; j < edges_.size(); ++j) {
            if (edges_[i][j])  std::cout << j << ", ";
        }
        std::cout << "} " << std::endl;
    }
}

size_t MatrixGraph::VerticesCount() const {
    return edges_.size();
}