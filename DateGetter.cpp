#include "DateGetter.h"

CashFlow DateGetter::GetTodaysDate() {
    CashFlow cashFlow;
    time_t now = time(0);

    tm *ltm = localtime(&now);

    int year = 1900 + ltm->tm_year;
    int month =  1 + ltm->tm_mon;
    int day = ltm->tm_mday;

    cashFlow.SetDay(day);
    cashFlow.SetMonth(month);
    cashFlow.SetYear(year);

    return cashFlow;
}

CashFlow DateGetter::GetDateOfFirstDayOfMonth() {
    CashFlow cashFlow;
    time_t now = time(0);

    tm *ltm = localtime(&now);

    int year = 1900 + ltm->tm_year;
    int month =  1 + ltm->tm_mon;
    int day = 1;

    cashFlow.SetDay(day);
    cashFlow.SetMonth(month);
    cashFlow.SetYear(year);
    return cashFlow;
}

CashFlow DateGetter::GetDateOfLastDayOfMonth() {
    CashFlow cashFlow;
    time_t now = time(0);

    tm *ltm = localtime(&now);

    int year = 1900 + ltm->tm_year;
    int month =  1 + ltm->tm_mon;
    int day = GetLastDayOfMonth(month,year);

    cashFlow.SetDay(day);
    cashFlow.SetMonth(month);
    cashFlow.SetYear(year);
    return cashFlow;
}

int DateGetter::GetLastDayOfMonth(int month, int year) {
    if( month == 2) {
        //DODAC JEDNA FUNKCJE LEAP YEAR
        if((year%400==0) || (year%4==0 && year%100!=0)) {
            return 29;
        } else {
            return 28;
        }

    } else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
              ||month == 10 || month==12) {
        return 31;
    } else {
        return 30;
    }
}

CashFlow DateGetter::GetFirstDayOfLastMonth() {
    CashFlow cashFlow;
    time_t now = time(0);
    int day = 1;

    tm *ltm = localtime(&now);

    int month =  1 + ltm->tm_mon;
    int year = 1900 + ltm->tm_year;

    if (month !=1) {
        month--;
        cashFlow.SetDay(day);
        cashFlow.SetMonth(month);
        cashFlow.SetYear(year);
    } else {
        cashFlow = GetDateOfDecemberLastYear(month,year);
        cashFlow.SetDay(day);
    }
    return cashFlow;
}

CashFlow DateGetter::GetLastDayOfLastMonth() {
    CashFlow cashFlow;
    time_t now = time(0);
    int day;
    tm *ltm = localtime(&now);

    int month = 1 + ltm->tm_mon;
    int year =1900 + ltm->tm_year;

    if (month !=1) {
        month--;
        day = GetLastDayOfMonth(month,year);
        cashFlow.SetDay(day);
        cashFlow.SetMonth(month);
        cashFlow.SetYear(year);
    } else {
        cashFlow = GetDateOfDecemberLastYear(month,year);
        month = cashFlow.GetMonth();
        year = cashFlow.GetYear();
        day = GetLastDayOfMonth(month,year);
        cashFlow.SetDay(day);
    }
    return cashFlow;
}

CashFlow DateGetter::GetDateOfDecemberLastYear(int month, int year) {
    CashFlow cashFlow;
    //SPRAWDZIC CZY ROK NIE SPADA PONIZEJ 2000
    year--;
    month = 12;
    cashFlow.SetMonth(month);
    cashFlow.SetYear(year);
    return cashFlow;
}

