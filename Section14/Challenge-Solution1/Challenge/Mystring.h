#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring(Mystring &&source);                         // Move constructor
    ~Mystring();                                                     // Destructor
    
    Mystring& operator=(const Mystring& rhs);     // Copy assignment
    Mystring& operator=(Mystring&& rhs);           // Move assignment
    Mystring operator-();
    bool operator==(const Mystring& rhs);
    bool operator!=(const Mystring& rhs);
    bool operator<(const Mystring& rhs);
    bool operator>(const Mystring& rhs);
    Mystring operator+(const Mystring& rhs);
    void operator+=(const Mystring& rhs);
    Mystring operator*(int factor);
    void operator*=(int factor);
    Mystring& operator++();
    Mystring operator++(int);

    void display() const;
    
    int get_length() const;                                      // getters
    const char *get_str() const;
    void set_str(const Mystring& obj);
};

#endif // _MYSTRING_H_