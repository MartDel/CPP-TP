#include "SavingsAccount.hpp"

void CheckingAccount::print() {
    cout << "Number : " << number << endl;
    cout << "Owner : " << owner << endl;
    cout << "Balance : " << balance << "€" << endl;
    cout << "Overdraft limit : " << overdraftLimit << "€" << endl;
}

bool CheckingAccount::withdrawal(const float& amount) {
    if (amount <= overdraftLimit) {
        balance -= amount;
        return true;
    } else return false;
}

bool CheckingAccount::transfer(const float& amount, BankAccount& other_account) {
    if (withdrawal(amount)) {
        other_account.deposit(amount);
        return true;
    } else return false;
}

void SavingsAccount::print() {
    cout << "Number : " << number << endl;
    cout << "Owner : " << owner << endl;
    cout << "Balance : " << balance << "€" << endl;
    cout << "Annual interest rate : " << annualInterestRate << "%" << endl;
}

void SavingsAccount::depositAnnualInterest() {
    deposit(balance * annualInterestRate);
}
