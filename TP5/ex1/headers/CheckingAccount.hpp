#include "BankAccount.hpp"

class CheckingAccount : public BankAccount {
    private:
        float overdraftLimit;

    public:
        CheckingAccount(const int& n, const string& o, const float& b, const float& l)
        : BankAccount(n, o, b), overdraftLimit(l) {}
        float getOverdraftLimit() const { return overdraftLimit; }

        bool withdrawal(const float&);
        bool transfer(const float& amount, BankAccount& other_account);
};
