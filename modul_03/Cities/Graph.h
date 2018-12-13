//
// Created by Андрей on 12.12.18.
//

#ifndef CITIES_GRAPH_H
#define CITIES_GRAPH_H

#include <vector>

struct Point {
    int distance = -1; /// должна быть изначально бесконечная
    int number = -1;
    bool visited = false;
};

class Graph {
public:
    Graph() = delete;
    explicit Graph(int point_count);
//    Graph(const Graph&) = delete;
    Graph& operator=(const Graph&) = delete;
    ~Graph() = default;

//    friend int get_distance(int from, int to, Graph graph) const;

    int GetDistance(int from, int to);
    void AddEdge(int from, int to, int distance);
    void GetNextVertices(int vertex, std::vector<Point*> &vertices) ;

public:
    std::vector<std::vector<int>> matrix_;
    std::vector<Point> vertices_;
};

int get_distance(int from, int to, Graph graph);

#endif //CITIES_GRAPH_H
