#ifndef MY_ABS_EX_H
#define MY_ABS_EX_H

#include "IOperandBase.h"

class MyAbstractVMException : public std::exception {
private:
    std::string eMessage;

public:
    MyAbstractVMException(const std::string& message) : eMessage(message) {}

    const char* what() const noexcept override {
        return eMessage.c_str();
    }
};

#endif