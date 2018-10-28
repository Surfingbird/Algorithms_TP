//
// Created by Андрей on 10.10.18.
//

#ifndef TASK_05_LESSOPERATORTESTS_H
#define TASK_05_LESSOPERATORTESTS_H

void Check_OperatorLess1() {
    /// left < right by day
    DateBorder left = GetDateBorder('[', 2, 11, 1998);
    DateBorder right = GetDateBorder(']', 3, 11, 1998);
    BOOST_CHECK(left < right);
}

void Check_OperatorLess2() {
    /// left < right by mounth
    DateBorder left = GetDateBorder('[', 3, 10, 1998);
    DateBorder right = GetDateBorder(']', 3, 11, 1998);
    BOOST_CHECK(left < right);
}

void Check_OperatorLess3() {
    /// left < right by year
    DateBorder left = GetDateBorder('[', 3, 10, 1998);
    DateBorder right = GetDateBorder(']', 3, 10, 1999);
    BOOST_CHECK(left < right);
}

void Check_OperatorLess4() {
    /// left equal right
    DateBorder left = GetDateBorder('[', 3, 10, 1998);
    DateBorder right = GetDateBorder(']', 3, 10, 1998);
    BOOST_CHECK(!(left < right));
}

#endif //TASK_05_LESSOPERATORTESTS_H
