#include "BudgetManager.h"

vector <CashFlow> BudgetManager::SortVectorByDates (vector <CashFlow> unsortedVector) {
    sort(unsortedVector.begin(),unsortedVector.end(),[](CashFlow&a,CashFlow&b)->bool {return a<b;});
    return unsortedVector;
}

void BudgetManager::LoadAllDataOfLoggedUser () {
    incomes = fileWithIncomesAndExpenses.LoadLoggedUserData("Incomes");
    lastIncomeId = fileWithIncomesAndExpenses.GetLastSavedId();
    expenses = fileWithIncomesAndExpenses.LoadLoggedUserData("Expenses");
    lastExpenseId = fileWithIncomesAndExpenses.GetLastSavedId();
}

void BudgetManager::sortUnsortedContainerWithTransfers() {
    incomes = SortVectorByDates(incomes);
    expenses = SortVectorByDates(expenses);
}


void BudgetManager::AddIncome() {
    CashFlow cashFlow;
    string typeOfTransaction = "Incomes";
    cashFlow = GetTransactionData(typeOfTransaction);
    incomes.push_back(cashFlow);
    fileWithIncomesAndExpenses.AddTransaction(typeOfTransaction,cashFlow);
}
void BudgetManager::AddExpense() {
    CashFlow cashFlow;
    string typeOfTransaction = "Expenses";
    cashFlow = GetTransactionData(typeOfTransaction);
    expenses.push_back(cashFlow);
    fileWithIncomesAndExpenses.AddTransaction(typeOfTransaction, cashFlow);
}

void BudgetManager::ShowBalanceForThisMonth() {
    CashFlow firstDay = DateGetter::GetDateOfFirstDayOfMonth();
    CashFlow lastDay = DateGetter::GetTodaysDate();
    ShowBalance(firstDay,lastDay);
}


void BudgetManager::ShowBalanceForLastMonth() {
    CashFlow firstDay = DateGetter::GetFirstDayOfLastMonth();
    CashFlow lastDay = DateGetter::GetLastDayOfLastMonth();
    ShowBalance(firstDay,lastDay);


}

void BudgetManager::ShowBalanceForSelectedPeriod() {
    string firstDayDescription = "first selected period day.";
    string lastDayDescription = "last selected period day.";
    CashFlow firstDay = GetDateForShowing(firstDayDescription);
    CashFlow lastDay = GetDateForShowing(lastDayDescription);
    ShowBalance(firstDay,lastDay);


}



void BudgetManager::ShowBalance (CashFlow FirstDay, CashFlow LastDay) {
    sortUnsortedContainerWithTransfers();

    float allIncomes = 0;
    float allExpenses = 0;
    float BalanceForSelectedPeriod = 0;

    for (auto itr = incomes.begin(); itr != incomes.end() ; itr++) {
        if ((FirstDay<=*itr)&&(*itr<=LastDay)) {
            itr->ShowAllData();
            allIncomes+=itr->GetValue();
        }
    }
    cout<<endl<<"Yours Incomes for selected are: "<<allIncomes<<endl;
    cout<<"---------------------------------------------------------"<<endl;

    for (auto itr = expenses.begin(); itr != expenses.end() ; itr++) {
        if ((FirstDay<=*itr)&&(*itr<=LastDay)) {
            itr->ShowAllData();
            allExpenses+=itr->GetValue();
        }
    }
    BalanceForSelectedPeriod = allIncomes - allExpenses;
    cout<<endl<<"Yours expenses for selected period are: "<<allExpenses<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"Total Balance for selected period: "<<BalanceForSelectedPeriod<<endl;

    system("PAUSE");
    return;
}

CashFlow BudgetManager::GetTransactionData (string typeOfTransaction) {

    UserInterface *userInterface;
    userInterface = new UserInterface;
    CashFlow cashFlow;
    string date;
    string value;
    int choice;
    int lastId;
    string category;
    bool ifcorrect = false;
    while (!ifcorrect) {
        cout << "Enter Date of "<<typeOfTransaction<<endl;
        cout <<"Please enter in yyyy-mm-dd format, e.g 2015-04-24"<<endl;
        date = AuxiliaryMethods::LoadLine();
        if (DataChecker::CheckIfEnteredDateIsInCorrectForm(date)) {
            cout <<"Date entered in correct form."<<endl;
            cout<<"Please enter value of "<<typeOfTransaction<<endl;
            cout <<"Please enter in xxxxx.xx format, e.g 2000.55"<<endl;
            value = AuxiliaryMethods::LoadLine();
            if (DataChecker::CheckIfEnteredValueIsInCorrectForm(value)) {
                cout <<"Value entered in correct form."<<endl;
                cout<<"Select category of "<<typeOfTransaction<<endl;
                if (typeOfTransaction == "Incomes") {
                    choice = userInterface->CategoryIncomesMenu();
                    category = TypeOfIncomesCategory(choice);
                    lastIncomeId++;
                    lastId = lastIncomeId;
                } else {
                    choice = userInterface->CategoryExpensesMenu();
                    category = TypeOfExpensesCategory(choice);
                    lastExpenseId++;
                    lastId = lastExpenseId;
                }
                cashFlow = SetDataIntoRecord(date,value,category,lastId);
                ifcorrect = true;
                delete userInterface;
                userInterface = NULL;
                return cashFlow;
            } else {
                cout<<"Value entered in wrong format. Try again."<<endl;
            }
        } else {
            cout<<"Date entered in wrong format. Try again."<<endl;
        }
    }
}

string BudgetManager::TypeOfIncomesCategory(int choice) {

    string category;

    switch (choice) {
    case '1':
        category = "SALARY";
        return category;
    case '2':
        category = "STOCKS/BONDS";
        return category;
    case '3':
        category = "COMPANY REVENUE";
        return category;
    case '4':
        category = "OTHERS";
        return category;
    }

}
string BudgetManager::TypeOfExpensesCategory(int choice) {
    string category;
    switch (choice) {
    case '1':
        category = "RENT";
        return category;
    case '2':
        category = "TAXES";
        return category;
    case '3':
        category = "INSURANCE";
        return category;
    case '4':
        category = "FOOD";
        return category;
    case '5':
        category = "OTHER SHOPPING";
        return category;
    case '6':
        category = "OTHERS";
        return category;
    }
}
CashFlow BudgetManager::GetDateForShowing(string typeOfGettingDate) {
    //TO WYMAGA ZMIANY
    CashFlow cashFlow;
    string date;
    int lastId = -1;
    string value = "0.0";
    string category = "No Category";
    bool ifcorrect = false;
    while (!ifcorrect) {
        cout << "Enter Date of "<<typeOfGettingDate<<endl;
        cout <<"Please enter in yyyy-mm-dd format, e.g 2015-04-24"<<endl;
        date = AuxiliaryMethods::LoadLine();
        if (DataChecker::CheckIfEnteredDateIsInCorrectForm(date)) {
            cout <<"Date entered in correct form."<<endl;
            cashFlow = SetDataIntoRecord(date,value,category,lastId);
            ifcorrect = true;
            return cashFlow;
        } else {
            cout<<"Date entered in wrong format. Try again."<<endl;
        }
    }
}


CashFlow BudgetManager::SetDataIntoRecord(string enteredDate, string enteredValue, string category, int lastId) {
    CashFlow cashFlow;
    string Year;
    string Month;
    string Day;
    string correctedValue;
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

    correctedValue = DataChecker::CorrectFormOfValue(enteredValue);
    float valueFloat = AuxiliaryMethods::StringIntoFloat(correctedValue);
    cashFlow.SetValue(valueFloat);

    cashFlow.SetCategory(category);
    cashFlow.SetIdTransaction(lastId);

    return cashFlow;
}

void BudgetManager::TEST_ShowAllIncomes() {
    for (auto itr = incomes.begin(); itr != incomes.end(); itr++) {
        itr->ShowAllData();
    }

}
void BudgetManager::TEST_ShowAllExpenses() {
    for (auto itr = expenses.begin(); itr != expenses.end(); itr++) {
        itr->ShowAllData();
    }
}
