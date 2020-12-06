#include "User.h"


void User::SetId(int newId) {
    if (newId >= 0)
        id=newId;
}
void User::SetLogin (string newLogin) {
    login = newLogin;
}
void User::SetPassword (string newPassword) {
    password = newPassword;
}

int User::GetId() {
    return id;
}
string User::GetLogin() {
    return login;
}
string User::GetPassword() {
    return password;
}
