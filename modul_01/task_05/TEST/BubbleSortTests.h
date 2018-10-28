//
// Created by Андрей on 11.10.18.
//

#ifndef TASK_05_BUBBLESORTTESTS_H
#define TASK_05_BUBBLESORTTESTS_H

#include "../Sorts/BubbleSort.h"

void BubbleSortTest() {
    const size_t size = 5; //{5, 6, 8, 4, 66};
    int *array = new int[size];
    array[0] = 5;
    array[1] = 6;
    array[2] = 8;
    array[3] = 4;
    array[4] = 66;

    BubbleSort(array, size);

    int sorted_array[size] = {4, 5, 6, 8, 66};
    for (size_t i = 0; i < size; ++i) {
        BOOST_CHECK(array[i] == sorted_array[i]);
    }
    //    std::cout << "Expected Array: ";
    //    for(size_t i = 0; i < size; ++i) {
    //        std::cout << sorted_array[i] << " ";
    //    }
    //    std::cout << std::endl;
    //    std::cout << "Result Array: ";
    //    for(size_t i = 0; i < size; ++i) {
    //        std::cout << array[i] << " ";
    //    }
    //    std::cout << std::endl;
}

#endif //TASK_05_BUBBLESORTTESTS_H
