#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("USERS.xml","EXPENSES.xml","INCOMES.xml");
    personalBudget.ListAllUsers();
   // personalBudget.RegisterUser();
  //  personalBudget.RegisterUser();
    personalBudget.LogIn();
    personalBudget.AddIncome();
   // personalBudget.ChangePasswordOfLoggedUser();


    return 0;
}
