#include "FileWithUsers.h"

vector <User> FileWithUsers::LoadUsersFromFile() {
    User user;
    vector <User> users;
    int id;
    CMarkup xmlFile;
    bool fileExists = xmlFile.Load(NAME_OF_FILE);
    if (!fileExists) {
        CreateFileWithTemplate();
        xmlFile.Load(NAME_OF_FILE);
    }
    xmlFile.FindChildElem("USERS");
    xmlFile.IntoElem();
    while(xmlFile.FindElem("USER")) {
        xmlFile.FindChildElem("LOGIN");
        user.SetLogin(xmlFile.GetChildData());
        xmlFile.FindChildElem("ID");
        id = AuxiliaryMethods::StringIntoInt(xmlFile.GetChildData());
        user.SetId(id);
        xmlFile.FindChildElem("PASSWORD");
        user.SetPassword(xmlFile.GetChildData());
        users.push_back(user);
    }

    return users;
}

void FileWithUsers::CreateFileWithTemplate() {
    CMarkup xmlFile;
    xmlFile.AddElem("USERS");
    xmlFile.Save(NAME_OF_FILE);
}

void FileWithUsers::AddUserToFile (User user) {
    CMarkup xmlFile;
    bool fileExists = xmlFile.Load(NAME_OF_FILE);
    if (fileExists) {
        xmlFile.FindElem("USERS");
        xmlFile.IntoElem();
        xmlFile.AddElem("USER");
        xmlFile.AddChildElem("LOGIN",user.GetLogin());
        xmlFile.AddChildElem("ID",AuxiliaryMethods::IntIntoString(user.GetId()));
        xmlFile.AddChildElem("PASSWORD", user.GetPassword());
        xmlFile.Save(NAME_OF_FILE);
    }

    else {
        cout<<"ERROR - Problem with file.";
    }
}

void FileWithUsers::SaveNewPassword(User user) {
    CMarkup xmlFile;
    bool fileExists = xmlFile.Load(NAME_OF_FILE);
    if (fileExists) {
        xmlFile.FindElem("USERS");
        xmlFile.IntoElem();
        while(xmlFile.FindElem("USER")) {
            xmlFile.FindChildElem("LOGIN");
            if(xmlFile.GetChildData() == user.GetLogin()) {
                xmlFile.FindChildElem("PASSWORD");
                xmlFile.SetChildData(user.GetPassword());
                xmlFile.Save(NAME_OF_FILE);
                cout <<"Password changed correctly";
            }
        }
    } else {
        cout<<"ERROR - Problem with file.";
    }
}
