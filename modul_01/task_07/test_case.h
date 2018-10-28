//
// Created by Андрей on 22.10.18.
//

#ifndef TASK_07_TEST_CASE_H
#define TASK_07_TEST_CASE_H

#include "functions.h"
#include <boost/test/minimal.hpp>

void Printer(long long int* arr, int size) {
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

bool IsEqualArray(long long int* arr1, __int64_t* arr2, long long int size) {
    for(int i = 0; i < size; ++i) {
        if(arr1[i] != arr2[i]) return false;
    }
    return true;
}

void test_0() {

    const int size = 10;
    long long int have[size] = {3,
                                6,
                                9,
                                8,
                                2,
                                1,
                                4,
                                7,
                                8,
                                3};

    long long int expected[size] = {1, 2, 3, 3, 4, 6, 7, 8, 8, 9};

    QsortForBit(have, 0, size, 64);

//    Printer(have, size);

    BOOST_CHECK(IsEqualArray(have, expected, size));
}

void test_1() {

    const int size = 10;
    long long int have[size] = {72104283,
                      41105460,
                      99001495,
                      73262535,
                      41617850,
                      96382152,
                      93785168,
                      5392641,
                      24637664,
                      2469804};

    long long int expected[size] = {2469804,
                          5392641,
                          24637664,
                          41105460,
                          41617850,
                          72104283,
                          73262535,
                          93785168,
                          96382152,
                          99001495};

    QsortForBit(have, 0, size, 64);

    BOOST_CHECK(IsEqualArray(have, expected, size));
}

void test_2() {

    const int size = 9;
    long long int have[size] = {61370808,
                                79413532,
                                44782105,
                                30008111,
                                34863067,
                                7747151,
                                12119288,
                                72378794,
                                6091801
    };

    long long int expected[size] = {6091801,
                                    7747151,
                                    12119288,
                                    30008111,
                                    34863067,
                                    44782105,
                                    61370808,
                                    72378794,
                                    79413532};

    QsortForBit(have, 0, size, 64);

    BOOST_CHECK(IsEqualArray(have, expected, size));
}

void test_3() {

    const int size = 20;
    long long int have[size] = {96,
                                85,
                                64,
                                32,
                                14,
                                14,
                                26,
                                12,
                                57,
                                23,
                                13533064215,
                                43044981345,
                                39489711180,
                                6671794902,
                                47098631614,
                                39557636079,
                                9535726668,
                                42204110316,
                                35672927443,
                                32995740720
    };

    long long int* have_2 = new  long long int[size];
    for(int i = 0; i < size; ++i) {
        have_2[i] = have[i];
    }

    long long int expected[size] = {12,
                                    14,
                                    14,
                                    23,
                                    26,
                                    32,
                                    57,
                                    64,
                                    85,
                                    96,
                                    6671794902,
                                    9535726668,
                                    13533064215,
                                    32995740720,
                                    35672927443,
                                    39489711180,
                                    39557636079,
                                    42204110316,
                                    43044981345,
                                    47098631614
    };

    QsortForBit(have_2, 0, size, 64);

    Printer(have_2, size);

    BOOST_CHECK(IsEqualArray(have_2, expected, size));
}

void test_4() {

    const int size = 9;
    long long int have[size] = {61370808,
                                79413532,
                                44782105,
                                30008111,
                                34863067,
                                7747151,
                                12119288,
                                72378794,
                                6091801
    };

    long long int expected[size] = {6091801,
                                    7747151,
                                    12119288,
                                    30008111,
                                    34863067,
                                    44782105,
                                    61370808,
                                    72378794,
                                    79413532};

    QsortForBit(have, 0, size, 64);

    BOOST_CHECK(IsEqualArray(have, expected, size));
}

#endif //TASK_07_TEST_CASE_H

