#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager {
    vector <User> users;
    FileWithUsers fileWithUsers;

private:
    User EnterNewUserData();
    bool IfLoginExists(string login);
    int LoggedUserId;

public:
    UserManager(string nameOfFile) : fileWithUsers(nameOfFile) {
        LoggedUserId = 0;
    };
    void UserRegistration();
    void ListAllUsers ();
    void LoadUsersFromFile();
    void LoginUser();
    void ChangePasswordOfLoggedUser();
    bool IfUserIsLogged();
    void LogOutUser();
    int GetLoggedUserId();
    int GetNewUserId();

};

#endif
