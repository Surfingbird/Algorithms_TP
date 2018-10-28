//
// Created by Андрей on 12.10.18.
//

#ifndef TASK_02_FUNCTIONSFROMMAIN_H
#define TASK_02_FUNCTIONSFROMMAIN_H

using namespace std;

int BinarySearch(int* arr, int size, int left, int right) { /// right + 1
    while(left < right) {
        int mid = (left + right) / 2;
        if(arr[mid] < arr[mid + 1] && mid == 0)
            left = mid + 1;
        else if(arr[mid] > arr[mid - 1] && mid == 0) /// проверяешь мид на последний элемент
            left =  mid;
        else if(arr[mid] < arr[mid + 1] && arr[mid] > arr[mid - 1])
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int DoubleTap(int* arr, int size) {
    int left = 0;
    int right = 0;

    while (right != size - 1) {
        left = right;
        right = 2 * left + 1;
        if (right >= size) right = size - 1;

        if (arr[right - 1] < arr[right] && right != size - 1) {
            if (arr[right + 1] < arr[right]) { // выход за пределы массива
//                cout << left << " Border " << right << endl;
                return right;
            }
        }

        if(right == size - 1 && arr[right - 1] < arr[right])
            return right;

        if (arr[right - 1] > arr[right] && arr[left + 1] > arr[left]) {
//            cout << left << " BINSEARHC " << right << endl;
            return BinarySearch(arr, size, left, right + 1); // бинарный поиск с невплюченным правым эллементом
        }

    }
}


#endif //TASK_02_FUNCTIONSFROMMAIN_H
