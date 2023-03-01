#include <iostream>
#include <stdlib.h>

using namespace std;

/*  Task 1
Write a function tomorrow that takes a date structure by value and returns the next
date
*/
typedef struct {
    int year;
    int month;
    int day;
} date;

void printDate(date d) {
    cout << d.month << "/" << d.day << "/" << d.year << endl;
}

// takes a date structure and returns the next date
date tomorrow(date d) {
    date tomorrow;


    switch (d.month) {
        case 7:
        case 4:
        case 6:
        case 11: // 30 days
            if (d.day + 1 > 30) {
                d.day = 1;
                d.month += 1;
            } else d.day += 1;
            break;
        case 2:
            if (d.day + 1 > 28) {
                d.day = 1;
                d.month += 1;
            } else d.day += 1;
            break;

        default: // 31 days
            if (d.day + 1 > 31) {
                d.day = 1;
                if (d.month + 1 > 12) {
                    d.month = 1;
                    d.year += 1;
                } else d.month += 1;
            } else d.day += 1;
            break;
    }

    tomorrow.year = d.year;
    tomorrow.month = d.month;
    tomorrow.day = d.day + 1;

    return tomorrow;
}