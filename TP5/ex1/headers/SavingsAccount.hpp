#include "CheckingAccount.hpp"

class SavingsAccount : public BankAccount {
    private:
        float annualInterestRate;

    public:
        SavingsAccount(const int& n, const string& o, const float& b, const float& i)
        : BankAccount(n, o, b), annualInterestRate(i) {}
        float getAnnualInterestRate() const { return annualInterestRate; }

        void depositAnnualInterest();
};
