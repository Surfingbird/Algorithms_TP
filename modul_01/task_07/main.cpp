#include <iostream>

///int tmp = 3 < 64;
using namespace std;


void Swap(long long int* left, long long int* right) {
    long long int mnt = *left;
    *left = *right;
    *right = mnt;
}

bool IsThisBit(long long int* arr, int i, int bit_pos) {
    long long int l = 1;
    return arr[i] & (l << bit_pos);
}

bool IsThisBit(long long int value, int bit_pos) {
    long long l = 1;
    return value & (l << bit_pos);
}

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


int main() {

    int size = 0;
    cin >> size;

    long long int* arr = new long long int[size];

    for(int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    QsortForBit(arr, 0, size, 64);
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";

    return 0;
}

//int main() {
//
//    long long a = 43044981345;
//    for(int i = 63; i >= 0; --i) {
//        cout << (IsThisBit(a, i) > 0) ? 1 : 0;
//    }
//
//    return 0;
//}