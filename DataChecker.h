#ifndef DATACHECKER_H
#define DATACHECKER_H

#include <vector>
#include <iostream>
#include "User.h"
#include "AuxiliaryMethods.h"
#include "DateGetter.h"
#include "CashFlow.h"


using namespace std;

class DataChecker {
   static bool checkIfNumberOfDaysIsCorrect (string dayString, string monthString, string yearString);
   static bool CheckIfEnteredYearIsCorrect (string Year);
   static bool CheckIfEnteredMonthIsCorrect (string Month);
   static bool CheckIfEnteredDayIsCorrect (string Day);
   static bool CheckIfEnteredValueIsFloat (string enteredValue);
   static string IfIsCommaInsteadFullStop (string Value);
   static string CheckIfThereIsMinusSymbolBeforeValue (string Value);
   static bool ifStringConsistOnlyDigits(const string& number);
    static bool checkIfDateIsNotInFuture(string Day,string Month,string Year);

public:
    static string CorrectFormOfValue(string value);
    static bool CheckIfEnteredValueIsInCorrectForm (string value);
    static bool CheckIfEnteredDateIsInCorrectForm (string enteredDate);
};

#endif
