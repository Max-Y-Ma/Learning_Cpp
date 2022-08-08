// Section 8 Challenge
/*
	For this program I will be using US dollars and cents.
	
    Write a program that asks the user to enter the following:
	An integer representing the number of cents 
    	
	You may assume that the number of cents entered is greater than or equal to zero
    
	The program should then display how to provide that change to the user.
	
	In the US:
		1 dollar is 100 cents
		1 quarter is 25 cents
		1 dime is 10 cents
		1 nickel is 5 cents, and
		1 penny is 1 cent.
		
	Here is a sample run:
	
	Enter an amount in cents :  92
	
	You can provide this change as follows:
	dollars    : 0
	quarters : 3
	dimes     : 1
	nickels   : 1
	pennies  : 2
	
	Feel free to use your own currency system.
	Also, think of how you might solve the problem using the modulo operator.

	Have fun and test your program!!

*/

#include <iostream>
using namespace std;

/* PsuedoCode:
 * 1.) Recieve cents amount
 * 2.) Calculate using modulo
 * 3.) Start with dollars and work towards pennies
*/

int main() {
	int amount_in_cents {0};
	cout << "Enter an amount in cents : ";
	cin >> amount_in_cents;

	int dollar {0}, quarter {0}, dime {0}, nickel {0}, penny {0};
	int current_amount_in_cents {0};
	const int dollar_in_cents {100};
	const int quarter_in_cents {25};
	const int dime_in_cents {10};
	const int nickel_in_cents {5};
	const int penny_in_cents {1};

	dollar = amount_in_cents / dollar_in_cents;
	current_amount_in_cents = amount_in_cents % dollar_in_cents;

	quarter = current_amount_in_cents / quarter_in_cents;
	current_amount_in_cents %= quarter_in_cents;

	dime = current_amount_in_cents / dime_in_cents;
	current_amount_in_cents %= dime_in_cents;

	nickel = current_amount_in_cents / nickel_in_cents;
	current_amount_in_cents %= nickel_in_cents;

	penny = current_amount_in_cents;

	cout << "\nYou can provide this change as follows:" << endl;
	cout << "Dollars: " << dollar << endl;
	cout << "Quarters: " << quarter << endl;
	cout << "Dime: " << dime << endl;
	cout << "Nickel: " << nickel << endl;
	cout << "Penny: " << penny << endl;

    return 0;
}


