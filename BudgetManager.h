#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "FileWithIncomesAndExpenses.h"
#include "CashFlow.h"


using namespace std;

class BudgetManager {


private:

    vector <CashFlow> incomes;
    vector <CashFlow> expenses;

    int LoggedUserId;
    FileWithIncomesAndExpenses fileWithIncomesAndExpenses;
    CashFlow GetTransactionData (string TypeOfTransaction);
    bool checkIfNumberOfDaysIsCorrect (string dayString, string monthString, string yearString);
    bool CheckIfEnteredDateIsInCorrectForm (string enteredDate);
    bool CheckIfEnteredYearIsCorrect (string Year);
    bool CheckIfEnteredMonthIsCorrect (string Month);
    bool CheckIfEnteredDayIsCorrect (string Day);
    bool CheckIfEnteredValueIsInCorrectForm (string enteredValue);
    bool IfEnteredValueIsInCorrectForm (string Value);
    string IfIsCommaInsteadFullStop (string Value);
    string CheckIfThereIsMinusSymbolBeforeValue (string Value);
    bool ifStringConsistOnlyDigits(const string& number);
    CashFlow SetDataIntoRecord(string enteredDate, string value);

public:
    BudgetManager(string nameOfFileWithIncomes, string nameOfFileWithExpenses, int userId) : fileWithIncomesAndExpenses(nameOfFileWithIncomes,nameOfFileWithExpenses, userId),
    LoggedUserId(userId) {
        LoadAllDataOfLoggedUser();
    };
    void AddIncome();
    void AddExpense();
    void ShowBalance ();
    void LoadAllDataOfLoggedUser();
};

#endif
