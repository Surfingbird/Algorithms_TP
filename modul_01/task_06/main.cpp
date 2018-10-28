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

//int partition2(int* arr, int l, int r) {
//    int p = arr[(l + r) / 2];
//    int i = l;
//    int j = r;
//    while (i <= j) {
//        while (arr[i] < p)
//            i++;
//        while (arr[j] > p)
//            j--;
//        if (i >= j)
//            break;
//        Swap(&arr[i++], &arr[j--]);
//    }
//    return j;
//}

int partition(int* arr, int left, int right) {
    int i = left;
    int j = left;

    int PivotIndex = RandomP(left, right - 1);
    Swap(&arr[PivotIndex], &arr[right - 1]);
    PivotIndex = right - 1;

    while(i < PivotIndex && arr[i] < arr[PivotIndex])
        ++i;

    j = i;

    while(j < PivotIndex) {
        while (j < PivotIndex && arr[j] >= arr[PivotIndex]) {
            ++j;
        }
        if(i < j && j != PivotIndex) {
            Swap(&arr[i], &arr[j]);
            i++;
        }
    }
    Swap(&arr[i], &arr[PivotIndex]);

    PivotIndex = i;
    return PivotIndex;
}



int KStatistic(int* arr, int size, int index) {
    int left = 0;
    int right = size;
    while (true) {

        const int mid = partition(arr, left, right);

        if (mid == index) {
//            cout << mid << ": " << arr[mid] << endl;
            return arr[mid];
        }
        else if (index < mid) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
}

int main() {
    int size = 0;
    int value = -1;
    cin >> size;
    cin >> value;
    int *buffer = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> buffer[i];
    }
    cout << KStatistic(buffer, size, value);


    return 0;
}