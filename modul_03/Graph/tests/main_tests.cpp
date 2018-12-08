//
// Created by Андрей on 07.12.18.
//

#include <gtest/gtest.h>
#include "../set_graph/set_graph.h"
#include "../matrix_graph/matrix_graph.h"
#include "../arc_graph/arc_graph.h"
#include "../list_graph/list_graph.hpp"

SetGraph get_fake_set_graph() {
    SetGraph graph =  SetGraph(4);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(0, 3);

    return graph;
}

MatrixGraph get_fake_mgraph() {
    MatrixGraph graph = MatrixGraph(4);
    graph.AddEdge(0, 1);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 0);

    return graph;
}

ArcGraph get_fake_agraph() {
    ArcGraph graph = ArcGraph(4);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(0, 3);

    return graph;
}

ListGraph get_fake_lgraph() {
    ListGraph graph = ListGraph(4);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(0, 3);

    return graph;
}



class TestSetGraph : public ::testing::Test {
    void SetUp() override;

public:
    SetGraph setGraph;
};

void TestSetGraph::SetUp() {
    setGraph = get_fake_set_graph();
}

TEST_F(TestSetGraph, simple_set_graph_01) {
    /// from 0 -> 1, 2, 3
    std::vector<int> expected_out_edges = {1, 2, 3};
    std::vector<int> real_out_edges;

    setGraph.GetNextVertices(0, real_out_edges);
    std::sort(real_out_edges.begin(), real_out_edges.end());

    EXPECT_EQ(real_out_edges, expected_out_edges);

    std::vector<int> expected_in_edges_1 = {0};
    std::vector<int> expected_in_edges_2 = {0};
    std::vector<int> expected_in_edges_3 = {0};

    std::vector<int> real_in_edges_1;
    std::vector<int> real_in_edges_2;
    std::vector<int> real_in_edges_3;

    setGraph.GetPrevVertices(1, real_in_edges_1);
    setGraph.GetPrevVertices(2, real_in_edges_2);
    setGraph.GetPrevVertices(3, real_in_edges_3);

    EXPECT_EQ(expected_in_edges_1, real_in_edges_1);
    EXPECT_EQ(expected_in_edges_2, real_in_edges_2);
    EXPECT_EQ(expected_in_edges_3, real_in_edges_3);
}

TEST(SetGraphConstructor, from_mgraph_to_setg) {
    MatrixGraph matrixGraph = get_fake_mgraph();
    SetGraph setGraph(dynamic_cast<IGraph*>(&matrixGraph));

    EXPECT_EQ(4, setGraph.VerticesCount());

    std::vector<int> expected_in_edges_1 = {0};
    std::vector<int> expected_in_edges_2 = {1};
    std::vector<int> expected_in_edges_3 = {2};

    std::vector<int> real_in_edges_1;
    std::vector<int> real_in_edges_2;
    std::vector<int> real_in_edges_3;

    setGraph.GetPrevVertices(1, real_in_edges_1);
    setGraph.GetPrevVertices(2, real_in_edges_2);
    setGraph.GetPrevVertices(3, real_in_edges_3);

    EXPECT_EQ(expected_in_edges_1, real_in_edges_1);
    EXPECT_EQ(expected_in_edges_2, real_in_edges_2);
    EXPECT_EQ(expected_in_edges_3, real_in_edges_3);
}

TEST(SetGraphConstructor, from_agraph_to_setg) {
    ArcGraph arcGraph = get_fake_agraph();

    SetGraph setGraph = SetGraph(dynamic_cast<IGraph*>(&arcGraph));

    std::vector<int> expected_out_edges = {1, 2, 3};
    std::vector<int> real_out_edges;

    setGraph.GetNextVertices(0, real_out_edges);
    std::sort(real_out_edges.begin(), real_out_edges.end());

    EXPECT_EQ(real_out_edges, expected_out_edges);
}

TEST(SetGraphConstructor, from_lgraph_to_setg) {
    ListGraph listGraph = get_fake_lgraph();

    SetGraph setGraph = SetGraph(dynamic_cast<IGraph*>(&listGraph));

    std::vector<int> expected_out_edges = {1, 2, 3};
    std::vector<int> real_out_edges;

    setGraph.GetNextVertices(0, real_out_edges);
    std::sort(real_out_edges.begin(), real_out_edges.end());

    EXPECT_EQ(real_out_edges, expected_out_edges);
}


TEST(SetGraphConstructor, from_setg_to_lg) {
    SetGraph setGraph1 = get_fake_set_graph();

    ListGraph listGraph = ListGraph(dynamic_cast<IGraph*>(&setGraph1));

    std::vector<int> expected_out_edges = {1, 2, 3};
    std::vector<int> real_out_edges;

    listGraph.GetNextVertices(0, real_out_edges);
    std::sort(real_out_edges.begin(), real_out_edges.end());

    EXPECT_EQ(real_out_edges, expected_out_edges);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}