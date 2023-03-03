#include <iostream>
#include <stdlib.h>
#include <stdio.h>

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
    cout << d.month << "/" << d.day << "/" << d.year << endl;
}

// takes a date structure and returns the next date
date tomorrow(date d) {
    date tomorrow;

    tomorrow.year = d.year;
    tomorrow.month = d.month;
    tomorrow.day = d.day;

    switch (d.day) {
        case 28:
            if (d.month == 2) {
                tomorrow.day = 1;
                tomorrow.month = 3;
            } else {
                tomorrow.day+=1;
            }
            break;
        case 30:
            if (d.month == 7 || d.month == 4 || d.month == 6 || d.month == 11) {
                tomorrow.day = 1;
                tomorrow.month+=1;
            } else
                tomorrow.day+=1;
            break;
        case 31:
            if (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 8 || d.month == 9 || d.month == 10) {
                tomorrow.day = 1;
                tomorrow.month+=1;
            }
            if (d.month == 12) {
                tomorrow.day = 1;
                tomorrow.month = 1;
                tomorrow.year+=1;
            } else
                tomorrow.day+=1;
            break;
        default:
            tomorrow.day+=1;
            break;
    }

    return tomorrow;
} // end tomorrow


void printTempData(tempData arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << "The temperature was: " << arr[i].temp << " on ";
        printDate(arr[i].date_);
    }
}

tempData* averageTempData(tempData a1[], tempData a2[], int size)
{
    tempData *result = (tempData*) malloc(size * sizeof(tempData));
    for(int i = 0; i < size; i++)
    {
        result[i] = {a1[i].date_, (a1[i].temp + a2[i].temp)/2.0};
    }

    return result;
}


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
    cout << "  expected output: 03/01/1900" << endl;

    /*  Task 2
 * Define a structure tempData that has a nested structure date (already defined) and a temperature reading (a double).
 */

// Question 1: Print out the size of this structure and write it down in comments.
cout << sizeof(tempData) << endl;
// 24 bytes

// Question 2: Create two 5-element arrays of these structures (statically, not using malloc): highest and lowest,
// representing the highest and the lowest temperature readings of the day. The dates for the two arrays should be the same.
tempData h1 = {{2023, 01, 01}, 12.4};
tempData l1 = {{2023, 01, 01}, 2.5};
tempData h2 = {{2023, 01, 01}, 32.4};
tempData l2 = {{2023, 01, 01}, 14.2};
tempData h3 = {{2023, 01, 01}, 3.9};
tempData l3 = {{2023, 01, 01}, -1.3};
tempData h4 = {{2023, 01, 01}, 21.4};
tempData l4 = {{2023, 01, 01}, 13.2};
tempData h5 = {{2023, 01, 01}, 27.7};
tempData l5 = {{2023, 01, 01}, 6.3};
static tempData highest[5] = {h1,h2,h3,h4,h5};
static tempData lowest[5] = {l1,l2,l3,l4,l5};

// Question 3: Write a function that takes an array of tempData structures and it's size and prints it out in a human-readable format.
// In comments for the function explain why it needs the size.
cout << "highest: " << endl;
printTempData(highest, 5);

cout << "lowest: " << endl;
printTempData(lowest,5);
// printTempData needs the size because if you don't give it the size, it will use the pointer size, rather than the
// size of the array.


// Question 4: Write a function that takes two arrays of tempData and their size (assuming that they are the same size), allocates
// a new array of tempData of the same size, and fills it with the average temperatures of the two arrays (make sure to set the dates as well).
// The return type is the pointer to the new array.
tempData *avgtemp;
avgtemp = averageTempData(highest, lowest, 5);

cout << "average: " << endl;
printTempData(avgtemp, 5);
}