// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    /* PsuedoCode
     * Push all elements of the string into the deque's back
     * Pop from the back and check with string 
     * This will compare them in reverse order 
    */
    
    std::deque<char> p;

    // Push all characters to back of the deque
    for (const char& e: s) {
        if (std::isalpha(e))
            p.push_back(std::toupper(e));
    }

    // Pop each character from back and compare with front of string
    for (const char& e: s) {
        if (!std::isalpha(e))
            continue;
        
        if (p.back() == std::toupper(e))
            p.pop_back();
        else
            break;
    }

    // If deque is empty, we know that it was a palindrome
    return (p.empty());
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}