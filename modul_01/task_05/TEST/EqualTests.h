//
// Created by Андрей on 10.10.18.
//

#ifndef TASK_05_EQUALTESTS_H
#define TASK_05_EQUALTESTS_H

void Check_OperatorEqually1() {
    DateBorder left = GetDateBorder('[', 4, 11, 1998);
    DateBorder right = GetDateBorder(']', 3, 11, 1998);
    BOOST_CHECK(!(left == right));
}

void Check_OperatorEqually2() {
    DateBorder left = GetDateBorder('[', 3, 11, 1998);
    DateBorder right = GetDateBorder('[', 3, 11, 1998);
    BOOST_CHECK(left == right);
}

void Check_OperatorEqually3() {
    DateBorder left = GetDateBorder('[', 3, 11, 1998);
    DateBorder right = GetDateBorder(']', 3, 11, 1998);
    BOOST_CHECK(left == right);
}

#endif //TASK_05_EQUALTESTS_H
