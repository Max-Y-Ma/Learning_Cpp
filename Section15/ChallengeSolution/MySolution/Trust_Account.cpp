#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate, double bonus, 
    int num_withdrawls) : Savings_Account{name, balance, int_rate}, bonus{bonus}, num_withdrawals{num_withdrawls} {

}

bool Trust_Account::withdraw(double amount) {
    if (num_withdrawals < 0 || (amount > (balance * 0.20))) 
        return false;
    num_withdrawals--;
    return Account::withdraw(amount);
}

bool Trust_Account::deposit(double amount) {
    if (amount >= 5000)
        amount += bonus;
    return Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Savings_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << 
        ", " << account.bonus << ", " << account.num_withdrawals << "]";
    return os;
}