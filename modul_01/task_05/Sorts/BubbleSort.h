//
// Created by Андрей on 11.10.18.
//

#ifndef TASK_05_BUBBLESORT_H
#define TASK_05_BUBBLESORT_H

template<class T>
void  Swap(T* left, T* right) {
    T mnt = *left;
    *left = *right;
    *right = mnt;
}

template<class T>
void BubbleSort(T* buffer, size_t size) {
    for(size_t i = 0; i < size; ++i) {
        for(size_t j = 0; j < size - 1; ++j) {
            if(buffer[j] > buffer[j + 1]) {
                Swap(&buffer[j], &buffer[j + 1]);
            }
        }
    }
}

#endif //TASK_05_BUBBLESORT_H
