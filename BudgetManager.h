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
#include "DataChecker.h"
#include "DateGetter.h"
#include "UserInterface.h"


using namespace std;

class BudgetManager {

private:

    vector <CashFlow> incomes;
    vector <CashFlow> expenses;
    vector <CashFlow> SortVectorByDates (vector <CashFlow> unsortedVector);
    string TypeOfIncomesCategory(int choice);
    string TypeOfExpensesCategory(int choice);

    int LoggedUserId;
    int lastIncomeId;
    int lastExpenseId;
    FileWithIncomesAndExpenses fileWithIncomesAndExpenses;
    CashFlow GetTransactionData (string TypeOfTransaction);
    CashFlow SetDataIntoRecord(string enteredDate, string value, string category, int lastId);
    CashFlow GetDateForShowing(string typeOfGettingDate);

public:
    BudgetManager(string nameOfFileWithIncomes, string nameOfFileWithExpenses, int userId) : LoggedUserId(userId),
        fileWithIncomesAndExpenses(nameOfFileWithIncomes,nameOfFileWithExpenses, userId) {
        LoadAllDataOfLoggedUser();
    };
    void AddIncome();
    void AddExpense();
    void ShowBalance ();
    void LoadAllDataOfLoggedUser();
    void TEST_ShowAllIncomes();
    void TEST_ShowAllExpenses();
    void sortUnsortedContainerWithTransfers();
    void ShowBalance (CashFlow FirstDay, CashFlow LastDay);
    void ShowBalanceForThisMonth();
    void ShowBalanceForLastMonth();
    void ShowBalanceForSelectedPeriod();
};

#endif
