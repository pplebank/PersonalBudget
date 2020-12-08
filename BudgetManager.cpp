#include "BudgetManager.h"

vector <CashFlow> BudgetManager::SortVectorByDates (vector <CashFlow> unsortedVector) {
    sort(unsortedVector.begin(),unsortedVector.end(),[](CashFlow&a,CashFlow&b)->bool {return a<b;});
    return unsortedVector;
}

void BudgetManager::LoadAllDataOfLoggedUser () {
    incomes = fileWithIncomesAndExpenses.LoadLoggedUserData("Incomes");
    expenses = fileWithIncomesAndExpenses.LoadLoggedUserData("Expenses");
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

void BudgetManager::ShowBalanceForThisMonth()
{
CashFlow firstDay = DateGetter::GetDateOfFirstDayOfMonth();
CashFlow lastDay = DateGetter::GetTodaysDate();
ShowBalance(firstDay,lastDay);
}


void BudgetManager::ShowBalanceForLastMonth()
{
CashFlow firstDay = DateGetter::GetFirstDayOfLastMonth();
CashFlow lastDay = DateGetter::GetLastDayOfLastMonth();
ShowBalance(firstDay,lastDay);


}

void BudgetManager::ShowBalanceForSelectedPeriod()
{
CashFlow firstDay = DateGetter::GetDateOfFirstDayOfMonth();
CashFlow lastDay = DateGetter::GetTodaysDate();
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

void ShowBalance ();

CashFlow BudgetManager::GetTransactionData (string typeOfTransaction) {

    CashFlow cashFlow;
    string date;
    string value;
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
                cashFlow = SetDataIntoRecord(date,value);
                ifcorrect = true;
                return cashFlow;
            } else {
                cout<<"Value entered in wrong format. Try again."<<endl;
            }
        } else {
            cout<<"Date entered in wrong format. Try again."<<endl;
        }
    }
}

CashFlow BudgetManager::SetDataIntoRecord(string enteredDate, string enteredValue) {
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
