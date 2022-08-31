// Section 19
/*
Section 19
Challenge 4
Copy Romeo and Juliet with line numbers

This challenge should be pretty easy.
I have provided the text to Romeo and Juliet in a file named romeoandjuliet.txt

For this challenge you have to make copy of the Romeo and Juliet file and save it to another file.
This new copy should have line numbers at the beginning of each line in the play.
Please format the numbers nicely so everything lines up.

Feel free to extend this challenge in any way you like.
For example, you may want to provide line numbers only for lines that actually have text

Have fun!
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ifstream in_file;
    ofstream out_file;
    in_file.open("./romeoandjuliet");
    out_file.open("./romeoandjulietlines", ios::app);

    if (!in_file || !out_file) {
        cerr << "Trouble Opening Files!" << endl;
        return 1;
    }

    out_file.clear();
    unsigned long int num_line {1};
    while (!in_file.eof()) {
        string line;
        getline(in_file, line);

        if (line.compare("\r") == 0) {
            out_file << endl;
            continue;
        }

        out_file << num_line << ": " << line << endl;
        num_line++;
    }

    in_file.close();
    out_file.close();

    return 0;
}

