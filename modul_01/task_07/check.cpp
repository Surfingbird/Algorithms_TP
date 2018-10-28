//
// Created by Андрей on 22.10.18.
//

#include <iostream>

bool IsThisBit(long long int per, int bit_pos) {
    return per & (1 << bit_pos);
}

///int tmp = 3 < 64;
using namespace std;


int main() {
 long long int a = 1125899906842623;
 long long int b = 3;

 if(IsThisBit(b, 66)) {
     cout << "\nYES!\n";
 }
}