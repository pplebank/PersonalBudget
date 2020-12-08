#ifndef DATEGETTER_H
#define DATEGETTER_H

#include <iostream>
#include <fstream>
#include <ctime>

#include "AuxiliaryMethods.h"
#include "CashFlow.h"

using namespace std;


class DateGetter {

   static int GetLastDayOfMonth (int month, int year);
   static CashFlow GetDateOfDecemberLastYear(int month, int year);

public:
   static CashFlow GetTodaysDate();
   static CashFlow GetDateOfFirstDayOfMonth();
   static CashFlow GetDateOfLastDayOfMonth();
   static CashFlow GetFirstDayOfLastMonth();
   static CashFlow GetLastDayOfLastMonth();
};

#endif
