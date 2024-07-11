#ifndef STACK_H
#define STACK_H
#include "../include/IOperandBase.h"
​
#include <stack>
​
namespace stack
{
    class Stack
    {
      private:
        std::stack<const IOperand*> a_stack;
    
      public:
        Stack() = default;
        ~Stack();
        void               push(const IOperand* operand);
        const IOperand*    pop();
        const IOperand*    top();
        bool               empty();
        std::string        toString() const;
    };
​
}
​
#endif