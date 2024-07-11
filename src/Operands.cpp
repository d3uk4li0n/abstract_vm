#include "../include/IOperandBase.h"
#include "../include/Operands.h"
#include "../include/Calculator.h"
#include "../include/Stack.h"

Operands::functype Operands::functptr[5] = {_createInt8, _createInt16, _createInt32, _createFloat, _createDouble};

Operands::Operands (std::string value, int precision, eOperandType type){
    m_value = value;
    m_precision = precision;
    m_type = type;
  }
    
eOperandType Operands::createOperandType(const std::string& typeValue){
    if (typeValue == "int8"){
        return Int8_t;
    }else if (typeValue == "int16"){
        return Int16_t;
    }else if (typeValue == "int32"){
        return Int32_t;
    }else if (typeValue == "float"){
        return Float_t;
    }else// Double_t
    {
        return Double_t;
    }
}

IOperand* Operands::createOperand(eOperandType type, const std::string& value){

    return (*functptr[static_cast<int>(type)])(value);
}

IOperand* Operands::_createInt8(const std::string& value){
    return new Int8(value);
}

IOperand* Operands::_createInt16(const std::string& value){
    return new Int16(value);
}

IOperand* Operands::_createInt32(const std::string& value){
    return new Int32(value);
}

IOperand* Operands::_createFloat(const std::string& value){
    return new Float(value);
}

IOperand* Operands::_createDouble(const std::string& value){
    return new Double(value);
}