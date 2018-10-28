//
// Created by Андрей on 10.10.18.
//

/// В данной реализации все отрезки включают концы, то есть имеет смысл сортировать не только по
/// временному интервалу, но и по символу открывающей или закрывающей скобки

#ifndef TASK_05_DATEOPERATIONS_H
#define TASK_05_DATEOPERATIONS_H

struct DateBorder {
    friend bool operator==(const DateBorder& left, const DateBorder& right);
    char border;
    size_t day = 0;
    size_t mounth = 0;
    size_t year = 0;
};

int GetDaysInMounth(int m, int y) { return (m!=2?((m%2)^(m>7))+30:(!(y%400)||!(y%4)&&(y%25)?29:28));}

DateBorder GetDateBorder(char border, int day, int mounth, int year) {
    DateBorder date;
    date.border = border;
    date.day = day;
    date.mounth = mounth;
    date.year = year;

    return date;
}

DateBorder GetDateBorder(char border) {
    DateBorder date;
    date.border = border;
    std::cin >> date.day;
    std::cin >> date.mounth;
    std::cin >> date.year;

    return date;
}

DateBorder GetDateBeforeEnd(DateBorder end) {
    if (end.day > 1) {
        --end.day;
    } else if(end.mounth > 1) {
        --end.mounth;
    } else {
        --end.year;
        end.mounth = 12;
        end.day = GetDaysInMounth(end.mounth, end.year);;
    }
    return end;
}

const bool operator<(const DateBorder& left, const DateBorder& right) {
    if(left.year < right.year) return true;
    else if(left.year > right.year) return false;

    if(left.mounth < right.mounth) return true;
    else if(left.mounth > right.mounth) return false;

    if(left.day < right.day) return true;
    else return false; /// скользкий момент
    ///может случиться, что в один день [ и ] -- следовательно у [ больше приоритет, чем у ]
}

bool operator==(const DateBorder& left, const DateBorder& right) {
    return left.day == right.day &&
                   left.mounth == right.mounth &&
                   left.year == right.year  ? true : false;
}

#endif //TASK_05_DATEOPERATIONS_H
