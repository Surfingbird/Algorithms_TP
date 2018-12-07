//
// Created by Андрей on 06.12.18.
//

#ifndef PROJECT_ARC_GRAPH_H
#define PROJECT_ARC_GRAPH_H

#include "../graph.hpp"

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(size_t vertices_count);
    explicit ArcGraph(const IGraph*  graph);

    void AddEdge(int from, int to) override;

    size_t VerticesCount() const override { return vertices_count; }

    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;

    void Print();

private:
    std::vector<std::pair<int, int>> edges_;
    size_t vertices_count = 0;
};

#endif //PROJECT_ARC_GRAPH_H
