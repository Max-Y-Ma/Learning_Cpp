/*
Section 18
Challenge
For this challenge we want to integrate our own user-defined exception classes into the Account class
hierarchy.

The account classes are provided for you.
Also, the IllegalBalanceException.h file contains the declaration for the IllegalBalanceException class.

What I would like you to do is:
1. Derive IllegalBalanceException from std::exception and implement the what() method to provide an exception message.
   This exception object should be thrown from the Account class constructor if an account object is created with a negative 
   balance.
   
2. Derive InsufficentFundsException from std::exception and implement the what() method to provide an exception message.
   This exception object should be thrown if a withdraw results in a negative balance.
   You should throw this exception object from the Account withdraw method.
   
That's it - good luck!
Test your code in the main driver.

Have fun and experiment!
*/

#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"
#include "InsufficentFundException.h"

using namespace std;

int main() {
    try {
        Savings_Account j {"Jason", 100, 5};
        j.withdraw(2000);
    }
    catch(IllegalBalanceException &e) {
        std::cerr << e.what() << std::endl;
    }
    catch(InsufficentFundException &e) {
        std::cerr << e.what() << std::endl;
    }
    catch(...) {
        std::cerr << "Unknown Error" << std::endl;
    }

    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

