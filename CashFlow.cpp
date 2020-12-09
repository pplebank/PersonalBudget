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

void CashFlow::SetIdTransaction (int newId) {
    IdTransaction = newId;
}
void CashFlow::SetCategory(string newCategory) {
    Category = newCategory;
}

int CashFlow::GetIdTransaction () {
    return IdTransaction;
}
string CashFlow::GetCategory() {
    return Category;
}


CashFlow::CashFlow(int y, int m, int d, float v,int i, string c) {
    Day = d;
    Month = m;
    Year = y;
    Value =v;
    IdTransaction = i;
    Category = c;
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

bool  CashFlow::operator<(const CashFlow &d1) {

    if (this->Year < d1.GetYear())
        return true;

    if ((this->Year == d1.GetYear())&&(this->Month < d1.GetMonth()))
        return true;

    if ((this->Year == d1.GetYear())&&(this->Month == d1.GetMonth())&&(this->Day < d1.GetDay()))
        return true;
    else
        return false;
}

bool CashFlow::operator== (const CashFlow &d1)   {

    return ((Day == d1.GetDay())&&(Month == d1.GetMonth())&&(Year == d1.GetYear()));
}

bool  CashFlow::operator<=(const CashFlow &d1)  {
    if (this->operator==(d1)) {
        return true;
    } else {
        return this->operator<(d1);
    }
}

bool CashFlow::operator +=(float &number) {
    number+=this->GetValue();
    return number;
}

