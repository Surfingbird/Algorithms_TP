//
// Created by Андрей on 12.10.18.
//

#include <iostream>

using namespace std;

int RandomP(int left, int right) {
    return rand() % (right - left + 1) + left;
}

void Swap(int* left, int* right) {
    int mnt = *left;
    *left = *right;
    *right = mnt;
}

void Printer(int* buffer, int size) {
    for(int i = 0; i < size; ++i) {
        cout << buffer[i] << " ";
    }
    cout << endl;
}

struct Diapason {
    int from;
    int to;
    bool Empty;
};

int SearchIndex(int* arr, int size, int value) {
    Diapason diapason;
    diapason.from = 0;
    diapason.to = size - 1;
    diapason.Empty = false;

    while(!diapason.Empty) {
        int from = diapason.from;
        int to = diapason.to;
        diapason.Empty = true;

        if(to - from == 1) {
            if(arr[from] <= arr[to]) {
                if(value == arr[from]) return from;
                else return to;
            } else {
                if(value == arr[from]) return to;
                else return from;
            }
        }
//        cout << "--------------------" << endl;
//        cout << from << " - " << to << endl;
//        for(int i = from; i <= to; ++i) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//        cout << "--------------------" << endl;

//        cout << from << " " << to << endl;

        int PivotIndex =  RandomP(from, to);
        int PivotValue = arr[PivotIndex];
        Swap(&arr[PivotIndex], &arr[to]);
        PivotIndex = to;

        int i = from;
        int j = to - 1;

//        Printer(arr, size);

        while(i < j) {
            while(arr[i] <= PivotValue) ++i;
            while(arr[j] > PivotValue) --j;

            if(i < j) Swap(&arr[i], &arr[j]);
        }
        Swap(&arr[PivotIndex], &arr[i]);
        PivotIndex = i;

        if(arr[PivotIndex] == value) return PivotIndex;
        if (value < arr[PivotIndex]) {
            diapason.from = from;
            diapason.to = PivotIndex - 1;
            diapason.Empty = false;
        } else {
            diapason.from = PivotIndex + 1;
            diapason.to = to;
            diapason.Empty = false;
        }
    }
}

int main() {
    int size = 0;
    int value = -1;
    cin >> size; cin >> value;
    int* buffer = new int[size];
    for(int i = 0; i < size; ++i) {
        cin >> buffer[i];
    }
    cout << SearchIndex(buffer, size, value);



    return 0;
