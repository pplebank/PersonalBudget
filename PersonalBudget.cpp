#include "PersonalBudget.h"

void PersonalBudget::LoadAllUsers () {
    userManager.LoadUsersFromFile();
}
void PersonalBudget::RegisterUser() {
    userManager.UserRegistration();
}

void PersonalBudget::ListAllUsers() {
    userManager.ListAllUsers();
}

void PersonalBudget::LogIn () {
    userManager.LoginUser();
    if (userManager.IfUserIsLogged()) {
        budgetManager = new BudgetManager(NAME_OF_FILE_WITH_INCOMES, NAME_OF_FILE_WITH_EXPENSES,userManager.GetLoggedUserId());
    }
}

void PersonalBudget::sortContainersWithData() {
    budgetManager->sortUnsortedContainerWithTransfers();
}

void PersonalBudget::ChangePasswordOfLoggedUser() {
    userManager.ChangePasswordOfLoggedUser();
}

void PersonalBudget::AddIncome() {
    budgetManager->AddIncome();
}
void PersonalBudget::AddExpense() {
    budgetManager->AddExpense();
}

void PersonalBudget::TEST_ShowAllIncomes() {
    budgetManager-> TEST_ShowAllIncomes();
}
void PersonalBudget::TEST_ShowAllExpenses() {
    budgetManager-> TEST_ShowAllExpenses();
}

void PersonalBudget::ShowBalanceForThisMonth()
{
    budgetManager->ShowBalanceForThisMonth();
}

void PersonalBudget::ShowBalanceForLastMonth()
{
    budgetManager->ShowBalanceForLastMonth();
}

void PersonalBudget::ShowBalanceForSelectedPeriod()
{
    budgetManager->ShowBalanceForSelectedPeriod();
}

bool PersonalBudget::IfUserIsLogged()
{
    return userManager.IfUserIsLogged();
}

void PersonalBudget::LogOut()
{
    userManager.LogOutUser();
    delete budgetManager;
    budgetManager = NULL;
}
