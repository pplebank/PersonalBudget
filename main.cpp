#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget personalBudget("USERS.xml","INCOMES.xml","EXPENSES.xml");
    personalBudget.ListAllUsers();
    // personalBudget.RegisterUser();
    //  personalBudget.RegisterUser();
    personalBudget.LogIn();
    personalBudget.TEST_ShowAllIncomes();
    personalBudget.sortContainersWithData();
    cout<<"-------------------------------------"<<endl;
    personalBudget.TEST_ShowAllIncomes();
    //  personalBudget.AddIncome();
    //   personalBudget.AddIncome();
    // personalBudget.AddIncome();
    // personalBudget.ChangePasswordOfLoggedUser();


    return 0;
}
