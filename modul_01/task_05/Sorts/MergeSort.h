//
// Created by Андрей on 11.10.18.
//

#ifndef TASK_05_MERGESORT_H
#define TASK_05_MERGESORT_H

template<class T>
void Merge(T* LeftBuffer, int LeftLen, T* RightBuffer, int RightLen, T* Dest) {
    int LeftIndex = 0;
    int RightIndex = 0;
    int DestIndex = 0;
    while (LeftIndex < LeftLen || RightIndex < RightLen) {

        if(LeftBuffer[LeftIndex] < RightBuffer[RightIndex]) {
            Dest[DestIndex++] = LeftBuffer[LeftIndex];
            ++LeftIndex;
        } else {
            Dest[DestIndex++] = RightBuffer[RightIndex];
            ++RightIndex;
        }

        if(LeftIndex == LeftLen) {
            for(; RightIndex < RightLen; ++RightIndex) {
                Dest[DestIndex++] = RightBuffer[RightIndex];
            }
            break;
        }
        if(RightIndex == RightLen) {
            for(; LeftIndex < LeftLen; ++LeftIndex) {
                Dest[DestIndex++] = LeftBuffer[LeftIndex];
            }
            break;
        }
    }
}

template<class T>
void MergeSort(T* buffer, int size) {
    if(size <= 1) {
        return;
    }
    int LeftLen = size / 2;
    int RightLen = size - LeftLen;
    MergeSort(buffer, LeftLen);
    MergeSort(buffer + LeftLen, RightLen);

    T* new_buffer = new T[size];
    Merge(buffer, LeftLen, buffer + LeftLen, RightLen, new_buffer);
    memcpy(buffer, new_buffer, sizeof(T)*size);
    delete [] new_buffer;
}




#endif //TASK_05_MERGESORT_H
