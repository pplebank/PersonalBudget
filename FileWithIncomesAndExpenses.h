#ifndef FILEWITHINCOMESANDEXPENSES_H
#define FILEWITHINCOMESANDEXPENSES_H

#include "XMLFile.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "CashFlow.h"
#include <vector>


using namespace std;

class FileWithIncomesAndExpenses :public XMLFile {
    int LoggedUserId;
    bool CheckIfDataBaseOfLoggedUserExists (string nameOfFile);
    bool IfFileExists(string nameOfFile);
    void CreateLoggedUserDataBase (string nameOfFile);
    void CreateFileWithBudget(string nameOfFile);
    CashFlow GetDateFromOneString (string dateInString);
    int lastSavedIdFromFile;

public:
    FileWithIncomesAndExpenses (string nameOfFileWithIncomes, string nameOfFileWithExpenses, int Id) : XMLFile(nameOfFileWithIncomes,nameOfFileWithExpenses), LoggedUserId(Id) {
    };
    void AddTransaction (string typeOfTransaction,CashFlow transactionToAdd);
    vector <CashFlow> LoadLoggedUserData(string typeOfLoadingData);
   int GetLastSavedId();
};

#endif
