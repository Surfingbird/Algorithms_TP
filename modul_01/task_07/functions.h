//
// Created by Андрей on 22.10.18.
//

#ifndef TASK_07_FUNCTIONS_H
#define TASK_07_FUNCTIONS_H

void Swap(long long int* left, long long int* right) {
    long long int mnt = *left;
    *left = *right;
    *right = mnt;
}

bool IsThisBit(long long int* arr, int i, int bit_pos) {
    long long int a = 1;
    return arr[i] & (a << bit_pos);
}

//bool IsThisBit(long long int value, int bit_pos) {
//    long long l = 1;
//    return value & (l << bit_pos);
//}

void QsortForBit(long long int* arr, int left, int right, int deepth) {
    --deepth;

    if(left == right || deepth < 0)
        return;

    int i = left;
    int j = left;

    while(!IsThisBit(arr, i, deepth) && i < right)
        ++i;

    j = i;

    while(j < right) {
        while(IsThisBit(arr, j, deepth) && j < right)
            ++j;

        if(i < j && j != right) {
            Swap(&arr[i], &arr[j]);
            ++i;
        }
    }

//    if(i == right || i == left)
//        return;

    QsortForBit(arr, left, i, deepth);
    QsortForBit(arr, i, right, deepth);
}


#endif //TASK_07_FUNCTIONS_H
