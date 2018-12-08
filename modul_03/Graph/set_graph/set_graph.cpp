//
// Created by Андрей on 06.12.18.
//

#include "set_graph.h"
#include <assert.h>
#include <unordered_set>

SetGraph::SetGraph(size_t vertices_count)
        : out_edges_(vertices_count), in_edges_(vertices_count)
{}

SetGraph::SetGraph(const IGraph *graph) {
    assert (nullptr != graph);

    for (int i = 0; i < graph->VerticesCount(); ++i) {
        std::unordered_multiset<int> multiset_in;
        std::unordered_multiset<int> multiset_out;

        std::vector<int>vertices;

        graph->GetPrevVertices(i, vertices);
        for (auto j = vertices.begin(); j != vertices.end(); ++j) multiset_in.insert(*j);
        in_edges_.push_back(multiset_in);

        graph->GetNextVertices(i, vertices);
        for (auto j = vertices.begin(); j != vertices.end(); ++j) multiset_out.insert(*j);
        out_edges_.push_back(multiset_out);
    }
}

void SetGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < VerticesCount());
    assert(to >= 0 && to < VerticesCount());

    //(multigraph)
    out_edges_[from].insert(to);
    in_edges_[to].insert(from);
}

void SetGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex >= 0 && vertex < VerticesCount());

    for (auto i = in_edges_[vertex].begin(); i != out_edges_[vertex].end(); ++i) {
        vertices.push_back(*i);
    }
}

void SetGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex >= 0 && vertex < VerticesCount());

    for (auto i = out_edges_[vertex].begin(); i != out_edges_[vertex].end(); ++i) {
        vertices.push_back(*i);
    }
}

size_t SetGraph::VerticesCount() const { return out_edges_.size(); }

void SetGraph::Print() {
    for (size_t i = 0; i < out_edges_.size(); ++i) {
        std::cout << " in : {";
        for (auto j = in_edges_[i].begin(); j != out_edges_[i].end(); ++j) {
            std::cout << *j << ", ";
        }
        std::cout << "} " << "-->" << i << "-->" << " out : {";
        for (auto j = out_edges_[i].begin(); j != out_edges_[i].end(); ++j) {
            std::cout << *j << ", ";
        }
        std::cout << "} " << std::endl;
    }
}