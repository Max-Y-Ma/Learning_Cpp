// Section 19
/*
Section 19
Challenge 2
Automated Grader

Write a program that reads a file named 'responses.txt" that contains the answer key for a quiz
as well as student responses for the quiz.

The answer key is the first item in the file.
Student1 name
Student1 responses
Student2 name
Student2 responses
. . .

Here is a sample file.

ABCDE
Frank
ABCDE
Larry
ABCAC
Moe
BBCDE
Curly
BBAAE
Michael
BBCDE

You should read the file and display:
Each student's name and score (#correct out of 5)
At the end, the class average should be displayed
You may assume that the data in the file is properly formatted

Program should output to the console the following:
Student                     Score 
----------------------------
Frank                             5
Larry                              3
Moe                              4
Curly                             2
Michael                         4
---------------------------
Average score            3.6

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Student {
    private:
        string name_;
        string choices_;
        int score_;
    public:
        Student() = default;
        Student(string name, string choices, int score): 
            name_ {name}, choices_ {choices}, score_ {score} {}
        void set_name_(string name) {name_ = name;}
        void set_choices_(string choices) {choices_ = choices;}
        void set_score_(int score) {score_ = score;}
        string get_name_() {return name_;}
        string get_choices_() {return choices_;}
        int get_score_() {return score_;}
};

int calc_score_(string choices, string answers) {
    int score {0};
    for (int i {0}; i < 5; ++i) {
        if (choices.at(i) == answers.at(i))
            score++;
    }
    return score;
}

int main() {
    ifstream in_file;
    in_file.open("responses.txt");

    string answers;
    vector<Student*> students;
    if (!in_file) {
        cout << "Error in Opening File!" << endl;
        return 1;
    }
    
    getline(in_file, answers);

    string temp_name;
    string temp_choices;
    while(!in_file.eof()) {
        getline(in_file, temp_name);
        getline(in_file, temp_choices);

        Student* temp_ptr = new Student(temp_name, temp_choices, calc_score_(temp_choices, answers));

        students.push_back(temp_ptr);
    }

    double total {0};
    for (auto& element: students) {
        cout << (*element).get_name_() << ": " << (*element).get_choices_() << ", " << (*element).get_score_() << endl;
        total += (*element).get_score_();
    }

    cout << "Class Average: " << total/(students.size()) << endl;

    for (auto& ptr: students) {
        delete ptr;
    }

    in_file.close();
    return 0;
}

