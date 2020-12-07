#ifndef CASHFLOW_H
#define CASHFLOW_H

#include <iostream>

#include "AuxiliaryMethods.h"


using namespace std;

class CashFlow {
    int Day;
    int Month;
    int Year;
    float Value;

public:
    CashFlow (int = 2000, int = 1, int = 1, float = 0);
    void SetDay(int newDay);
    void SetMonth (int newMonth);
    void SetYear (int newYear);
    void SetValue(float newValue);
    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;
    float GetValue();
    string GetDateInStringFormat();
    void ShowAllData();


};

#endif
