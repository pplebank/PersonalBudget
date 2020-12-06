#include "BudgetManager.h"

void BudgetManager::LoadAllDataOfLoggedUser ()
{
    incomes = fileWithIncomesAndExpenses.LoadLoggedUserData("Incomes");
    expenses = fileWithIncomesAndExpenses.LoadLoggedUserData("Expenses");
}


void BudgetManager::AddIncome() {
    CashFlow cashFlow;
   string typeOfTransaction = "Income";
    cashFlow = GetTransactionData(typeOfTransaction);
    incomes.push_back(cashFlow);
    fileWithIncomesAndExpenses.AddTransaction(typeOfTransaction,cashFlow);
}
void BudgetManager::AddExpense() {
    CashFlow cashFlow;
   string typeOfTransaction = "Expense";
    cashFlow = GetTransactionData(typeOfTransaction);
    expenses.push_back(cashFlow);
    fileWithIncomesAndExpenses.AddTransaction(typeOfTransaction, cashFlow);
}


void ShowBalance ();

CashFlow BudgetManager::GetTransactionData (string typeOfTransaction) {

    CashFlow cashFlow;
    string date;
    string value;

    cout << "Enter Date of "<<typeOfTransaction<<endl;
    cout <<"Please enter in yyyy-mm-dd format, e.g 2015-04-24"<<endl;
    date = AuxiliaryMethods::LoadLine();
    if (CheckIfEnteredDateIsInCorrectForm(date)) {
        cout <<"Date entered in correct form."<<endl;

        cout<<"Please enter value of "<<typeOfTransaction<<endl;
        cout <<"Please enter in xxxxx.xx format, e.g 2000.55"<<endl;
        value = AuxiliaryMethods::LoadLine();
        if (IfEnteredValueIsInCorrectForm(value)) {
            cout <<"Value entered in correct form."<<endl;
            cashFlow = SetDataIntoRecord(date,value);
            return cashFlow;
        } else {
            cout<<"Value entered in wrong format. Try again."<<endl;
        }
    } else {
        cout<<"Date entered in wrong format. Try again."<<endl;
    }
}

CashFlow BudgetManager::SetDataIntoRecord(string enteredDate, string enteredValue) {
    CashFlow cashFlow;
    string Year;
    string Month;
    string Day;
    int NumberOfSingleEnteredData = 1;
    string Number ="";
    for (int CharPosition = 0; CharPosition <= enteredDate.length(); CharPosition++) {
        if ((enteredDate[CharPosition] != '-')&&(CharPosition != enteredDate.length())) {
            Number += enteredDate[CharPosition];
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

    cashFlow.SetDay(dayInt);
    cashFlow.SetMonth(monthInt);
    cashFlow.SetYear(yearInt);

    float valueFloat = AuxiliaryMethods::StringIntoFloat(enteredValue);
    cashFlow.SetValue(valueFloat);

    return cashFlow;
}


bool BudgetManager::checkIfNumberOfDaysIsCorrect (string dayString, string monthString, string yearString) {

    int year = AuxiliaryMethods::StringIntoInt(yearString);
    int month = AuxiliaryMethods::StringIntoInt(monthString);
    int day = AuxiliaryMethods::StringIntoInt(dayString);

    if( month == 2) {
        if((year%400==0) || (year%4==0 && year%100!=0)) {

            if ((day < 0)||(day > 29)) {
                return false;
            }
        } else {
            if ((day < 0)||(day > 28)) {
                return false;
            }
        }
    } else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
              ||month == 10 || month==12) {

        if ((day < 0)||(day > 31)) {
            return false;
        }
    } else {
        if ((day < 0)||(day > 30)) {
            return false;
        }
    }
    return true;
}


bool BudgetManager::CheckIfEnteredDateIsInCorrectForm (string enteredDate) {
    string Year;
    string Month;
    string Day;
    int NumberOfSingleEnteredData = 1;
    string Number ="";
    for (int CharPosition = 0; CharPosition <= enteredDate.length(); CharPosition++) {
        if ((enteredDate[CharPosition] != '-')&&(CharPosition != enteredDate.length())) {
            Number += enteredDate[CharPosition];
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
    if (!CheckIfEnteredYearIsCorrect(Year)) {
        return false;
    }
    if (!CheckIfEnteredMonthIsCorrect(Month)) {
        return false;
    }
    if (!CheckIfEnteredDayIsCorrect(Day)) {
        return false;
    }

    if (!checkIfNumberOfDaysIsCorrect(Day,Month,Year)) {
        return false;
    }
    return true;
}


bool BudgetManager::CheckIfEnteredYearIsCorrect (string Year) {
    if (Year.size() != 4) {
        return false;
    }
    if (!ifStringConsistOnlyDigits(Year)) {
        return false;
    }
    int YearInt = AuxiliaryMethods::StringIntoInt(Year);
    if (YearInt < 2000) {
        return false;
    }
    return true;
}
bool BudgetManager::CheckIfEnteredMonthIsCorrect (string Month) {

    if (Month.size() != 2) {
        return false;
    }
    if (!ifStringConsistOnlyDigits(Month)) {
        return false;
    }
    int MonthInt = AuxiliaryMethods::StringIntoInt(Month);
    if ((MonthInt < 0)||(MonthInt > 12)) {
        return false;
    }
    return true;
}

bool BudgetManager::CheckIfEnteredDayIsCorrect (string Day) {
    if (Day.size() != 2) {
        return false;
    }
    if (!ifStringConsistOnlyDigits(Day)) {
        return false;
    }
    return true;
}

bool BudgetManager::CheckIfEnteredValueIsInCorrectForm (string enteredValue) {
    string PartBeforeFullStop;
    string PartAterFullStop;
    int NumberOfSingleEnteredData = 1;
    string Number ="";
    for (int CharPosition = 0; CharPosition <= enteredValue.length(); CharPosition++) {
        if ((enteredValue[CharPosition] != '.')&&(CharPosition != enteredValue.length())) {
            Number += enteredValue[CharPosition];
        } else {
            switch(NumberOfSingleEnteredData) {
            case 1:
                PartBeforeFullStop = Number;
                break;
            case 2:
                PartAterFullStop = Number;
                break;
            case 3:
                return false;
            }
            Number = "";
            NumberOfSingleEnteredData++;
        }
    }

    if (!ifStringConsistOnlyDigits(PartBeforeFullStop)) {
        return false;
    }
    if (PartAterFullStop !="") {
        if (!ifStringConsistOnlyDigits(PartAterFullStop)) {
            return false;
        }

        if (PartAterFullStop.size() > 2) {
            return false;
        }
    }
    return true;
}

bool BudgetManager::IfEnteredValueIsInCorrectForm (string Value) {
    Value = IfIsCommaInsteadFullStop(Value);
    Value = CheckIfThereIsMinusSymbolBeforeValue(Value);
    if (!CheckIfEnteredValueIsInCorrectForm(Value)) {
        return false;
    }
    return true;
}

string BudgetManager::IfIsCommaInsteadFullStop (string Value) {
    size_t Comma = Value.find(',');

    if (Comma!=string::npos) {
        Value.replace(Comma,1,".");
    }
    return Value;
}

string BudgetManager::CheckIfThereIsMinusSymbolBeforeValue (string Value) {
    if (Value[0] == '-') {
        Value.erase(0,1);
    }
    return Value;
}


bool BudgetManager::ifStringConsistOnlyDigits(const string& number) {
    return !number.empty() && find_if(number.begin(),
    number.end(), [](unsigned char Char) {
        return !std::isdigit(Char);
    }) == number.end();
}
