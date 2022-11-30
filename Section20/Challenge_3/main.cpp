// Section 20
// Challenge 3  
// Maps and Sets

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>

// Used for Part1
// Display the word and count from the 
// std::map<std::string, int>

void display_words(const std::map<std::string, int> &words) {
    std::cout << std::setw(12) << std::left << "\nWord"
                << std::setw(7) << std::right << "Count"<< std::endl;
    std::cout << "===================" << std::endl;
    for (auto pair: words)
        std::cout << std::setw(12) << std::left << pair.first 
                       << std::setw(7) << std::right << pair.second << std::endl;
}

// Used for Part2
// Display the word and occurences from the 
// std::map<std::string, std::set<int>>

void display_words(const std::map<std::string, std::set<int>> &words)
{
     std::cout << std::setw(12) << std::left << "\nWord"
                << "Occurrences"<< std::endl;
    std::cout << "=====================================================================" << std::endl;
    for (auto pair: words) {
        std::cout << std::setw(12) << std::left << pair.first 
                       << std::left << "[ ";
        for (auto i: pair.second) 
            std::cout << i << " ";
        std::cout << "]" << std::endl;
    }
}

// This function removes periods, commas, semicolons and colon in 
// a string and returns the clean version
std::string clean_string(const std::string &s) {
    std::string result;
    for (char c: s) {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else
            result += c;
    }
    return result;
}

// Part1 process the file and builds a map of words and the 
// number of times they occur in the file

void part1() {
    std::map<std::string, int> words;
    std::string line;   
    std::stringstream ss;    
    std::string word;   
    std::ifstream in_file {"./words.txt"};
    if (in_file) {
        // Read the file line by line
        while (std::getline(in_file, line)) {
            // Process each line
            ss.str(line);
            while (ss >> word) {
                word = clean_string(word);
                // If the word is in the map, increment its counter
                if(words.count(word))
                    words.at(word)++;
                else {
                    words.insert({word, 1});
                }
            }
            ss.clear();
        }

        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}
    
// Part2 process the file and builds a map of words and a 
// set of line numbers in which the word appears
void part2() {
    std::map<std::string, std::set<int>> words;
    std::stringstream ss;
    std::string line;
    std::string word;
    std::ifstream in_file {"./words.txt"};
    int linenum = 1;
    if (in_file) {
        // Read the file line by line
        while (std::getline(in_file, line)) {
            // Process each line
            ss.str(line);
            while (ss >> word) {
                word = clean_string(word);
                // If the word is in the map, update its line numbers
                if(words.count(word))
                    (words.at(word)).insert(linenum);
                else {
                    words.insert({word, {linenum}});
                }
            }
            ss.clear();
            linenum++;
        }
        
        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}

int main() {
    part1();
    part2();
    return 0;
}

