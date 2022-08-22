/*
A Trust account has a name, a balance, and an interest rate
The Trust account deposit works just like a savings account deposit.
However, any deposits of $5000.00 or more will receive a $50.00 bonus deposited to the account.

The Trust account withdrawal should only allow 3 withdrawals per year and each of these must be less than 20% of the account balance.
You don't have to keep track of calendar time for this application, just make sure the 4th withdrawal fails :)
*/

#ifndef _TRUST_H_
#define _TRUST_H_
#include "Savings_Account.h"

class Trust_Account: public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr double def_bonus {50};
    static constexpr int def_withdrawals {3};
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double flat_fee;
    double bonus;
    int num_withdrawals;
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate, double bonus = def_bonus, int num_withdrawls = def_withdrawals);
    bool withdraw(double amount);
    bool deposit(double amount);
};

#endif