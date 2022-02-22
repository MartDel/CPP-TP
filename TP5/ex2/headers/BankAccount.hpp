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

        virtual void deposit(const float& amount) = 0;
        virtual bool withdrawal(const float& amount) = 0;
        virtual void print() = 0;
};
