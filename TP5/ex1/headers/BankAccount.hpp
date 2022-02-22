#include <iostream>

using namespace std;

class BankAccount {
    protected:
        int number;
        string owner;
        float balance;

    public:
        BankAccount(const int& n, const string& o, const float& b)
        : number(n), owner(o), balance(b) {}
        int getNumber() const { return number; }
        string getOwner() const { return owner; }
        float getBalance() const { return balance; }

        void deposit(const float& amount) { balance += amount; }
        void withdrawal(const float& amount) { balance -= amount; }
        void print() const;
};
