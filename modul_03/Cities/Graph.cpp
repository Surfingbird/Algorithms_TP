//
// Created by Андрей on 12.12.18.
//

#include "Graph.h"
#include <cassert>
#include <vector>
#include <queue>

bool compare(Point left, Point right) {
    if (left.distance == -1 && right.distance == -1) return true;
    else if (left.distance == -1) return true;
    else if (right.distance == -1) return false;
    else if (left.distance > right.distance) return true;
    else return false;
}

Graph::Graph(int point_count) {
    for (int i = 0; i < point_count; ++i) {
        std::vector<int> vector;

        for (int j = 0; j < point_count; ++j) {
            vector.push_back(-1);
        }
        matrix_.push_back(vector);

        Point point;
        point.number = i;

        vertices_.push_back(point);
    }
}

void Graph::GetNextVertices(int vertex, std::vector<Point> &vertices)
{
    assert(vertex >= 0 && vertex < matrix_.size());

    for (int i = 0; i < matrix_.size(); ++i) {
        if (matrix_[vertex][i] != -1 && !vertices_[i].visited) vertices.push_back(vertices_[i]);
    }
}

void Graph::AddEdge(int from, int to, int distance) {
    assert(from >= 0 && from < matrix_.size());
    assert(to >= 0 && to < matrix_.size());
    assert(from != to);

    matrix_[from][to] = distance;
    matrix_[to][from] = distance;
}

int Graph::GetDistance(int from, int to) {
    assert(from >= 0 && from < matrix_.size());
    assert(to >= 0 && to < matrix_.size());
    assert(matrix_[from][to] != -1);

    return matrix_[from][to];
}

using my_type = Point;
using my_container = std::vector<Point>;

struct LessThanByPoint {
    bool operator()(const Point& left, const Point& right) {
        if (left.distance == -1 && right.distance == -1) return true;
        else if (left.distance == -1) return true;
        else if (right.distance == -1) return false;
        else if (left.distance > right.distance) return true;
        else return false;
    }
};

int get_distance(int from, int to, Graph graph) {
    assert(from >= 0 && from < graph.matrix_.size());
    assert(to >= 0 && to < graph.matrix_.size());

    if (from == to) return 0; /// не ну вдруг)

    graph.vertices_[from].distance = 0;
    graph.vertices_[from].visited = true;

    std::priority_queue<my_type, my_container, LessThanByPoint> queue;

    /// здесь костыль на построение очереди с приоритетом
    for (int i = 0; i < graph.vertices_.size(); ++i) {
        queue.push(graph.vertices_[i]);
    }

    /// думаю, что все таки точки из вектора и точки и точки из очереди - не одно и то же!!!

    int result = 0;

    ///пошел сам алгоритм (нужно добавить востановление очереди с приоритетом и переписать на указатели на элементы вектора)
    while (!queue.empty()) {
        Point current = queue.top();
        current.visited = true;
        queue.pop();

        std::vector<Point> out_vert;
        graph.GetNextVertices(current.number, out_vert);

        for (auto i = out_vert.begin(); i != out_vert.end(); ++i) {
            int new_dist = current.distance + graph.matrix_[current.distance][(*i).number]; /// аккуратней

            if ((*i).distance == -1) (*i).distance = new_dist;
            if ((*i).number == to) result = (*i).distance;
        }

        if (result) break;
    }
    return result;
}


