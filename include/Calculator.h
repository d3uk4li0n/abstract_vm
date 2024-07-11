#ifndef CALCULATE_H
#define CALCULATE_H
#include <string>
#include <sstream>
#include "../include/IOperandBase.h"
#include "../include/Stack.h"

struct Calculator{
public:
  template <typename T>
  static std::string sum(const T left, const int left_precision, const IOperand &rhs)
  {
    int precision = std::max(rhs.getPrecision(), left_precision);

    if (rhs.getType() == Double_t)
      return Calculator::toString(left + std::stod(rhs.toString()), precision);

     if (rhs.getType() == Float_t)
      return Calculator::toString(left + std::stof(rhs.toString()), precision);

    else
      return Calculator::toString(left + std::stoi(rhs.toString()), precision);
  }

  template <typename T>
  static std::string subtract(const T left, const int left_precision, const IOperand &rhs)
  {
    int precision = std::max(rhs.getPrecision(), left_precision);

    if (rhs.getType() == Double_t)
      return Calculator::toString(left - std::stod(rhs.toString()), precision);

    if (rhs.getType() == Float_t)
      return Calculator::toString(left - std::stof(rhs.toString()), precision);
    else
      return Calculator::toString(left - std::stoi(rhs.toString()), precision);
  }

  template <typename T>
  static std::string multiply(const T left, const int left_precision, const IOperand &rhs)
  {
      
    int precision = std::max(rhs.getPrecision(), left_precision);

    if (rhs.getType() == Double_t)
      return Calculator::toString(left * std::stod(rhs.toString()), precision);

    if (rhs.getType() == Float_t)
      return Calculator::toString(left * std::stof(rhs.toString()), precision);
      
    else
      return Calculator::toString(left * std::stoi(rhs.toString()), precision);
  }

  template <typename T>
  static std::string divide(const T left, const int left_precision, const IOperand &rhs)
  {
    int precision = std::max(rhs.getPrecision(), left_precision);

    if (rhs.getType() == Double_t)
      return Calculator::toString(left / std::stod(rhs.toString()), precision);

    if (rhs.getType() == Float_t)
      return Calculator::toString(left / std::stof(rhs.toString()), precision);

    else
      return Calculator::toString(left / std::stoi(rhs.toString()), precision);
  }

  template <typename T>
  static std::string mod(T left, const int left_precision, const IOperand &rhs)
  {

    int precision = std::max(rhs.getPrecision(), left_precision);
    
    if (rhs.getType() == Double_t)
      return Calculator::toString(std::fmod(left, std::stod(rhs.toString())), precision);

    if (rhs.getType() == Float_t)
      return Calculator::toString(std::fmod(left, std::stof(rhs.toString())), precision);

    else
      return Calculator::toString(std::fmod(left, std::stoi(rhs.toString())), precision);
  }

  template <typename T>
  static std::string toString(const T value, const int n)
  {
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << value;
    return out.str();
  }
  
  static int getPrecision(const IOperand &oper)
  {
    if (oper.getType() == Int8_t)
      return 0;
    else if (oper.getType() == Int16_t)
      return 0;
    else if (oper.getType() == Int32_t)
      return 0;
    else if (oper.getType() == Float_t)
      return 6; //decimal digits of precision
    else // Double_t
      return 15; // decimal digits of precision
  }
};

class MyAbstractVM{

public:
  void executeInstruction(const std::string &instruction) ;
  void executePop();
  void executePush(const std::string &instruction);
  void executeDump();
  void executeAssert(const std::string &instruction);
  void executeAdd();
  void executeSub();
  void executeMul();
  void executeDiv();
  void executeMod();
  void executePrint();  

private:
  stack::Stack stackOperand;
};

#endif