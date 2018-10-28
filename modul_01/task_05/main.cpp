#include <iostream>
//#include "DateOperations.h"
//#include "Sorts/MergeSort.h"

///Группа людей называется современниками если был такой момент,
///        когда они могли собраться вместе. Для этого в этот момент каждому из
///        них должно было уже исполниться 18 лет, но ещё не исполниться 80 лет.
///Дан список Жизни Великих Людей. Необходимо получить максимальное количество современников.
///В день 18летия человек уже может принимать участие в собраниях,
///а в день 80летия и в день смерти уже не может.
///Замечание. Человек мог не дожить до 18-летия,
///либо умереть в день 18-летия. В этих случаях принимать участие в собраниях он не мог.

/// Pun ID: 12635521

using namespace std;

struct DateBorder {
    friend bool operator==(const DateBorder& left, const DateBorder& right);
    char border;
    size_t day = 0;
    size_t mounth = 0;
    size_t year = 0;
};

int GetDaysInMounth(int m, int y) { return (m!=2?((m%2)^(m>7))+30:(!(y%400)||!(y%4)&&(y%25)?29:28));}

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
    else return false;
    ///может случиться, что в один день [ и ] -- следовательно у [ больше приоритет, чем у ]
}

bool operator==(const DateBorder& left, const DateBorder& right) {
    return left.day == right.day &&
           left.mounth == right.mounth &&
           left.year == right.year  ? true : false;
}


void Merge(DateBorder* LeftBuffer, int LeftLen, DateBorder* RightBuffer, int RightLen, DateBorder* Dest) {
    int LeftIndex = 0;
    int RightIndex = 0;
    int DestIndex = 0;
    while (LeftIndex < LeftLen || RightIndex < RightLen) {

        if(LeftBuffer[LeftIndex] < RightBuffer[RightIndex] ||
           (LeftBuffer[LeftIndex] == RightBuffer[RightIndex]
            && LeftBuffer[LeftIndex].border < RightBuffer[RightIndex].border)) {

            Dest[DestIndex++] = LeftBuffer[LeftIndex];
            ++LeftIndex;
        } else {
            Dest[DestIndex++] = RightBuffer[RightIndex];
            ++RightIndex;
        }

        if(LeftIndex == LeftLen) {
            for(; RightIndex < RightLen; ++RightIndex) {
                Dest[DestIndex++] = RightBuffer[RightIndex];
            }
            break;
        }
        if(RightIndex == RightLen) {
            for(; LeftIndex < LeftLen; ++LeftIndex) {
                Dest[DestIndex++] = LeftBuffer[LeftIndex];
            }
            break;
        }
    }
}

void MergeSort(DateBorder* buffer, int size) {
    if(size <= 1) {
        return;
    }

    int LeftLen = size / 2;
    int RightLen = size - LeftLen;
    MergeSort(buffer, LeftLen);
    MergeSort(buffer + LeftLen, RightLen);

    DateBorder* new_buffer = new DateBorder[size];
    Merge(buffer, LeftLen, buffer + LeftLen, RightLen, new_buffer);
//    memcpy(buffer, new_buffer, sizeof(DateBorder)*size);
    for(int i = 0; i < size; ++i) {
        buffer[i] = new_buffer[i];
    }

    delete [] new_buffer;
}

void AppenBorders(DateBorder* buffer, DateBorder DateBorn,
                  DateBorder DateDeath, int *BufferTop) {
    DateBorder AdultDate = DateBorn;
    AdultDate.year += 18;

    DateBorder GrandDate = DateBorn;
    GrandDate.border = ']';
    GrandDate.year += 80;

    if(DateDeath < AdultDate || AdultDate == DateDeath) {
        return;
    }

    DateBorder UntilDate = GetDateBeforeEnd(GrandDate);

    if(DateDeath < GrandDate) {
        UntilDate = GetDateBeforeEnd(DateDeath);
    }

    int j = *BufferTop;
    buffer[j++] = AdultDate;
    buffer[j++] = UntilDate;
    *BufferTop = j;
}

int main() {
    int count = 0;
    cin >> count;
    int size = count * 2;
    DateBorder* buffer = new DateBorder[size];
    int BufferTop = 0;

    for(int i = 0; i < count; ++i) {
        DateBorder DateBorn = GetDateBorder('[');
        DateBorder DateDeath = GetDateBorder(']');
        AppenBorders(buffer, DateBorn, DateDeath, &BufferTop);
    }

    MergeSort(buffer, BufferTop);

    int max = 0;
    int current = 0;
    for (int i = 0; i < BufferTop; ++i) {
        if (buffer[i].border == '[') {
            ++current;
        } else --current;

        if (max < current) max = current;
    }
    cout << max;

    delete [] buffer;

    return 0;
}