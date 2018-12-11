//
// Created by Андрей on 11.12.18.
//

#include "ShortWaySetG.h"
#include "assert.h"


ShortWaySetG::ShortWaySetG(size_t point_count) {
    for (size_t i = 0; i < point_count; ++i) {
        std::unordered_multiset<GraphPoint*> multiset;
        out_edges_.push_back(multiset); /// как бы он был не один
        in_edges_.push_back(multiset);

        vertices_.push_back(GraphPoint(i));
    }
}

void ShortWaySetG::GetNextVertices(size_t vertex, std::vector<GraphPoint *> &vertices) const {
    for (auto i = out_edges_[vertex].begin(); i != out_edges_[vertex].end(); ++i) {
        vertices.push_back(*i);
    }
}

void ShortWaySetG::GetPoint(size_t vertex, GraphPoint *&current) {
    assert(vertex >= 0 && vertex < vertices_.size());

    current = &vertices_[vertex];
}

void ShortWaySetG::AddEdge(size_t from, size_t to) {
    assert(from >= 0 && from < vertices_.size());
    assert(to >= 0 && to < vertices_.size());

    GraphPoint *point = nullptr;

    GetPoint(to, point);
    in_edges_[from].insert(point);
    out_edges_[from].insert(point);

    GetPoint(from, point);
    in_edges_[to].insert(point);
    out_edges_[to].insert(point);
}

