//
// Created by Андрей on 11.12.18.
//

#ifndef SHORTWAY_SHORTWAYSETG_H
#define SHORTWAY_SHORTWAYSETG_H

#include <iostream>
#include <vector>
#include "../GraphPoint.h"
#include "unordered_set"

class ShortWaySetG {
public:
    ShortWaySetG() = delete;
    explicit ShortWaySetG(size_t point_count);
    ShortWaySetG(const ShortWaySetG&) = delete;
    ShortWaySetG& operator=(const ShortWaySetG&) = delete;
    ~ShortWaySetG() = default;

//    friend std::ostream& operator << (std::ostream &os, ShortWayGraph &shortWayGraph);

    void AddEdge(size_t from, size_t to);
    void GetNextVertices(size_t vertex, std::vector<GraphPoint *> &vertices) const;
    void GetPoint(size_t vertex, GraphPoint* &current);

private:
    std::vector<std::unordered_multiset<GraphPoint*>> out_edges_;
    std::vector<std::unordered_multiset<GraphPoint*>> in_edges_;
    std::vector<GraphPoint> vertices_;

};

#endif //SHORTWAY_SHORTWAYSETG_H
