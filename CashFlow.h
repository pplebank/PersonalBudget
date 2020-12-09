#ifndef CASHFLOW_H
#define CASHFLOW_H

#include <iostream>

#include "AuxiliaryMethods.h"


using namespace std;

class CashFlow {
    int IdTransaction;
    string Category;
    int Day;
    int Month;
    int Year;
    float Value;

public:
    CashFlow (int = 2000, int = 1, int = 1, float = 0, int =-1, string = "No Category");
    void SetDay(int newDay);
    void SetMonth (int newMonth);
    void SetYear (int newYear);
    void SetValue(float newValue);
    void SetIdTransaction (int newId);
    void SetCategory(string newCategory);
    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;
    float GetValue();
    int GetIdTransaction();
    string GetCategory();
    string GetDateInStringFormat();
    void ShowAllData();
    bool operator<(const CashFlow &d1);
    bool operator== (const CashFlow &d1);
    bool  operator<=(const CashFlow &d1);
    bool operator +=(float &number);


};

#endif
