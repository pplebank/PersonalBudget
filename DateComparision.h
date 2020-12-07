#ifndef DATECOMPARISION_H
#define DATECOMPARISION_H

#include <iostream>
#include <vector>

#include "AuxiliaryMethods.h"
#include "CashFlow.h"


using namespace std;


class DateComparision {
    static bool CompareDates(const CashFlow &d1,const CashFlow &d2);

public:
    static vector <CashFlow> SortVectorByDates (vector <CashFlow> unsortedVector);
};


#endif
