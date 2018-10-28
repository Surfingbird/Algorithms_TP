//
// Created by Андрей on 11.10.18.
//

#ifndef TASK_05_GETDATEBEFOREENDTESTS_H
#define TASK_05_GETDATEBEFOREENDTESTS_H


void GetDateBeforeEndTest1() {
    DateBorder date = GetDateBorder('[', 1, 1, 1998);
    date = GetDateBeforeEnd(date);
    DateBorder expected = GetDateBorder('[', 31, 12, 1997);
    BOOST_CHECK(date == expected);
}

void GetDateBeforeEndTest2() {
    DateBorder date = GetDateBorder('[', 1, 2, 1998);
    date = GetDateBeforeEnd(date);
    DateBorder expected = GetDateBorder('[', 1, 1, 1998);
    BOOST_CHECK(date == expected);
}

void GetDateBeforeEndTest3() {
    DateBorder date = GetDateBorder('[', 2, 2, 1998);
    date = GetDateBeforeEnd(date);
    DateBorder expected = GetDateBorder('[', 1, 2, 1998);
    BOOST_CHECK(date == expected);
}

#endif //TASK_05_GETDATEBEFOREENDTESTS_H
