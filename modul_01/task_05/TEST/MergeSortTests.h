//
// Created by Андрей on 11.10.18.
//

#ifndef TASK_05_MERGESORTTESTS_H
#define TASK_05_MERGESORTTESTS_H

#include "../Sorts/MergeSort.h"

void MergeSortTest1() {
    const int size = 7;
    int buffer[size] = {1, 5, 7, 8, 4, 0, 23};
    MergeSort(buffer, size);

    int expected[size] = {0, 1, 4, 5, 7, 8, 23};
    for(int i = 0; i < size; ++i) {
        BOOST_CHECK(expected[i] == buffer[i]);
    }
//    for(int i = 0; i < size; ++i) {
//        std::cout << buffer[i] << " ";
//    }
//    std::cout << std::endl;
}

void MergeSortTest2() {
    const int size = 7;
    int buffer[size] = {-9, -7, 7, 1, 1, 0, 23};
    MergeSort(buffer, size);

    int expected[size] = {-9, -7, 0, 1, 1, 7, 23};
    for(int i = 0; i < size; ++i) {
        BOOST_CHECK(expected[i] == buffer[i]);
    }
//    for(int i = 0; i < size; ++i) {
//        std::cout << buffer[i] << " ";
//    }
//    std::cout << std::endl;
}

void MergeSortTest3() {
    const int size = 7;
    char buffer[size] = {'a', 'n', 'p', 'q', 'j', 'i', 'm'};
    MergeSort(buffer, size);

    char expected[size] = {'a', 'i', 'j', 'm', 'n', 'p', 'q'};
    for(int i = 0; i < size; ++i) {
        BOOST_CHECK(expected[i] == buffer[i]);
    }
//    for(int i = 0; i < size; ++i) {
//        std::cout << buffer[i] << " ";
//    }
//    std::cout << std::endl;
}

void MergeSortTest4() {
    const int size = 2;
    char buffer[size] = {'[', ']'};
    MergeSort(buffer, size);

    char expected[size] = {'[', ']'};
    for(int i = 0; i < size; ++i) {
        BOOST_CHECK(expected[i] == buffer[i]);
    }
//    for(int i = 0; i < size; ++i) {
//        std::cout << buffer[i] << " ";
//    }
//    std::cout << std::endl;
}

void MergeFuncTest1() {
    const int l_size = 3;
    const int r_size = 3;
    int Left[l_size] = {1, 5, 7};
    int Right[r_size] = {2, 6, 8};

    int* dest = new int[l_size + r_size];
    Merge(Left, l_size, Right, r_size, dest);

    int expected[l_size + r_size] = {1, 2, 5, 6, 7, 8};

    for(int i = 0; i < l_size + r_size; ++i) {
        BOOST_CHECK(expected[i] == dest[i]);
    }

//    for(int i = 0; i < l_size + r_size; ++i) {
//        std::cout << dest[i] << " ";
//    }
//    std::cout << std::endl;
}

void MergeFuncTest2() {
    const int l_size = 3;
    const int r_size = 3;
    int Left[l_size] = {1, 2, 3};
    int Right[r_size] = {4, 5, 6};

    int* dest = new int[l_size + r_size];
    Merge(Left, l_size, Right, r_size, dest);

    int expected[l_size + r_size] = {1, 2, 3, 4, 5, 6};

    for(int i = 0; i < l_size + r_size; ++i) {
        BOOST_CHECK(expected[i] == dest[i]);
    }
//    for(int i = 0; i < l_size + r_size; ++i) {
//        std::cout << dest[i] << " ";
//    }
//    std::cout << std::endl;
}

#endif //TASK_05_MERGESORTTESTS_H
