#include "FileWithIncomesAndExpenses.h"


void FileWithIncomesAndExpenses::AddTransaction (string typeOfTransaction,CashFlow transactionToAdd) {
    CMarkup xmlFile;
    string category;
    string nameOfFile;
    if (typeOfTransaction == "Incomes") {
        nameOfFile = NAME_OF_FILE_WiTH_INCOMES;
        category = "INCOMES";
        CheckIfDataBaseOfLoggedUserExists(nameOfFile, category);

    } else {
        nameOfFile = NAME_OF_FILE_WITH_EXPENSES;
        category = "EXPENSES";
        CheckIfDataBaseOfLoggedUserExists(nameOfFile, category);
    }

    bool fileExists = xmlFile.Load(nameOfFile);
    if (fileExists) {
        xmlFile.FindElem("USERS");
        xmlFile.IntoElem();
        while( xmlFile.FindElem("USER"))
            xmlFile.FindChildElem("ID");
        if (xmlFile.GetChildData() == AuxiliaryMethods::IntIntoString(LoggedUserId)) {
            xmlFile.IntoElem();
            xmlFile.FindElem(category);
            xmlFile.IntoElem();
            xmlFile.AddElem("TRANSFER");
            xmlFile.AddChildElem("DATE",transactionToAdd.GetDateInStringFormat());
            xmlFile.AddChildElem("VALUE",AuxiliaryMethods::FloatIntoString(transactionToAdd.GetValue()));
            xmlFile.Save(nameOfFile);
        }
    }
    return;
}

vector <CashFlow> FileWithIncomesAndExpenses::LoadLoggedUserData(string typeOfLoadingData) {

    CMarkup xmlFile;
    string nameOfFile;
    string category;
    string dateInString;
    string valueInString;
    CashFlow cashFlow;

    if (typeOfLoadingData == "Incomes") {
        nameOfFile = NAME_OF_FILE_WiTH_INCOMES;
        category = "INCOMES";
    } else {
        nameOfFile = NAME_OF_FILE_WITH_EXPENSES;
        category = "EXPENSES";
    }
    bool fileExists = xmlFile.Load(nameOfFile);
    if (!fileExists) {
        CreateFileWithBudget(nameOfFile);
        xmlFile.Load(nameOfFile);
    }

    if (!CheckIfDataBaseOfLoggedUserExists(nameOfFile,category)) {
        CreateLoggedUserDataBase(nameOfFile,category);
    }

    xmlFile.FindElem("USERS");
    xmlFile.IntoElem();
    while( xmlFile.FindElem("USER")) {
        xmlFile.FindChildElem("ID");
        if (xmlFile.GetChildData() == AuxiliaryMethods::IntIntoString(LoggedUserId)) {
            xmlFile.IntoElem();
            xmlFile.FindElem(category);
            xmlFile.IntoElem();
            while( xmlFile.FindElem("TRANSFER")) {
                xmlFile.FindChildElem("DATE");
                dateInString = xmlFile.GetChildData();
                cashFlow = GetDateFromOneString(dateInString);
                xmlFile.FindChildElem("VALUE");
                valueInString = xmlFile.GetChildData();
                cashFlow.SetValue(AuxiliaryMethods::StringIntoFloat(valueInString));
                transfers.push_back(cashFlow);
            }
        }
    }

    //TEST//
    /*
    for (auto itr = transfers.begin(); itr != transfers.end(); itr++) {
        itr->ShowAllData();
    }
*/
    return transfers;
}


void FileWithIncomesAndExpenses::CreateFileWithBudget(string nameOfFile) {
    CMarkup xmlFile;
    xmlFile.AddElem("USERS");
    xmlFile.Save(nameOfFile);
    return;
}

void FileWithIncomesAndExpenses::CreateLoggedUserDataBase (string nameOfFile, string category) {
    CMarkup xmlFile;
    xmlFile.Load(nameOfFile);
    xmlFile.FindElem("USERS");
    xmlFile.IntoElem();
    xmlFile.AddElem("USER");
    xmlFile.AddChildElem("ID",AuxiliaryMethods::IntIntoString(LoggedUserId));
    xmlFile.AddChildElem(category);
    xmlFile.Save(nameOfFile);
    return;
}


bool FileWithIncomesAndExpenses::CheckIfDataBaseOfLoggedUserExists (string nameOfFile, string category) {
    CMarkup xmlFile;

    bool fileExists = xmlFile.Load(nameOfFile);
    if (fileExists) {
        if( xmlFile.FindElem("USERS")) {
            xmlFile.IntoElem();
            while(xmlFile.FindElem("USER")) {
                xmlFile.FindChildElem("ID");
                if (xmlFile.GetChildData() == AuxiliaryMethods::IntIntoString(LoggedUserId)) {
                    xmlFile.IntoElem();
                    if (xmlFile.FindElem(category)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


CashFlow FileWithIncomesAndExpenses::GetDateFromOneString (string dateInString) {

    //PODOBNE DO TEGO Z USER MANAGERA, DO REFACTORU//
    CashFlow cashFlowWithDate;
    string Year;
    string Month;
    string Day;
    int NumberOfSingleEnteredData = 1;
    string Number ="";
    for (int CharPosition = 0; CharPosition <= dateInString.length(); CharPosition++) {
        if ((dateInString[CharPosition] != '/')&&(CharPosition != dateInString.length())) {
            Number += dateInString[CharPosition];
        } else {
            switch(NumberOfSingleEnteredData) {
            case 1:
                Year = Number;
                break;
            case 2:
                Month = Number;
                break;
            case 3:
                Day = Number;
                break;
            }
            Number = "";
            NumberOfSingleEnteredData++;
        }
    }
    int yearInt = AuxiliaryMethods::StringIntoInt(Year);
    int monthInt = AuxiliaryMethods::StringIntoInt(Month);
    int dayInt = AuxiliaryMethods::StringIntoInt(Day);

    cashFlowWithDate.SetDay(dayInt);
    cashFlowWithDate.SetMonth(monthInt);
    cashFlowWithDate.SetYear(yearInt);

    return cashFlowWithDate;
}
