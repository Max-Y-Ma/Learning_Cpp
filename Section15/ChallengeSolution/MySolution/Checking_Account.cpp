#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance, double fee) 
    : Account{name, balance}, flat_fee{fee} {
}

bool Checking_Account::withdraw(double amount) {
    return Account::withdraw(amount + flat_fee);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Account: " << account.name << ": " << account.balance << ", " << account.flat_fee << "]";
    return os;
}