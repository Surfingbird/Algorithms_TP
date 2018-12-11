//
// Created by Андрей on 09.12.18.
//

#ifndef SHORTWAY_SHORTWAYGRAPH_H
#define SHORTWAY_SHORTWAYGRAPH_H

#include <iostream>
#include <vector>
#include "../GraphPoint.h"

class ShortWayGraph {
public:
    ShortWayGraph() = delete;
    explicit ShortWayGraph(size_t point_count);
    ShortWayGraph(const ShortWayGraph&) = delete;
    ShortWayGraph& operator=(const ShortWayGraph&) = delete;
    ~ShortWayGraph() = default;

    friend std::ostream& operator << (std::ostream &os, ShortWayGraph &shortWayGraph);

    void AddEdge(size_t from, size_t to);
    void GetNextVertices(size_t vertex, std::vector<GraphPoint *> &vertices) const;
    void GetPoint(size_t vertex, GraphPoint* &current);

private:
    std::vector<std::vector<GraphPoint*>> matrix;
    std::vector<GraphPoint> points;
};

#endif //SHORTWAY_SHORTWAYGRAPH_H
