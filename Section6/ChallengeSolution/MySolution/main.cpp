
// Section 6
// Challenge

/* 
    Frank's Carpet Cleaning Service
    Charges:
        $25 per small room
        $35 per large room
    Sales tax rate is 6%
    Estimates are valid for 30 days

    Prompt the user for the number of small and large rooms they would like cleaned
    and provide an estimate such as:
     
Estimate for carpet cleaning service
Number of small rooms: 3
Number of large rooms: 1
Price per small room: $25
Price per large room: $35
Cost : $110
Tax: $6.6
===============================
Total estimate: $116.6
This estimate is valid for 30 days
*/

#include <iostream>
using namespace std;

int main() {
    cout << "Estimate for carpet cleaning service";
    
    cout << "\nNumber of small rooms: ";
    int number_of_small_rooms {0};
    cin >> number_of_small_rooms;

    cout << "Number of large rooms: ";
    int number_of_large_rooms {0};
    cin >> number_of_large_rooms;

    const double kPriceSmallRoom {25};
    cout << "Price per small room: $" << kPriceSmallRoom << endl;

    const double kPriceLargeRoom {35};
    cout << "Price per large room: $" << kPriceLargeRoom << endl;

    cout << "Cost: $" << (number_of_small_rooms * kPriceSmallRoom) 
    + (number_of_large_rooms * kPriceLargeRoom) << endl;

    const double kTaxRate {0.06};
    cout << "Tax: $" << (((number_of_small_rooms * kPriceSmallRoom) 
    + (number_of_large_rooms * kPriceLargeRoom)) * kTaxRate) << endl;

    cout << "==================================" << endl;

    cout << "Total Estimate: $" << (number_of_small_rooms * kPriceSmallRoom) 
    + (number_of_large_rooms * kPriceLargeRoom) + (((number_of_small_rooms * kPriceSmallRoom) 
    + (number_of_large_rooms * kPriceLargeRoom)) * kTaxRate) << endl;

    const int kServiceDays {30};
    cout << "This estimate is valid for " << kServiceDays << " days" << endl;

    return 0;
}

