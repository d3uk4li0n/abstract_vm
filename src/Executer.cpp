#include "../include/IOperandBase.h"
#include "../include/Operands.h"
#include "../include/Calculator.h"
#include "../include/Stack.h"
#include "../include/Exceptions.h"

void MyAbstractVM::executeInstruction(const std::string &instruction) {
    if (instruction.find(";") == 0)
    {
        //comment, ignore
    }else if (instruction.find("push") != std::string::npos) {
        executePush(instruction);
    }else if (instruction.find("assert") != std::string::npos) {
        executeAssert(instruction);
    } else if (instruction == "pop") {
        executePop();
    } else if (instruction == "dump") {
        executeDump();
    } else if (instruction == "print") {
        executePrint();
    } else if (instruction == "mod") {
        executeMod();
    } else if (instruction == "add") {
        executeAdd();
    } else if (instruction == "sub") {
        executeSub();
    } else if (instruction == "mul") {
        executeMul();
    } else if (instruction == "div") {
        executeDiv();
    }
}

void MyAbstractVM::executePop(){
    try {
        if (stackOperand.empty()) {
            throw MyAbstractVMException("Error: Pop on empty stack");
        }

        const IOperand* topOperand = stackOperand.pop();
        delete topOperand;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        throw e;
    }
}

void MyAbstractVM::executePush(const std::string &instruction){
    std::istringstream ss(instruction);
    std::string cmd;  
    std::string token;
    std::string type; 
    std::string value;

    ss >> cmd >> token;
       
    std::istringstream tokenSS(token);
    std::getline(tokenSS, type, '(');
    std::getline(tokenSS, value, ')');

    const IOperand* operand = Operands::createOperand(Operands::createOperandType(type), value);    
    stackOperand.push(operand);
}

void MyAbstractVM::executeDump(){
    std::cout << stackOperand.toString();
}

void MyAbstractVM::executeAssert(const std::string &instruction){
    std::istringstream ss(instruction);
    std::string cmd;  
    std::string token;
    std::string type; 
    std::string value;

    ss >> cmd >> token;
       
    std::istringstream tokenSS(token);
    std::getline(tokenSS, type, '(');
    std::getline(tokenSS, value, ')');

    const IOperand* operand = Operands::createOperand(Operands::createOperandType(type), value);    

    try {
        if (stackOperand.empty()) {
            throw MyAbstractVMException("Error: Top on empty stack");
        }

        const IOperand* topOperand = stackOperand.top();

        //std::cout << "topOperand->getType(): " << topOperand->getType() << std::endl;
        //std::cout << "topOperand->toString(): " << topOperand->toString() << std::endl;

        if (operand->getType() != topOperand->getType() ||
            operand->toString() != topOperand->toString())
        {
            throw MyAbstractVMException("Error: Assert failed");
        }

    } catch (const std::exception& e) {
        delete operand;
        std::cerr << "Exception caught: " << e.what() << std::endl;
        throw e;
    }    
}

void MyAbstractVM::executeAdd(){
    try {
        if (stackOperand.empty()) {
            throw MyAbstractVMException("Error: Pop on empty stack");
        }

        const IOperand* v1 = stackOperand.pop();

        if (stackOperand.empty()) {
            delete v1;
            throw MyAbstractVMException("Error: Pop on empty stack");
        }

        const IOperand* v2 = stackOperand.pop();

        const IOperand *result = (*v2) + (*v1);
        stackOperand.push(result);

        delete v1;
        delete v2;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        throw e;
    }    
}

void MyAbstractVM::executeSub(){
    try {
        if (stackOperand.empty()) {
            throw MyAbstractVMException("Error: Pop on empty stack");
        }

        const IOperand* v1 = stackOperand.pop();

        if (stackOperand.empty()) {
            delete v1;
            throw MyAbstractVMException("Error: Pop on empty stack");
        }

        const IOperand* v2 = stackOperand.pop();

        const IOperand *result = (*v2) - (*v1);
        stackOperand.push(result);

        delete v1;
        delete v2;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        throw e;
    }    
}

void MyAbstractVM::executeMul(){
    try {
        if (stackOperand.empty()) {
            throw MyAbstractVMException("Error: Pop on empty stack");
        }

        const IOperand* v1 = stackOperand.pop();

        if (stackOperand.empty()) {
            delete v1;
            throw MyAbstractVMException("Error: Pop on empty stack");
        }

        const IOperand* v2 = stackOperand.pop();

        const IOperand *result = (*v2) * (*v1);
        stackOperand.push(result);

        delete v1;
        delete v2;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        throw e;
    }    
}

void MyAbstractVM::executeDiv(){
    try {
        if (stackOperand.empty()) {
            throw MyAbstractVMException("Error: Pop on empty stack");
        }

        const IOperand* v1 = stackOperand.pop();

        if (stackOperand.empty()) {
            delete v1;
            throw MyAbstractVMException("Error: Pop on empty stack");
        }

        const IOperand* v2 = stackOperand.pop();

        if (v2->toString() == "0")
        {
            delete v1;
            delete v2;
            throw MyAbstractVMException("Error: Divisor is equal to 0");
        }        

        const IOperand *result = (*v2) / (*v1);
        stackOperand.push(result);

        delete v1;
        delete v2;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        throw e;
    }    
}

void MyAbstractVM::executeMod(){
    try {
        if (stackOperand.empty()) {
            throw MyAbstractVMException("Error: Pop on empty stack");
        }

        const IOperand* v1 = stackOperand.pop();

        if (stackOperand.empty()) {
            delete v1;
            throw MyAbstractVMException("Error: Pop on empty stack");
        }

        const IOperand* v2 = stackOperand.pop();

        if (v2->toString() == "0")
        {
            delete v1;
            delete v2;
            throw MyAbstractVMException("Error: Divisor is equal to 0");
        }

        const IOperand *result = (*v2) % (*v1);
        stackOperand.push(result);

        delete v1;
        delete v2;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        throw e;
    }    
}

void MyAbstractVM::executePrint(){
    try {
        if (stackOperand.empty()) {
            throw MyAbstractVMException("Error: Pop on empty stack");
        }

        const IOperand* v1 = stackOperand.top();

        if (v1->getType() != Int8_t) {
            delete v1;
            throw MyAbstractVMException("Error: Not ASCII character");
        }
        std::cout << static_cast<char>(atoi(v1->toString().c_str())) << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        throw e;
    }    
}
