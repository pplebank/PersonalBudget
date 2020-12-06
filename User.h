#ifndef USER_H
#define USER_H

#include <iostream>


using namespace std;

class User
{
    int id;
    string login;
    string password;

public:
    void SetId(int newId);
    void SetLogin (string newLogin);
    void SetPassword (string newPassword);
    int GetId();
    string GetLogin();
    string GetPassword();

};

#endif
