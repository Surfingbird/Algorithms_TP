//
// Created by Андрей on 10.10.18.
//

#include <boost/test/minimal.hpp>
#include "../DateOperations.h"
#include "EqualTests.h"
#include "LessOperatorTests.h"
#include "../Sorts/MergeSort.h"
#include "BubbleSortTests.h"
#include "../Sorts/BubbleSort.h"
#include "MergeSortTests.h"
#include "GetDateBeforeEndTests.h"

void EqualOperatorTests() {
    Check_OperatorEqually1();
    Check_OperatorEqually2();
    Check_OperatorEqually3();
}

void LessOperatorTests() {
    Check_OperatorLess1();
    Check_OperatorLess2();
    Check_OperatorLess3();
    Check_OperatorLess4();
}

void MergeSortTests() {
    MergeFuncTest1();
    MergeFuncTest2();
    MergeSortTest1();
    MergeSortTest2();
    MergeSortTest3();
    MergeSortTest4();

}

void GetDaysInMounthTests() {
    BOOST_CHECK(GetDaysInMounth(2, 2016) == 29);
    BOOST_CHECK(GetDaysInMounth(10, 2018) == 31);
    BOOST_CHECK(GetDaysInMounth(11, 2018) == 30);
    BOOST_CHECK(GetDaysInMounth(12, 2018) == 31);
    BOOST_CHECK(GetDaysInMounth(9, 2018) == 30);
}

void GetDateBeforeEndTests() {
    GetDateBeforeEndTest1();
    GetDateBeforeEndTest2();
    GetDateBeforeEndTest3();
}

int test_main( int, char *[ ] ) {// note the name!
    MergeSortTests();
    return 0;
}
