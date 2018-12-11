//
// Created by Андрей on 11.12.18.
//

#ifndef SHORTWAY_GRAPHPOINT_H
#define SHORTWAY_GRAPHPOINT_H

class GraphPoint {
public:
    GraphPoint() = delete;
    explicit GraphPoint(size_t number) : point_number(number) {}
    ~GraphPoint() = default;

    std::string colour = "white";
    size_t length = 0;
    size_t point_number;
};


#endif //SHORTWAY_GRAPHPOINT_H
