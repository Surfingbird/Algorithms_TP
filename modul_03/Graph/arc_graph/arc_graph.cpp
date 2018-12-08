//
// Created by Андрей on 06.12.18.
//

#include "arc_graph.h"
#include "iostream"
#include <assert.h>

ArcGraph::ArcGraph(size_t vertices_count)
        : vertices_count(vertices_count)
{}

void ArcGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < VerticesCount());
    assert(to >= 0 && to < VerticesCount());

    edges_.push_back(std::make_pair(from, to));
}

ArcGraph::ArcGraph(const IGraph *graph) {
    assert (nullptr != graph);


    for (int i = 0; i < graph->VerticesCount(); ++i) {
        std::vector<int> vertices;

        graph->GetNextVertices(i, vertices);

        for (auto j = vertices.begin(); j != vertices.end(); ++j) {
            edges_.push_back(std::make_pair(i, *j));
        }
    }
}

void ArcGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex >= 0 && vertex < VerticesCount());

    for (auto i = edges_.begin(); i != edges_.end(); ++i) {
        if (vertex == (*i).second) vertices.push_back((*i).first);
    }
}

void ArcGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex >= 0 && vertex < VerticesCount());

    for (auto i = edges_.begin(); i != edges_.end(); ++i) {
        if (vertex == (*i).first) vertices.push_back((*i).second);
    }
}

void ArcGraph::Print() {
    for (int i = 0; i < vertices_count; ++i) {
        std::cout << " in : {";
        for (auto j = edges_.begin(); j != edges_.end(); ++j) {
            if ((*j).second == i) std::cout << (*j).first << ", ";
        }
        std::cout << "} " << "-->" << i << "-->" << " out : {";
        for (auto j = edges_.begin(); j != edges_.end(); ++j) {
            if ((*j).first == i) std::cout << (*j).second << ", ";
        }
        std::cout << "} " << std::endl;
    }
}
