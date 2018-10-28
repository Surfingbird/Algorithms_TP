cmake_minimum_required(VERSION 3.10)
project(task_05)

set(CMAKE_CXX_STANDARD 11)

#add_executable(task_05 TEST/test_case.cpp DateOperations.h TEST/EqualTests.h TEST/LessOperatorTests.h Sorts/MergeSort.h TEST/BubbleSortTests.h Sorts/BubbleSort.h TEST/MergeSortTests.h TEST/GetDateBeforeEndTests.h)

add_executable(task_05 main.cpp DateOperations.h Sorts/MergeSort.h )