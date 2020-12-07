#ifndef DATEGETTER_H
#define DATEGETTER_H

#include <iostream>
#include <fstream>
#include <ctime>

#include "AuxiliaryMethods.h"
#include "CashFlow.h"

using namespace std;


class DateGetter {

    int GetLastDayOfMonth (int month, int year);
    CashFlow GetDateOfDecemberLastYear(int month, int year);

public:
    CashFlow GetTodaysDate();
    CashFlow GetDateOfFirstDayOfMonth();
    CashFlow GetDateOfLastDayOfMonth();
    CashFlow GetFirstDayOfLastMonth();
    CashFlow GetLastDayOfLastMonth();
};

#endif
