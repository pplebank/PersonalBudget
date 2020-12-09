#include "UserInterface.h"

char UserInterface::selectOptionFromUserMenu() {
    char choice;
    bool  choiceIsCorrect = false;
    while (!choiceIsCorrect) {

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
        if (choice >= '1' && choice <='7') {
            choiceIsCorrect = true;
            return choice;
        } else {
            cout<<"There is no such option on the menu. Try again"<<endl;
            system("PAUSE");
        }
    }
}

char UserInterface::CategoryIncomesMenu() {
    char choice;
    bool  choiceIsCorrect = false;
    while (!choiceIsCorrect) {
        system("cls");
        cout <<endl;
        cout << "---------------------------" << endl;
        cout << "1.Salary." << endl;
        cout << "2.Stocks/Bonds." << endl;
        cout << "3.Company revenue." << endl;
        cout << "4.Others." << endl;
        cout << "---------------------------" << endl;
        cout << "Your choice: ";
        choice = LoadChar();
        if (choice >= '1' && choice <='4') {
            choiceIsCorrect = true;
            return choice;
        } else {
            cout<<"There is no such option on the menu. Try again"<<endl;
            system("PAUSE");
        }
    }
}

char UserInterface::CategoryExpensesMenu() {
    char choice;
    bool  choiceIsCorrect = false;
    while (!choiceIsCorrect) {
        system("cls");
        cout <<endl;
        cout << "---------------------------" << endl;
        cout << "1.Rent." << endl;
        cout << "2.Taxes." << endl;
        cout << "3.Insurance." << endl;
        cout << "4.Food." << endl;
        cout << "5.Other shopping." << endl;
        cout << "6.Others." << endl;
        cout << "---------------------------" << endl;
        cout << "Your choice: ";
        choice = LoadChar();

        if (choice >= '1' && choice <='6') {
            choiceIsCorrect = true;
            return choice;
        } else {
            cout<<"There is no such option on the menu. Try again"<<endl;
            system("PAUSE");
        }
    }
}



char UserInterface::selectOptionFromMainMenu() {
    char choice;

    bool  choiceIsCorrect = false;
    while (!choiceIsCorrect) {
        system("cls");
        cout << "    >>> MAIN MENU <<<" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Registration." << endl;
        cout << "2. Log in." << endl;
        cout << "3. Close program." << endl;
        cout << "---------------------------" << endl;
        cout << "Your choice: ";
        choice = LoadChar();
        if (choice >= '1' && choice <='3') {
            choiceIsCorrect = true;
            return choice;
        } else {
            cout<<"There is no such option on the menu. Try again"<<endl;
            system("PAUSE");
        }
    }
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
