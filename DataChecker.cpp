#include "DataChecker.h"



bool DataChecker::checkIfNumberOfDaysIsCorrect (string dayString, string monthString, string yearString) {

    int year = AuxiliaryMethods::StringIntoInt(yearString);
    int month = AuxiliaryMethods::StringIntoInt(monthString);
    int day = AuxiliaryMethods::StringIntoInt(dayString);

    if( month == 2) {
        if((year%400==0) || (year%4==0 && year%100!=0)) {

            if ((day < 0)||(day > 29)) {
                return false;
            }
        } else {
            if ((day < 0)||(day > 28)) {
                return false;
            }
        }
    } else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
              ||month == 10 || month==12) {

        if ((day < 0)||(day > 31)) {
            return false;
        }
    } else {
        if ((day < 0)||(day > 30)) {
            return false;
        }
    }
    return true;
}


bool DataChecker::CheckIfEnteredDateIsInCorrectForm (string enteredDate) {
    string Year;
    string Month;
    string Day;
    int NumberOfSingleEnteredData = 1;
    string Number ="";
    for (int CharPosition = 0; CharPosition <= enteredDate.length(); CharPosition++) {
        if ((enteredDate[CharPosition] != '-')&&(CharPosition != enteredDate.length())) {
            Number += enteredDate[CharPosition];
        } else {
            switch(NumberOfSingleEnteredData) {
            case 1:
                Year = Number;
                break;
            case 2:
                Month = Number;
                break;
            case 3:
                Day = Number;
                break;
            }
            Number = "";
            NumberOfSingleEnteredData++;
        }
    }
    if (!CheckIfEnteredYearIsCorrect(Year)) {
        return false;
    }
    if (!CheckIfEnteredMonthIsCorrect(Month)) {
        return false;
    }
    if (!CheckIfEnteredDayIsCorrect(Day)) {
        return false;
    }

    if (!checkIfNumberOfDaysIsCorrect(Day,Month,Year)) {
        return false;
    }
    return true;
}


bool DataChecker::CheckIfEnteredYearIsCorrect (string Year) {
    if (Year.size() != 4) {
        return false;
    }
    if (!ifStringConsistOnlyDigits(Year)) {
        return false;
    }
    int YearInt = AuxiliaryMethods::StringIntoInt(Year);
    if (YearInt < 2000) {
        return false;
    }
    return true;
}
bool DataChecker::CheckIfEnteredMonthIsCorrect (string Month) {

    if (Month.size() != 2) {
        return false;
    }
    if (!ifStringConsistOnlyDigits(Month)) {
        return false;
    }
    int MonthInt = AuxiliaryMethods::StringIntoInt(Month);
    if ((MonthInt < 0)||(MonthInt > 12)) {
        return false;
    }
    return true;
}

bool DataChecker::CheckIfEnteredDayIsCorrect (string Day) {
    if (Day.size() != 2) {
        return false;
    }
    if (!ifStringConsistOnlyDigits(Day)) {
        return false;
    }
    return true;
}

bool DataChecker::CheckIfEnteredValueIsFloat(string enteredValue) {
    string PartBeforeFullStop;
    string PartAterFullStop;
    int NumberOfSingleEnteredData = 1;
    string Number ="";
    for (int CharPosition = 0; CharPosition <= enteredValue.length(); CharPosition++) {
        if ((enteredValue[CharPosition] != '.')&&(CharPosition != enteredValue.length())) {
            Number += enteredValue[CharPosition];
        } else {
            switch(NumberOfSingleEnteredData) {
            case 1:
                PartBeforeFullStop = Number;
                break;
            case 2:
                PartAterFullStop = Number;
                break;
            case 3:
                return false;
            }
            Number = "";
            NumberOfSingleEnteredData++;
        }
    }

    if (!ifStringConsistOnlyDigits(PartBeforeFullStop)) {
        return false;
    }
    if (PartAterFullStop !="") {
        if (!ifStringConsistOnlyDigits(PartAterFullStop)) {
            return false;
        }

        if (PartAterFullStop.size() > 2) {
            return false;
        }
    }
    return true;
}

bool DataChecker::CheckIfEnteredValueIsInCorrectForm (string value) {
    value = CorrectFormOfValue(value);
    if (!CheckIfEnteredValueIsFloat) {
        return false;
    }
    return true;
}


bool DataChecker::ifStringConsistOnlyDigits(const string& number) {
    return !number.empty() && find_if(number.begin(),
    number.end(), [](unsigned char Char) {
        return !std::isdigit(Char);
    }) == number.end();
}

string DataChecker::CorrectFormOfValue (string value) {
    size_t Comma = value.find(',');

    if (Comma!=string::npos) {
        value.replace(Comma,1,".");
    }

    if (value[0] == '-') {
        value.erase(0,1);
    }
    return value;
}
