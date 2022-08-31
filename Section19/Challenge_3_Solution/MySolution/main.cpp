// Section 19
/*
Section 19
Challenge 3
Word finder

Ask the user to enter a word
Process the Romeo and Juliet file and determine how many total words there are
and how many times the word the user entered appears as a substring of a word in the play.

For example.
If the user enters: love
Then the words love, lovely, and beloved will all be considered matches.
You decide whether you want to be case sensitive or not. My solution is case sensitive

Sample are some sample runs:

Enter the substring to search for: love
25919 words were searched...
The substring love was found 171 times

Enter the substring to search for: Romeo
25919 words were searched...
The substring Romeo was found 132 times

Enter the substring to search for: Juliet
25919 words were searched...
The substring Juliet was found 49 times

Enter the substring to search for: Frank
25919 words were searched...
The substring Frank was found 0 times

Have fun!
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ifstream in_file {"./romeoandjuliet.txt"};

    if (!in_file) {
        cerr << "Error Opening File" << endl;
        return 1;
    }

    string search_word;
    cout << "Enter the substring to search for: ";
    getline(cin, search_word);
    
    int num_word {0};
    int num_word_hit {0};
    while (!in_file.eof()) {
        string word_in_file {};
        char temp {};
        
        while(in_file.get(temp)) {
            if (temp == '[' || temp == ']' || temp == '(' || temp == ')' || temp == *("'") || temp == '|') {
                continue;
            }
            else if (temp == ' ' || temp == '\t' || temp == '\r' || temp == '\n') {
                break;
            }
            else
                word_in_file.push_back(temp);
        }

        if (word_in_file.compare("") != 0)
            num_word++;

        int length = static_cast<int>(word_in_file.length() - search_word.length());
        if (length < 0)
            continue;

        for (int i{0}; i <= length; i++) {
            if (word_in_file.compare(i, search_word.length(), search_word) == 0) {
                num_word_hit++;
                break;
            }
        }
    }

    cout << num_word << " words were searched..." << endl;
    cout << "The substring " << search_word << " was found " << num_word_hit << " times!" << endl;

    in_file.close();

    return 0;
}

