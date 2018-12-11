//
// Created by Андрей on 11.12.18.
//

#include <iostream>
#include <iostream>
#include <vector>
#include <assert.h>
#include <queue>
#include "unordered_set"

class GraphPoint {
public:
    GraphPoint() = delete;
    explicit GraphPoint(size_t number) : point_number(number) {}
    ~GraphPoint() = default;

    std::string colour = "white";
    size_t point_number;
};

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
    ///std::vector<std::unordered_multiset<GraphPoint*>> in_edges_;
    std::vector<GraphPoint> vertices_;

};

template <typename T>
size_t search_way(size_t search_from, size_t search_to, T &graph) {
    std::queue<GraphPoint*> queue;
    std::queue<GraphPoint*> layer_queue;

    GraphPoint* current = nullptr;
    graph.GetPoint(search_from, current);

    queue.push(current);
    queue.push(nullptr);

    size_t step = 0;
    size_t result = 0;

    while (!queue.empty()) {
        current = queue.front();
        queue.pop();

        if (nullptr == current && queue.size() > 0 && result == 0) {
            queue.push(nullptr); /// вот тут по аккуратней
        }
        if (nullptr == current) {
            ++step;

            while (!layer_queue.empty()) {
                GraphPoint* layers_point = layer_queue.front();
                layers_point->colour = "grey";
                layer_queue.pop();
            }

            continue;
        }

        if(search_to == current->point_number) { /// появиля путь до точки !!! поправить
            ++result;
            continue;
        }

        if (0 == result) {
            current->colour = "black";

            std::vector<GraphPoint*> out_edges;
            graph.GetNextVertices(current->point_number, out_edges); /// вот это мне не понравилось

            for (auto i = out_edges.begin(); i != out_edges.end(); ++i) {

                if ("black" == (*i)->colour || "grey" == (*i)->colour) continue; /// уже посещенная вершина
//                if (current->length == (*i)->length) continue;

//                if ((*i)->length == 0 || (*i)->length == step + 1) {
//                    (*i)->length = step + 1;
                queue.push(*i);
                layer_queue.push(*i);
            }
        }
    }

    return result;
}

ShortWaySetG::ShortWaySetG(size_t point_count) {
    for (size_t i = 0; i < point_count; ++i) {
        std::unordered_multiset<GraphPoint*> multiset;
        out_edges_.push_back(multiset); /// как бы он был не один
        //in_edges_.push_back(multiset);

        vertices_.push_back(GraphPoint(i));
    }
}

void ShortWaySetG::GetNextVertices(size_t vertex, std::vector<GraphPoint *> &vertices) const {
    for (auto i = out_edges_[vertex].begin(); i != out_edges_[vertex].end(); ++i) {
        vertices.push_back(*i);
    }
}

void ShortWaySetG::GetPoint(size_t vertex, GraphPoint *&current) {
    assert(vertex >= 0 && vertex < vertices_.size());

    current = &vertices_[vertex];
}

void ShortWaySetG::AddEdge(size_t from, size_t to) {
    assert(from >= 0 && from < vertices_.size());
    assert(to >= 0 && to < vertices_.size());

    GraphPoint *point = nullptr;

    GetPoint(to, point);
    //in_edges_[from].insert(point);
    out_edges_[from].insert(point);

    GetPoint(from, point);
    ///in_edges_[to].insert(point);
    out_edges_[to].insert(point);
}

int main() {
    size_t count_points = 0;
    size_t count_edge = 0;

    std::cin >> count_points >> count_edge;
    ShortWaySetG shortWaySetG(count_points);

    for (size_t i = 0; i < count_edge; ++i) {
        size_t from = 0;     /// не красиво, согласен!
        size_t to = 0;       /// не красиво, согласен!
        std::cin >> from >> to;
        shortWaySetG.AddEdge(from, to);
    }

    size_t search_from = 0;
    size_t search_to = 0;

    std::cin >> search_from >> search_to;

    size_t result = search_way(search_from, search_to, shortWaySetG);

    std::cout << result;
    return 0;
}