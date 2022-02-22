#include "SavingsAccount.hpp"

void BankAccount::print() const {
    cout << "Number : " << number << endl;
    cout << "Owner : " << owner << endl;
    cout << "Balance : " << balance << "€" << endl;
}

bool CheckingAccount::withdrawal(const float& amount) {
    if (amount <= overdraftLimit) {
        BankAccount::withdrawal(amount);
        return true;
    } else return false;
}

bool CheckingAccount::transfer(const float& amount, BankAccount& other_account) {
    if (withdrawal(amount)) {
        other_account.deposit(amount);
        return true;
    } else return false;
}

void SavingsAccount::depositAnnualInterest() {
    deposit(balance * annualInterestRate);
}
