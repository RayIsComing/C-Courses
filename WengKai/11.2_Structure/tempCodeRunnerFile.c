#include <stdio.h>
struct date {
    int month;
    int day;
    int year;
};

int main(int argc, char const *argv[])
{
    struct date today={01,31,2014};
    struct date thismonth = {thismonth.month=7,0,thismonth.year=2014};

    printf("Today's date is %i-%i-%i.\n",
        today.year,today.month,today.day);
    printf("This month is %i-%i-%i.\n",
        thismonth.year,thismonth.month,thismonth.day);
       
    return 0;
}