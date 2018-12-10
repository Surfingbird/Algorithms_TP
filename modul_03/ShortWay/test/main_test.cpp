//
// Created by Андрей on 09.12.18.
//

#include <gtest/gtest.h>
#include "../ShortWayGraph.h"
#include "../search_way.h"

TEST(serach_way, serach_way_01) {
ShortWayGraph graph(6);

graph.AddEdge(0, 1);
graph.AddEdge(0, 2);
graph.AddEdge(0, 3);
graph.AddEdge(1, 4);
graph.AddEdge(2, 4);
graph.AddEdge(3, 4);
graph.AddEdge(4, 5);

//std::cout << graph;
size_t expected = 3;
size_t real = search_way(0, 5, graph);

EXPECT_EQ(expected, real);
}

TEST(serach_way, serach_way_02) {
    ShortWayGraph graph(4);

    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 3);

    size_t expected = 2;
    size_t real = 0;

    real = search_way(0, 3, graph);

    EXPECT_EQ(expected, real);
}

TEST(serach_way, serach_way_03) {
    ShortWayGraph graph(2);

    graph.AddEdge(0, 1);

    size_t expected = 1;
    size_t real = 0;

    real = search_way(0, 1, graph);

    EXPECT_EQ(expected, real);
}

TEST(serach_way, serach_way_04) {
    ShortWayGraph graph(4);

    graph.AddEdge(0, 1);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);

    size_t expected = 1;
    size_t real = 0;

    real = search_way(0, 3, graph);

    EXPECT_EQ(expected, real);
}

TEST(serach_way, serach_way_05) {
    ShortWayGraph graph(4);

    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 3);
    graph.AddEdge(0, 3);

    size_t expected = 1;
    size_t real = 0;

    real = search_way(0, 3, graph);

    EXPECT_EQ(expected, real);
}

TEST(serach_way, serach_way_06) {
    ShortWayGraph graph(5);

    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 3);
    graph.AddEdge(0, 3);
    graph.AddEdge(3, 4);

    size_t expected = 1;
    size_t real = 0;

    real = search_way(0, 4, graph);

    EXPECT_EQ(expected, real);
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}