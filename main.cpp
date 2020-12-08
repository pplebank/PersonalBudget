#include <iostream>

#include "PersonalBudget.h"
#include "UserInterface.h"

using namespace std;

int TEST_main() {
    PersonalBudget personalBudget("USERS.xml","INCOMES.xml","EXPENSES.xml");
    personalBudget.ListAllUsers();
    // personalBudget.RegisterUser();
    //  personalBudget.RegisterUser();
    personalBudget.LogIn();
   // personalBudget.ShowBalanceForThisMonth();
      personalBudget.AddIncome();
    //   personalBudget.AddIncome();
    // personalBudget.AddIncome();
    // personalBudget.ChangePasswordOfLoggedUser();


    return 0;
}



int main() {

    char choice;


        PersonalBudget personalBudget("USERS.xml","INCOMES.xml","EXPENSES.xml");
        UserInterface userInterface;

    while (true) {
        if (personalBudget.IfUserIsLogged() == false) {
            choice = userInterface.selectOptionFromMainMenu();
            switch (choice) {
            case '1':
                personalBudget.RegisterUser();
                break;
            case '2':
                personalBudget.LogIn();
                break;
            case '3':
                exit(0);
                break;
            default:
                cout << endl << "There is no option like that in menu. Try again.." << endl << endl;
                system("pause");
                break;
            }
        }
        else {
            choice = userInterface.selectOptionFromUserMenu();
            switch (choice) {
            case '1':
                personalBudget.AddIncome();
                break;
            case '2':
                personalBudget.AddExpense();
                break;
            case '3':
                personalBudget.ShowBalanceForThisMonth();
                break;
            case '4':
                personalBudget.ShowBalanceForLastMonth();
                break;
            case '5':
                personalBudget.ShowBalanceForSelectedPeriod();
                break;
            case '6':
                personalBudget.ChangePasswordOfLoggedUser();
                break;
            case '7':
                personalBudget.LogOut();
                break;
            }
        }
    }
    return 0;
}
