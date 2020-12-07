#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget personalBudget("USERS.xml","INCOMES.xml","EXPENSES.xml");
    personalBudget.ListAllUsers();
    // personalBudget.RegisterUser();
    //  personalBudget.RegisterUser();
      personalBudget.LogIn();
      personalBudget.AddIncome();
      personalBudget.AddIncome();
     personalBudget.AddIncome();
  //  personalBudget.TEST_ShowAllIncomes();
   //    personalBudget.TEST_ShowAllExpenses();
    // personalBudget.ChangePasswordOfLoggedUser();


    return 0;
}
