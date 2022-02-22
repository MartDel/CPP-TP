#include "SavingsAccount.hpp"

int main(void) {
    CheckingAccount checking_account(0, "Maxime", 100, 20);
    SavingsAccount savings_account(1, "Tom", 10, 0.5);

    cout << "Trying to transfer 25€ from Maxime's account to Tom's account : ";
    cout << (checking_account.transfer(25, savings_account) ? "succeed" : "failed") << endl;

    cout << "Trying to transfer 15€ from Maxime's account to Tom's account : ";
    cout << (checking_account.transfer(15, savings_account) ? "succeed" : "failed") << endl << endl;

    checking_account.print();
    cout << endl;
    savings_account.print();

    cout << endl << "Depositing Tom's annual interest..." << endl << endl;
    savings_account.depositAnnualInterest();
    savings_account.print();

    return 0;
}
