#ifndef USERINTERFACE_H
#define USERINTERFACE_H


#include <iostream>


using namespace std;

class UserInterface {
    static char LoadChar();
public:
    static char selectOptionFromMainMenu();
    static char selectOptionFromUserMenu();
};


#endif
