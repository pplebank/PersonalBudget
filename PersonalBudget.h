#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class PersonalBudget  {

    UserManager userManager;
    BudgetManager *budgetManager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;
public:
    PersonalBudget (string nameOfFileWithUsers, string nameOfFileWithIncomes,string nameOfFileWithExpenses) : userManager(nameOfFileWithUsers),
        NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes),NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses) {
        LoadAllUsers();
    };
    void LoadAllUsers ();
    void RegisterUser();
    void ListAllUsers();
    void LogIn();
    void ChangePasswordOfLoggedUser();
    void sortContainersWithData();
    void AddIncome();
    void AddExpense();
    void ShowBalanceForThisMonth();
    void ShowBalanceForLastMonth();
    void ShowBalanceForSelectedPeriod();
    void TEST_ShowAllIncomes();
    void TEST_ShowAllExpenses();
    bool IfUserIsLogged();
    void LogOut();

    ~PersonalBudget() {
        delete budgetManager;
        budgetManager = NULL;

    }
};

#endif
