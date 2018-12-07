//
// Created by Андрей on 06.12.18.
//

#ifndef PROJECT_SET_GRAPH_H
#define PROJECT_SET_GRAPH_H

#pragma once

#include <iostream>
#include "../graph.hpp"
#include <vector>
#include <map>
#include <initializer_list>
#include <unordered_set>

class SetGraph : public IGraph {
public:
    explicit SetGraph() : out_edges_(0), in_edges_(0) {}
    explicit SetGraph(size_t vertices_count);
    explicit SetGraph(const IGraph *graph);

    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to) override ;

    virtual size_t VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;

    void Print();

private:
    std::vector<std::unordered_multiset<int>> out_edges_;
    std::vector<std::unordered_multiset<int>> in_edges_;
};

#endif //PROJECT_SET_GRAPH_H
