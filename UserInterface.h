#ifndef USERINTERFACE_H
#define USERINTERFACE_H


#include <iostream>


using namespace std;

class UserInterface {
     char LoadChar();
public:
     char selectOptionFromMainMenu();
     char selectOptionFromUserMenu();
     char CategoryExpensesMenu();
     char CategoryIncomesMenu();

};


#endif
