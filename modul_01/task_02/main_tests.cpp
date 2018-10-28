//
// Created by Андрей on 12.10.18.
//
#include <boost/test/minimal.hpp>
#include "FunctionsFromMain.h"

void test_double_method_1() {
    /// max - 1 index
    int arr[] = {1 , 2, 1};
    int const size = 3;
    BOOST_CHECK(DoubleTap(arr, size) == 1);
}

void test_double_method_2() {
    /// max - 3 index
    int arr[] = {1 , 2, 3, 4, 3};
    int const size = 5;
    BOOST_CHECK(DoubleTap(arr, size) == 3);
}

void test_double_method_3() {
    /// max - 7 index
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 7};
    int const size = 9;
    BOOST_CHECK(DoubleTap(arr, size) == 7);
}

void test_double_method_4() {
    /// max - 15 index
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 14, 13, 12, 11, 10};
    int const size = 21;
    BOOST_CHECK(DoubleTap(arr, size) == 15);
}

void test_binary_search_1() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 7, 6};
    int const size = 11;
    BOOST_CHECK(DoubleTap(arr, size) == 8);
}

void test_binary_search_2() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8};
    int const size = 11;
    BOOST_CHECK(DoubleTap(arr, size) == 9);
}


void test_binary_search_3() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9};
    int const size = 12;
    BOOST_CHECK(DoubleTap(arr, size) == 10);
}

void test_binary_search_4() { /// ошибка в случае, если это срединный элемент
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 9}; /// 0 1 2 3 4 5 6 7 8 9 10 11 9
    int const size = 13;
    BOOST_CHECK(DoubleTap(arr, size) == 11);
}

void test_binary_search_5() { /// ошибка в случае, если это срединный элемент
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 11};
    int const size = 14;
    BOOST_CHECK(DoubleTap(arr, size) == 12);
}

void test_binary_search_6() { /// ошибка в случае, если это срединный элемент
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 11};
    int const size = 15;
    BOOST_CHECK(DoubleTap(arr, size) == 13);
}

void test_binary_search_7() { /// ошибка в случае, если это срединный элемент
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 10};
    int const size = 16;
    BOOST_CHECK(DoubleTap(arr, size) == 14);
}

void test_binary_search_8() { /// ошибка в случае, если это срединный элемент
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    int const size = 17;
    BOOST_CHECK(DoubleTap(arr, size) == 15);
}

void test_binary_search_9() { /// ошибка в случае, если это срединный элемент
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 7, 6, 5, 4, 3, 2, 1};
    int const size = 16;
    BOOST_CHECK(DoubleTap(arr, size) == 8);
}

void test_binary_search_10() { /// ошибка в случае, если это срединный элемент
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3};
    int const size = 16;
    BOOST_CHECK(DoubleTap(arr, size) == 9);
}

void test_binary_search_11() { /// ошибка в случае, если это срединный элемент
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5};
    int const size = 16;
    BOOST_CHECK(DoubleTap(arr, size) == 10);
}

void test_binary_search_12() { /// ошибка в случае, если это срединный элемент
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 9, 8, 7, 6};
    int const size = 16;
    BOOST_CHECK(DoubleTap(arr, size) == 11);
}

void test_binary_search_13() { /// ошибка в случае, если это срединный элемент
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 11, 10, 9};
    int const size = 16;
    BOOST_CHECK(DoubleTap(arr, size) == 12);
}

void test_binary_search_14() { /// ошибка в случае, если это срединный элемент
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11};
    int const size = 16;
    BOOST_CHECK(DoubleTap(arr, size) == 13);
}

void test_binary_search_15() { /// ошибка в случае, если это срединный элемент
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 11};
    int const size = 16;
    BOOST_CHECK(DoubleTap(arr, size) == 14);
}

void test_binary_search_16() { /// ошибка в случае, если это срединный элемент
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 11};
    int const size = 17;
    BOOST_CHECK(DoubleTap(arr, size) == 15);
}

void test_binary_search_17() { /// ошибка в случае, если это срединный элемент
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1, 0};
    int const size = 15;
    BOOST_CHECK(DoubleTap(arr, size) == 7);
}

void test_binary_search_18() { /// ошибка в случае, если это срединный элемент
    int arr[] = {0, 1, 2, 3, 4, 5, 6};
    int const size = 7;
    BOOST_CHECK(DoubleTap(arr, size) == 6);
}

void prev_tests() {
    test_double_method_1();
    test_double_method_2();
    test_double_method_3();
    test_double_method_4();

    test_binary_search_1();
    test_binary_search_2();
    test_binary_search_3();
    test_binary_search_4();
    test_binary_search_5();
    test_binary_search_6();
    test_binary_search_7();
    test_binary_search_8();

    test_binary_search_9();
    test_binary_search_10();
    test_binary_search_11();
    test_binary_search_12();
    test_binary_search_13();
    test_binary_search_14();
    test_binary_search_15();
    test_binary_search_16();
}

int test_main( int, char *[ ] ) {// note the name!
    test_binary_search_17();
    test_binary_search_18();
    return 0;
}