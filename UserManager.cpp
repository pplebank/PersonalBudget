#include "UserManager.h"

void UserManager::UserRegistration() {
    User user = EnterNewUserData();

    users.push_back(user);
    fileWithUsers.AddUserToFile(user);

    cout << "Account added sucessful" << endl << endl;
    system("pause");
}

User UserManager::EnterNewUserData() {
    User user;

    user.SetId(GetNewUserId());
    string login;
    do {
        cout << "Enter login: ";
        cin >> login;
        user.SetLogin(login);
    } while (IfLoginExists(user.GetLogin()) == true);

    string password;
    cout << "Enter password: ";
    cin >> password;
    user.SetPassword(password);

    return user;
}

bool UserManager::IfLoginExists(string login) {
    for (auto itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> GetLogin() == login) {
            cout << endl << "User with this login already exists." << endl;
            return true;
        }
    }

    return false;
}

void UserManager::ListAllUsers () {
    for (auto itr = users.begin(); itr != users.end(); itr++) {
        cout << itr -> GetId() << endl;
        cout << itr -> GetLogin() << endl;
        cout << itr -> GetPassword() << endl;
    }
}

int UserManager::GetNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().GetId() + 1;
}

void UserManager::LoadUsersFromFile() {
    users = fileWithUsers.LoadUsersFromFile();
}

void UserManager::LoginUser() {
    User user;
    string login = "", password = "";

    cout << endl << "Enter login: ";
    login = AuxiliaryMethods::LoadLine();

    auto itr = users.begin();

    while (itr != users.end()) {
        if (itr -> GetLogin() == login) {
            for (int attempts = 3; attempts > 0; attempts--) {
                cout << "Enter password. Attempts: " << attempts << ": ";
                password = AuxiliaryMethods::LoadLine();

                if (itr -> GetPassword() == password) {
                    cout << endl << "You have logged in correctly." << endl << endl;
                    system("pause");
                    LoggedUserId = itr -> GetId();
                    return;
                }
            }
            cout << "You have entered wrong password 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "There is no user with this login." << endl << endl;
    system("pause");
    return;
}

void UserManager::ChangePasswordOfLoggedUser() {
    if (IfUserIsLogged()) {

        string newPassword = "";
        cout << "Enter new password: ";
        newPassword = AuxiliaryMethods::LoadLine();

        for (auto itr = users.begin(); itr != users.end(); itr++) {
            if (itr ->GetId() == LoggedUserId) {
                itr ->SetPassword(newPassword);
                cout << "Password changed sucessfuly." << endl << endl;
                system("pause");
                fileWithUsers.SaveNewPassword(*itr);
            }
        }
    }
    else
    {
        cout<<"ERROR - you are not logged!";
    }

}
bool UserManager::IfUserIsLogged() {
    if (LoggedUserId > 0 ) {
        return true;
    }
    return false;
}

int UserManager::GetLoggedUserId() {
    return LoggedUserId;
}

void UserManager::LogOutUser() {
    LoggedUserId = 0;
}
