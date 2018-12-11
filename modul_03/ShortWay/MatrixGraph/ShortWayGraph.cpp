//
// Created by Андрей on 09.12.18.
//

#include "ShortWayGraph.h"
#include <iostream>
#include <assert.h>

ShortWayGraph::ShortWayGraph(size_t point_count)
{
    for (size_t i = 0; i < point_count; ++i) {
        points.push_back(GraphPoint(i));

        std::vector<GraphPoint*> vector;

        for (size_t j = 0; j < point_count; ++j) {
            vector.push_back(nullptr);
        }
        matrix.push_back(vector);
    }
}

void ShortWayGraph::GetPoint(size_t vertex, GraphPoint* &current)  {
    assert(vertex >= 0 && vertex < points.size());

    current = &points[vertex];
    return;
}

void ShortWayGraph::AddEdge(size_t from, size_t to) {
    assert(from >= 0 && from < points.size());
    assert(to >= 0 && to < points.size());

    matrix[from][to] = &points[to];
    matrix[to][from] = &points[from];
}

void ShortWayGraph::GetNextVertices(size_t vertex, std::vector<GraphPoint *> &vertices) const {
    assert(vertex >= 0 && vertex < points.size());

    for (auto i = matrix[vertex].begin(); i != matrix[vertex].end(); ++i) {
        if (nullptr != *i) vertices.push_back(*i);
    }
}

std::ostream& operator << (std::ostream &os, ShortWayGraph &shortWayGraph) {
    for (auto i = shortWayGraph.matrix.begin(); i != shortWayGraph.matrix.end(); ++i) {
        for (auto j = (*i).begin(); j != (*i).end(); ++j) {
            if (nullptr == *j) os << "NONE_ ";
            else os << (*j)->colour << " ";
        }
        os << "\n";
    }
}
