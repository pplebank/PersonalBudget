#include "DateComparision.h"

bool  DateComparision::CompareDates(const CashFlow &d1,const CashFlow &d2) {

    if (d1.GetYear() < d2.GetYear())
        return true;
    if (d1.GetYear() > d2.GetYear())
        return false;

    if (d1.GetMonth() < d2.GetMonth())
        return true;
    if (d1.GetMonth() > d2.GetMonth())
        return false;

    return (d1.GetDay() < d2.GetDay());
}

vector <CashFlow> DateComparision::SortVectorByDates (vector <CashFlow> unsortedVector) {
    sort(unsortedVector.begin(),unsortedVector.end(),CompareDates);
    return unsortedVector;

}
