#include <iostream>
#include <iostream>
#include <vector>
#include <assert.h>
#include <queue>

class GraphPoint {
public:
    GraphPoint() = delete;
    explicit GraphPoint(size_t number) : point_number(number) {}
    ~GraphPoint() = default;

    std::string colour = "white";
    size_t length = 0;
    size_t point_number;
};

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

size_t search_way(size_t search_from, size_t search_to, ShortWayGraph &graph) {
    std::queue<GraphPoint*> queue;

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
            continue;
        }

        if(search_to == current->point_number) { /// появиля путь до точки !!! поправить
            ++result;
            continue;
        }

        if (0 == result) {
            current->colour = "black";
            current->length = step; /// растояние от начала к узлу

            std::vector<GraphPoint*> out_edges;
            graph.GetNextVertices(current->point_number, out_edges); /// вот это мне не понравилось

            for (auto i = out_edges.begin(); i != out_edges.end(); ++i) {

                if ("black" == (*i)->colour) continue; /// уже посещенная вершина
//                if (current->length == (*i)->length) continue;
                if ((*i)->length == 0 || (*i)->length == step + 1) {
                    (*i)->length = step + 1;
                    queue.push(*i);
                }
            }
        }
    }


    return result;
}

ShortWayGraph::ShortWayGraph(size_t point_count)
{
    for (size_t i = 0; i < point_count; ++i) {
        points.push_back(GraphPoint(i));

        std::vector<GraphPoint*> vector;

        for (size_t j = 0; j < point_count; ++j) {
            vector.push_back(nullptr);
        }
        matrix.push_back(vector);
    }
}

void ShortWayGraph::GetPoint(size_t vertex, GraphPoint* &current)  {
    assert(vertex >= 0 && vertex < points.size());

    current = &points[vertex];
    return;
}

void ShortWayGraph::AddEdge(size_t from, size_t to) {
    assert(from >= 0 && from < points.size());
    assert(to >= 0 && to < points.size());

    matrix[from][to] = &points[to];
}

void ShortWayGraph::GetNextVertices(size_t vertex, std::vector<GraphPoint *> &vertices) const {
    assert(vertex >= 0 && vertex < points.size());

    for (auto i = matrix[vertex].begin(); i != matrix[vertex].end(); ++i) {
        if (nullptr != *i) vertices.push_back(*i);
    }
}

std::ostream& operator << (std::ostream &os, ShortWayGraph &shortWayGraph) {
    for (auto i = shortWayGraph.matrix.begin(); i != shortWayGraph.matrix.end(); ++i) {
        for (auto j = (*i).begin(); j != (*i).end(); ++j) {
            if (nullptr == *j) os << "NONE_ ";
            else os << (*j)->colour << " ";
        }
        os << "\n";
    }
}



int main() {
    size_t count_points = 0;
    size_t count_edge = 0;

    std::cin >> count_points >> count_edge;
    ShortWayGraph shortWayGraph(count_points);

    for (size_t i = 0; i < count_edge; ++i) {
        size_t from = 0;     /// не красиво, согласен!
        size_t to = 0;       /// не красиво, согласен!
        std::cin >> from >> to;
        shortWayGraph.AddEdge(from, to);
    }

    size_t search_from = 0;
    size_t search_to = 0;

    std::cin >> search_from >> search_to;

    size_t result = search_way(search_from, search_to, shortWayGraph);

    std::cout << result;
    return 0;
}