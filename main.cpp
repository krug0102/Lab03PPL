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

typedef struct {
    date date_;
    double temp;
} tempData;

date tomorrow(date);

void printDate(date d) {
    cout << (d.month < 10 ? "0" : "") << d.month << "/"
         << (d.day < 10 ? "0" : "") << d.day << "/"
         << d.year;
}

// takes a date structure and returns the next date
date tomorrow(date d) {
    date tomorrow;

    tomorrow.year = d.year;
    tomorrow.month = d.month;


    switch (d.day) {
        case 28:
            if (d.month == 2) {
                tomorrow.day = 1;
                tomorrow.month = 3;
            } else {
                tomorrow.day = d.day + 1;
            }
            break;
        case 30:
            if (d.month == 7 || d.month == 4 || d.month == 6 || d.month == 11) {
                tomorrow.day = 1;
                tomorrow.month = d.month + 1;
            } else
                tomorrow.day = d.day + 1;
            break;
        case 31:
            if (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 8 || d.month == 9 || d.month == 10) {
                tomorrow.day = 1;
                tomorrow.month = d.month + 1;
            }
            if (d.month == 12) {
                tomorrow.day = 1;
                tomorrow.month = 1;
                tomorrow.year = d.year + 1;
            } else
                tomorrow.day = d.day + 1;
            break;
        default:
            tomorrow.day = d.day + 1;
            break;
    }

    return tomorrow;
} // end tomorrow

int main() {

    date d1 = { 2022, 2, 27 };
    date t1 = tomorrow(d1);
    printDate(d1);
    cout << " -> ";
    printDate(t1);
    cout << "  expected output: 02/28/2022" << endl;

    date d2 = { 2022, 2, 28 };
    date t2 = tomorrow(d2);
    printDate(d2);
    cout << " -> ";
    printDate(t2);
    cout << "  expected output: 03/01/2022" << endl;

    date d3 = { 2022, 4, 30 };
    date t3 = tomorrow(d3);
    printDate(d3);
    cout << " -> ";
    printDate(t3);
    cout << "  expected output: 05/01/2022" << endl;

    date d4 = { 2022, 12, 31 };
    date t4 = tomorrow(d4);
    printDate(d4);
    cout << " -> ";
    printDate(t4);
    cout << "  expected output: 01/01/2023" << endl;

    date d5 = { 2000, 2, 28 };
    date t5 = tomorrow(d5);
    printDate(d5);
    cout << " -> ";
    printDate(t5);
    cout << "  expected output: 03/01/2000" << endl;

    date d6 = { 1900, 2, 28 };
    date t6 = tomorrow(d6);
    printDate(d6);
    cout << " -> ";
    printDate(t6);
    cout << "  expected output: 03/01/1900";

}