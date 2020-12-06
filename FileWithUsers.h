#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <vector>
#include <iostream>
#include "User.h"
#include "XMLFile.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"


using namespace std;

class FileWithUsers :public XMLFile
{
void CreateFileWithTemplate();
public:
FileWithUsers(string NameOfFile) : XMLFile(NameOfFile) {};

void AddUserToFile (User user);
vector <User> LoadUsersFromFile();
void SaveNewPassword(const User user);

};

#endif
