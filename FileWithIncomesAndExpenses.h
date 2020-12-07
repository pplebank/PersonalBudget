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
    bool CheckIfDataBaseOfLoggedUserExists (string nameOfFile, string category);
    bool IfFileExists(string nameOfFile);
    void CreateLoggedUserDataBase (string nameOfFile, string category);
    void CreateFileWithBudget(string nameOfFile);
    CashFlow GetDateFromOneString (string dateInString);

public:
    FileWithIncomesAndExpenses (string nameOfFileWithIncomes, string nameOfFileWithExpenses, int Id) : XMLFile(nameOfFileWithIncomes,nameOfFileWithExpenses), LoggedUserId(Id) {
    };
    void AddTransaction (string typeOfTransaction,CashFlow transactionToAdd);
    vector <CashFlow> LoadLoggedUserData(string typeOfLoadingData);
};

#endif
