//
// Created by Андрей on 12.12.18.
//

#include <gtest/gtest.h>
#include "Graph.h"
#include <vector>
#include <queue>

TEST(Graph, simple_01) {
    Graph graph(4);

    EXPECT_TRUE(graph.matrix_[1][1] == -1);
}

TEST(Graph, simple_02) {
    Graph graph(4);
    graph.AddEdge(1, 2, 10);

    EXPECT_TRUE(graph.matrix_[1][2] == 10);
    EXPECT_TRUE(graph.matrix_[2][1] == 10);
}

/// возможная опасность, тут могут быть проблемы
//TEST(Graph, simple_03) {
//    Graph graph(4);
//    graph.AddEdge(1, 0, 10);
//    graph.AddEdge(1, 2, 10);
//    graph.AddEdge(1, 3, 10);
//
//    Point p1; p1.distance = 2; p1.number = 1;
//    Point p2; p2.distance = 3; p2.number = 2;
//    Point p3; p3.distance = 3; p3.number = 3;
//    Point p4; p4.distance = 4; p4.number = 4;
//
//
//
//    std::vector<bool> visited = {false, false, false, false};
//
//    std::vector<int> expected = {0, 2, 3};
//    std::vector<int> real;
//
//    graph.GetNextVertices(1, real, visited);
//
//    EXPECT_EQ(real, expected);
//}
//
//TEST(Graph, simple_04) {
//    Graph graph(4);
//    graph.AddEdge(1, 0, 10);
//    graph.AddEdge(1, 2, 10);
//    graph.AddEdge(1, 3, 10);
//
//    std::vector<bool> visited = {true, true, true, false};
//
//    std::vector<int> expected = {3};
//    std::vector<int> real;
//
//    graph.GetNextVertices(1, real, visited);
//
//    EXPECT_EQ(real, expected);
//}
//
//TEST(Graph, simple_05) {
//    Graph graph(4);
//    graph.AddEdge(1, 0, 10);
//    graph.AddEdge(1, 2, 10);
//    graph.AddEdge(1, 3, 10);
//
//    std::vector<bool> visited = {true, true, true, true};
//
//    std::vector<int> expected = {};
//    std::vector<int> real;
//
//    graph.GetNextVertices(1, real, visited);
//
//    EXPECT_EQ(real, expected);
//}

//TEST(Graph, simple_06) {
//    Point p1; p1.distance = 3;
//    Point p2; p2.distance = 2;
//
//    EXPECT_TRUE(compare(p1, p2));
//}
//
//TEST(Graph, simple_07) {
//    Point p1; p1.distance = 3;
//    Point p2;
//
//    EXPECT_FALSE(compare(p1, p2));
//}
//
//TEST(Graph, simple_08) {
//    Point p1;
//    Point p2;
//
//    EXPECT_TRUE(compare(p1, p2));
//}
//
//TEST(Graph, simple_09) {
//    Point p1;
//    Point p2; p2.distance = 3;
//
//    EXPECT_TRUE(compare(p1, p2));
//}
//
//TEST(Graph, simple_10) {
//    Point p1; p1.distance = 2;
//    Point p2; p2.distance = 3;
//
//    EXPECT_FALSE(compare(p1, p2));
//}

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

//
//auto my_comp = [](const my_type& left, const my_type& right) {
//    if (left.distance == -1 && right.distance == -1) return true;
//    else if (left.distance == -1) return true;
//    else if (right.distance == -1) return false;
//    else if (left.distance > right.distance) return true;
//    else return false;
//};

TEST(Graph, simple_11) {
    Point p1; p1.distance = 2; p1.number = 1;
    Point p2; p2.distance = 3; p2.number = 2;
    Point p3; p3.number = 3;
    Point p4; p4.distance = 4; p4.number = 4;

    std::priority_queue<my_type, my_container, LessThanByPoint> queue;

    queue.push(p1);
    queue.push(p2);
    queue.push(p3);
    queue.push(p4);

    Point p =  queue.top();
    queue.pop();
    EXPECT_TRUE(p.number == 1);

    p =  queue.top();
    queue.pop();
    EXPECT_TRUE(p.number == 2);

}
//
//TEST(Graph, simple_12) {
//    Graph graph(2);
//    graph.AddEdge(0, 1, 10);
//
//    int expected = 10;
//    int real = get_distance(0, 1, graph);
//
//    EXPECT_EQ(expected, real);
//}

//TEST(Graph, simple_13) {
//    Graph graph(3);
//    graph.AddEdge(0, 1, 10);
//    graph.AddEdge(1, 2, 10);
//
//    int expected = 20;
//    int real = get_distance(0, 2, graph);
//
//    EXPECT_EQ(expected, real);
//}

TEST(Graph, simple_14) {
    Graph graph(6);

    graph.AddEdge(0, 3, 1); ///
    graph.AddEdge(0, 4, 2); ///
    graph.AddEdge(1, 2, 7); ///
    graph.AddEdge(1, 3, 2); ///
    graph.AddEdge(1, 4, 3); ///
    graph.AddEdge(1, 5, 3); ///
    graph.AddEdge(2, 5, 3); ///
    graph.AddEdge(3, 4, 4); ///
    graph.AddEdge(3, 5, 6); ///

    int expected = 9;
    int real = get_distance(0, 2, graph);

    EXPECT_EQ(expected, real);
}

TEST(Graph, simple_15) {
    Graph graph(2);

    graph.AddEdge(0, 1, 1);
    graph.AddEdge(0, 1, 1);

    int expected = 1;
    int real = get_distance(0, 1, graph);

    EXPECT_EQ(expected, real);
}




int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

