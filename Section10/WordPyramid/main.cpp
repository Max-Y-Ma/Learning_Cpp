/*
* If the user enters 'ABCDEFG', then your program should display:

      A                                                                                                                
     ABA                                                                                                               
    ABCBA                                                                                                              
   ABCDCBA                                                                                                             
  ABCDEDCBA                                                                                                            
 ABCDEFEDCBA                                                                                                           
ABCDEFGFEDCBA
*
* 1.) Store String
* 2.) Calculte Space: w.size() - current row # (starting at 1)
* 3.) Displaying Characters: Create 2 appropriate substrings and display both
*/


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    cout << "Enter Word: ";
    string w;
    getline(cin, w);

    for (long unsigned i {1}; i <= w.size(); ++i) {
        string substr_1 {w, 0, i};  // Larger SubString
        string substr_2 {w, 0, i - 1};  // Smaller SubString
        reverse(substr_2.begin(), substr_2.end()); // Reverse Smaller SubString

        // Display Spaces
        for (int j{0}; j < (w.size() - i); ++j) {
            cout << ' ';
        }

        cout << substr_1 << substr_2;

        // Display Spaces
        for (int j{0}; j < (w.size() - i); ++j) {
            cout << ' ';
        }

        cout << '\n';
    }

    return 0;
}