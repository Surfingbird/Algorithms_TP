//
// Created by Андрей on 11.12.18.
//
#include <iostream>
#include <vector>
#include <assert.h>
#include <queue>

class GraphPoint {
public:
    GraphPoint() = delete;
    explicit GraphPoint(int number) : point_number(number) {}
    ~GraphPoint() = default;

    std::string colour = "white";
    int length = 0;
    int point_number;
};


class MatrixManyGraph {
public:
    MatrixManyGraph() = delete;
    explicit MatrixManyGraph(int point_count);
    MatrixManyGraph(const MatrixManyGraph&) = delete;
    MatrixManyGraph& operator=(const MatrixManyGraph&) = delete;
    ~MatrixManyGraph() = default;

    friend int search_way_02(int search_from, int search_to, MatrixManyGraph &graph);

    void AddEdge(int from, int to);
    void GetNextVertices(int vertex, std::vector<int> &vertices) ;
    void GetPoint(int vertex, GraphPoint* &current);

private:
    std::vector<std::vector<int>> matrix_;
    std::vector<GraphPoint> vertices_;
};

MatrixManyGraph::MatrixManyGraph(int point_count)

{
    for (int i = 0; i < point_count; ++i) {
        vertices_.push_back(GraphPoint(i));
    }

    for (int i = 0; i < point_count; ++i) {
        std::vector<int> ways;
        for (size_t j = 0; j < point_count; ++j) {
            ways.push_back(0);
        }
        matrix_.push_back(ways);
    }
}

void MatrixManyGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < vertices_.size());
    assert(to >= 0 && to < vertices_.size());

    if (from != to) {
        ++matrix_[from][to];
        ++matrix_[to][from];
    } else {
        ++matrix_[from][to];
    }
}

void MatrixManyGraph::GetNextVertices(int vertex, std::vector<int> &vertices) {
    for (int i = 0; i < matrix_[vertex].size(); ++i) {
        if (0 == matrix_[vertex][i]) continue;
        for (size_t j = 0; j < matrix_[vertex][i]; ++j) vertices.push_back(i);
    }
}

void MatrixManyGraph::GetPoint(int vertex, GraphPoint *&current) {

}

int search_way_02(int search_from, int search_to, MatrixManyGraph &graph) {
    std::queue<int> queue;
    std::queue<int> layer_queue;

    int current = search_from;
    int step = 0;

    queue.push(current);
    queue.push(-1);

    int result = 0; /// можно еще на отсутствие путей проверять

    while (!queue.empty()) {
        current = queue.front();
        queue.pop();

        if (-1 == current && queue.size() > 0 && result == 0) {
            queue.push(-1); /// вот тут по аккуратней
        }
        if (-1 == current) {
            ++step;

            while (!layer_queue.empty()) {
                int layers_point = layer_queue.front();
                graph.vertices_[layers_point].colour = "grey";
                layer_queue.pop();
            }

            continue;
        }

        if(search_to == current) { /// появиля путь до точки !!! поправить
            ++result;
            continue;
        }

        if (0 == result) {
            graph.vertices_[current].colour = "black";
            graph.vertices_[current].length = step; /// растояние от начала к узлу

            std::vector<int> out_edges;
            graph.GetNextVertices(current, out_edges); /// вот это мне не понравилось

            for (int i = 0; i < out_edges.size(); ++i) {

                if ("black" ==  graph.vertices_[out_edges[i]].colour || "grey" == graph.vertices_[out_edges[i]].colour) continue; /// уже посещенная вершина
//                if (current->length == (*i)->length) continue;

//                if ((*i)->length == 0 || (*i)->length == step + 1) {
//                    (*i)->length = step + 1;
                queue.push(out_edges[i]);
                layer_queue.push(out_edges[i]);
            }
        }
    }

    return result;
}

int main() {
    int count_points = 0;
    int count_edge = 0;

    std::cin >> count_points >> count_edge;
    MatrixManyGraph shortWayGraph(count_points);

    for (int i = 0; i < count_edge; ++i) {
        int from = 0;     /// не красиво, согласен!
        int to = 0;       /// не красиво, согласен!
        std::cin >> from >> to;
        shortWayGraph.AddEdge(from, to);
    }

    int search_from = 0;
    int search_to = 0;

    std::cin >> search_from >> search_to;

    int result = search_way_02(search_from, search_to, shortWayGraph);

    std::cout << result;
    return 0;
}