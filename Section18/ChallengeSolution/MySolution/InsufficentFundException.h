#ifndef __INSUFFICENT_FUND_EXCEPTION_H__
#define __INSUFFICENT_FUND_EXCEPTION_H__

class InsufficentFundException : public std::exception {
public:
    InsufficentFundException() = default;
    ~InsufficentFundException() = default;
    const char* what() const noexcept override {
        return "Insufficent Funds Exception";
    }
};

#endif