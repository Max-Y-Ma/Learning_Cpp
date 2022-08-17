#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
        //std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring(Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
        //std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
    //std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs) {
   //std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// getters & setters
int Mystring::get_length() const { return strlen(str); }
const char *Mystring::get_str() const { return str; }
void Mystring::set_str(const Mystring& obj) { 
    delete [] this->str;
    strcpy(this->str, obj.str);
}

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

// overloaded unary minus operator
Mystring Mystring::operator-() {
    char* new_string = new char[this->get_length() + 1];
    for (int i {0}; i < this->get_length() + 1; ++i)
        new_string[i] = tolower(this->str[i]);
    
    return Mystring{new_string};
}

// overloaded Is Equal To operator
bool Mystring::operator==(const Mystring& rhs) {
    return !(strcmp(this->str, rhs.str));
}

// overloaded Not Equal To operator
bool Mystring::operator!=(const Mystring& rhs) {
    return (strcmp(this->str, rhs.str));
}

// overloaded Less Than operator
bool Mystring::operator<(const Mystring& rhs) {
    return ((strcmp(this->str, rhs.str)) < 0) ? true : false;
}

// overloaded Greater Than operator
bool Mystring::operator>(const Mystring& rhs) {
    return ((strcmp(this->str, rhs.str)) > 0) ? true : false;
}

// overloaded Addition operator
Mystring Mystring::operator+(const Mystring& rhs) {
    char* new_string = new char[this->get_length() + rhs.get_length() + 1];
    strcpy(new_string, this->str);
    strcat(new_string, rhs.str);
    Mystring n{new_string};
    delete [] new_string;
    return n;
}

// overloaded Addition Equal operator
void Mystring::operator+=(const Mystring& rhs) {
    *this = this->operator+(rhs);
}

// overloaded Multiplication operator
Mystring Mystring::operator*(int factor) {
    char* new_string = new char[this->get_length() * factor + 1];
    
    strcpy(new_string, this->str);
    for (int i {1}; i < factor; ++i)
       strcat(new_string, this->str);

    Mystring n{new_string};
    delete [] new_string;
    return n;
}

// overloaded Multiplication Equal operator
void Mystring::operator*=(int factor) {
    *this = this->operator*(factor);
}

// overloaded Pre-Increment operator
Mystring& Mystring::operator++() {
    char* new_string = new char[this->get_length() + 1];
    for (int i {0}; i < this->get_length(); ++i)
        new_string[i] = toupper(this->str[i]);
    
    *this = Mystring{new_string};

    delete [] new_string;

    return *this;
}

// overloaded Post-Increment operator
Mystring Mystring::operator++(int) {
    Mystring copy {*this};
    operator++();                    
    return copy; 
}
