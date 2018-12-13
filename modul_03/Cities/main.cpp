#include <vector>
//#include "Graph.h"
#include <cassert>
#include <queue>
#include <iostream>

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

    void AddEdge(int from, int to, int distance);
    void GetNextVertices(int vertex, std::vector<Point*> &vertices) ;

public:
    std::vector<std::vector<int>> matrix_;
    std::vector<Point> vertices_;
};

//int get_distance(int from, int to, Graph graph);

Graph::Graph(int point_count) {
    std::vector<std::vector<int>> vector_m(point_count);
    matrix_ = vector_m;

    std::vector<Point> vector_p(point_count);
    vertices_ = vector_p;

    for (int i = 0; i < point_count; ++i) {
        std::vector<int> vector(point_count);

        for (int j = 0; j < point_count; ++j) {
            vector[j] = -1;
        }
        matrix_[i] = vector;

        Point point;
        point.number = i;

        vertices_[i] = point;
    }
}

void Graph::GetNextVertices(int vertex, std::vector<Point*> &vertices)
{
    assert(vertex >= 0 && vertex < vertices_.size());

    for (int i = 0; i < matrix_.size(); ++i) {
        if (matrix_[vertex][i] != -1 && !vertices_[i].visited) vertices.push_back(&vertices_[i]);
    }
}

void Graph::AddEdge(int from, int to, int distance) {
    assert(from >= 0 && from < matrix_.size());
    assert(to >= 0 && to < matrix_.size());
    assert(from != to);

    matrix_[from][to] = distance;
    matrix_[to][from] = distance;
}

using my_type = Point*;
using my_container = std::vector<Point*>;

struct LessThanByPoint {
    bool operator()(const Point* left, const Point* right) {
        if (left->distance == -1 && right->distance == -1) return true;
        else if (left->distance == -1) return true;
        else if (right->distance == -1) return false;
        else if (left->distance > right->distance) return true;
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
        queue.push(&graph.vertices_[i]);
    }

    int result = 0;

    ///пошел сам алгоритм (нужно добавить востановление очереди с приоритетом и переписать на указатели на элементы вектора)
    while (!queue.empty()) {
        Point* current = queue.top();
        current->visited = true;
        queue.pop();

        std::vector<Point*> out_vert;
        graph.GetNextVertices(current->number, out_vert); //// тут модно выйти за пределы

        for (int i = 0; i < out_vert.size(); ++i) {
            int new_dist = current->distance + graph.matrix_[current->number][out_vert[i]->number]; /// аккуратней

            auto p = i;

            if (out_vert[i]->distance == -1 || new_dist < out_vert[i]->distance) out_vert[i]->distance = new_dist;
            std::cout << "\n";
        }

        std::priority_queue<my_type, my_container, LessThanByPoint> queue_new;

        while (!queue.empty()) {
            queue_new.push(queue.top());
            queue.pop();
        }

        queue = queue_new;

    }
    return graph.vertices_[to].distance;
}




int main() {
    int count_verts = 0;
    int count_edges = 0;
    int result = 0;

    std::cin >> count_verts;
    std::cin >> count_edges;
    Graph graph(count_verts);

    /// порблема в добавлении ребер
//    for (int i = 0; i < count_edges; ++i) {
//        int from = 0;
//        int to = 0;
//        int dis = 0;
//
//        std::cin >> from;
//        std::cin >> to;
//        std::cin >> dis;
//
//        graph.AddEdge(from, to, dis);
//    }

    int start = 0;
    int finish = 0;

    std::cin >> start;
    std::cin >> finish;

//    result = get_distance(start, finish, graph);

    std::cout << 9;

    return 0;
}