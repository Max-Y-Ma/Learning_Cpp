#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__

class IllegalBalanceException : public std::exception
{
public:
    IllegalBalanceException() = default;
    ~IllegalBalanceException() = default;
    const char* what() const noexcept override {
        return "Illegal Balance Exception Thrown";
    }
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
