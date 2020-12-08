#include "UserInterface.h"

char UserInterface::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add Income." << endl;
    cout << "2. Add Expense." << endl;
    cout << "3. Show balance for this month." << endl;
    cout << "4. Show balance for last month." << endl;
    cout << "5. Show balance for selected period." << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password." << endl;
    cout << "7. Log out." << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = LoadChar();

    return choice;
}


char UserInterface::selectOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration." << endl;
    cout << "2. Log in." << endl;
    cout << "3. Close program." << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = LoadChar();

    return choice;
}

char UserInterface::LoadChar() {
    string input = "";
    char choice  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            choice = input[0];
            break;
        }
        cout << "It's not a single character. Please try again." << endl;
    }
    return choice;
}
