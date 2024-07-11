#ifndef IO_OPERAND_H
#define IO_OPERAND_H

#include "../include/IOperandBase.h"
#include "../include/Calculator.h"

class Operands : public IOperand {
 private:
  struct Private;
  std::string      m_value;
  int              m_precision;
  eOperandType     m_type;

 public:

  Operands (std::string value, int precision, eOperandType type);

  virtual ~Operands (){

  }

  [[nodiscard]]  eOperandType       getType () const override{
    return m_type;
  }
  [[nodiscard]]  int                getPrecision () const override{
    return m_precision;
  }
  [[nodiscard]]  const std::string &toString () const override{    
    return m_value;
  }

  static eOperandType createOperandType(const std::string& typeValue);
  static IOperand* createOperand(eOperandType type, const std::string& value);

private:
  
  static IOperand* _createInt8(const std::string& value);
  static IOperand* _createInt16(const std::string& value);
  static IOperand* _createInt32(const std::string& value);
  static IOperand* _createFloat(const std::string& value);
  static IOperand* _createDouble(const std::string& value);

  typedef IOperand* (*functype)(const std::string&);
  static functype functptr[5];

};


class Int8 : public Operands {

 public:
  Int8 (std::string value): 
    Operands(value, 0, Int8_t){
  }

  virtual ~Int8(){

  }

  IOperand *operator+ (const IOperand &rhs) const override{
    std::string val = cal.sum(std::stoi(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator- (const IOperand &rhs) const override{
    std::string val = cal.subtract(std::stoi(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator* (const IOperand &rhs) const override{
    std::string val = cal.multiply(std::stoi(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator/ (const IOperand &rhs) const override{
    std::string val = cal.divide(std::stoi(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator% (const IOperand &rhs) const override{
    std::string val = cal.mod(std::stoi(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
private:
  Calculator cal;
};

class Int16 : public Operands {

 public:
  Int16 (std::string value): 
    Operands(value, 1, Int16_t){
  }

  virtual ~Int16(){

  }

  IOperand *operator+ (const IOperand &rhs) const override{
    std::string val = cal.sum(std::stoi(toString()) , getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator- (const IOperand &rhs) const override{
    std::string val = cal.subtract(std::stoi(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator* (const IOperand &rhs) const override{
    std::string val = cal.multiply(std::stoi(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator/ (const IOperand &rhs) const override{
    std::string val = cal.divide(std::stoi(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator% (const IOperand &rhs) const override{
    std::string val = cal.mod(std::stoi(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
private:
  Calculator cal;
};

class Int32 : public Operands {

 public:
  Int32 (std::string value): 
    Operands(value, 2, Int32_t){
  }

  virtual ~Int32(){

  }

  IOperand *operator+ (const IOperand &rhs) const override{
    std::string val = cal.sum(std::stoi(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator- (const IOperand &rhs) const override{
    std::string val = cal.subtract(std::stoi(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator* (const IOperand &rhs) const override{
    std::string val = cal.multiply(std::stoi(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator/ (const IOperand &rhs) const override{
    std::string val = cal.divide(std::stoi(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator% (const IOperand &rhs) const override{
    std::string val = cal.mod(std::stoi(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
private:
  Calculator cal;
};

class Float : public Operands {

 public:
  Float (std::string value): 
    Operands(value, 3, Float_t){
  }

  virtual ~Float(){

  }

  IOperand *operator+ (const IOperand &rhs) const override{
    std::string val = cal.sum(std::stof(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator- (const IOperand &rhs) const override{
    std::string val = cal.subtract(std::stof(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator* (const IOperand &rhs) const override{
    std::string val = cal.multiply(std::stof(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator/ (const IOperand &rhs) const override{
    std::string val = cal.divide(std::stof(toString()), getPrecision (), rhs);
   int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator% (const IOperand &rhs) const override{
    std::string val = cal.mod(std::stof(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
private:
  Calculator cal;
};

class Double : public Operands {

 public:
  Double (std::string value): 
    Operands(value, 4, Double_t){
  }

  virtual ~Double(){

  }

  IOperand *operator+ (const IOperand &rhs) const override{
    std::string val = cal.sum(std::stod(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator- (const IOperand &rhs) const override{
    std::string val = cal.subtract(std::stod(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator* (const IOperand &rhs) const override{
    std::string val = cal.multiply(std::stod(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator/ (const IOperand &rhs) const override{
    std::string val = cal.divide(std::stod(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
  IOperand *operator% (const IOperand &rhs) const override{
    std::string val = cal.mod(std::stod(toString()), getPrecision (), rhs);
    int precision = std::max(rhs.getPrecision(), getPrecision());
    return Operands::createOperand(static_cast<eOperandType>(precision), val);
  }
private:
  Calculator cal;
};

#endif
