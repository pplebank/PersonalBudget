#include "CashFlow.h"

void CashFlow::SetDay(int newDay) {
    Day = newDay;
}
void CashFlow::SetMonth (int newMonth) {
    Month = newMonth;
}
void CashFlow::SetYear (int newYear) {
    Year = newYear;
}
void CashFlow::SetValue (float newValue) {
    Value = newValue;
}

int CashFlow::GetDay()const {
    return Day;
}
int CashFlow::GetMonth()const {
    return Month;
}
int CashFlow::GetYear()const {
    return Year;
}
float CashFlow::GetValue() {
    return Value;
}

CashFlow::CashFlow(int y, int m, int d, float v) {
    Day = d;
    Month = m;
    Year = y;
    Value =v;
}

string CashFlow::GetDateInStringFormat() {
    string dayString = AuxiliaryMethods::IntIntoString(Day);
    string monthString = AuxiliaryMethods::IntIntoString(Month);
    string yearString = AuxiliaryMethods::IntIntoString(Year);
    string date = "";
    date +=yearString+"/"+monthString+"/"+dayString;
    return date;
}

void CashFlow::ShowAllData() {
    cout <<Year<<"/"<<Month<<"/"<<Day<< "Value of transfer is: "<<Value<<endl;

}
