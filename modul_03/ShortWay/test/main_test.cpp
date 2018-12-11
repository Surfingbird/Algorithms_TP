//
// Created by Андрей on 09.12.18.
//

#include <gtest/gtest.h>
#include "../MatrixManyGraph/MatrixManyGraph.h"

TEST(MatrixManyGraph, serach_way_01) {
    MatrixManyGraph graph(6);

    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(0, 3);
    graph.AddEdge(1, 4);
    graph.AddEdge(2, 4);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 5);

    //std::cout << graph;
    int expected = 3;
    int real = search_way_02(0, 5, graph);

    EXPECT_EQ(expected, real);
}

TEST(MatrixManyGraph, serach_way_02) {
    MatrixManyGraph graph(4);

    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 3);

    int expected = 2;
    int real = 0;

    real = search_way_02(0, 3, graph);

    EXPECT_EQ(expected, real);
}

TEST(MatrixManyGraph, serach_way_03) {
    MatrixManyGraph graph(2);

    graph.AddEdge(0, 1);

    int expected = 1;
    int real = 0;

    real = search_way_02(0, 1, graph);

    EXPECT_EQ(expected, real);
}

TEST(MatrixManyGraph, serach_way_04) {
    MatrixManyGraph graph(4);

    graph.AddEdge(0, 1);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);

    int expected = 1;
    int real = 0;

    real = search_way_02(0, 3, graph);

    EXPECT_EQ(expected, real);
}

TEST(MatrixManyGraph, serach_way_05) {
    MatrixManyGraph graph(4);

    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 3);
    graph.AddEdge(0, 3);

    int expected = 1;
    int real = 0;

    real = search_way_02(0, 3, graph);

    EXPECT_EQ(expected, real);
}

TEST(MatrixManyGraph, serach_way_06) {
    MatrixManyGraph graph(5);

    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 3);
    graph.AddEdge(0, 3);
    graph.AddEdge(3, 4);

    int expected = 1;
    int real = 0;

    real = search_way_02(0, 4, graph);

    EXPECT_EQ(expected, real);
}

TEST(MatrixManyGraph, serach_way_07) {
    MatrixManyGraph graph(8);

    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);

    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(1, 4);

    graph.AddEdge(2, 5);
    graph.AddEdge(2, 6);

    graph.AddEdge(3, 7);
    graph.AddEdge(3, 4);

    graph.AddEdge(4, 7);
    graph.AddEdge(4, 5);

    graph.AddEdge(5, 6);


    int expected = 2;
    int real = 0;

    real = search_way_02(0, 7, graph);

    EXPECT_EQ(expected, real);

}

TEST(MatrixManyGraph, serach_way_08) {
    MatrixManyGraph graph(2);

    graph.AddEdge(0, 1);
    graph.AddEdge(0, 1);

    int expected = 2;
    int real = 0;

    real = search_way_02(0, 1, graph);

    EXPECT_EQ(expected, real);
}

TEST(MatrixManyGraph, serach_way_09) {
    MatrixManyGraph graph(4);

    graph.AddEdge(0, 0);
    graph.AddEdge(1, 1);
    graph.AddEdge(2, 2);
    graph.AddEdge(3, 3);

    graph.AddEdge(0, 1);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 0);

//    std::cout << "-----\n";
//    std::cout << graph;
//    std::cout << "-----\n";


    int expected = 1;
    int real = 0;

    real = search_way_02(0, 1, graph);

    EXPECT_EQ(expected, real);
}

TEST(MatrixManyGraph, serach_way_10) {
    MatrixManyGraph graph(8);

//    graph.AddEdge(0, 0);
//    graph.AddEdge(1, 1);
//    graph.AddEdge(2, 2);
//    graph.AddEdge(3, 3);
//    graph.AddEdge(4, 4);
//    graph.AddEdge(5, 5);
//    graph.AddEdge(6, 6);
//    graph.AddEdge(7, 7);

    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(0, 3);
    graph.AddEdge(1, 4);
    graph.AddEdge(2, 5);
    graph.AddEdge(3, 6);
    graph.AddEdge(6, 7);

    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(0, 3);
    graph.AddEdge(1, 4);
    graph.AddEdge(2, 5);
    graph.AddEdge(3, 6);
    graph.AddEdge(6, 7);

    std::cout << "-----\n";
    std::cout << graph;
    std::cout << "-----\n";

    int expected = 2;
    int real = 0;

    real = search_way_02(0, 7, graph);

    EXPECT_EQ(expected, real);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}