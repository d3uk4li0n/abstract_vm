#include "../include/IOperandBase.h"
#include "../include/Operands.h"
#include "../include/Calculator.h"
#include "../include/Stack.h"
​
using namespace stack;
​
void Stack::push(const IOperand *operand){
  a_stack.push(operand);
}
​
bool Stack::empty(){
    return a_stack.empty();
}
​
Stack::~Stack(){
  while(!a_stack.empty()) {
    const IOperand* val = pop();
    delete val;
  }
}
​
const IOperand* Stack::pop(){
​
  const IOperand* val = a_stack.top();
  a_stack.pop();
  
  return val;
}
​
const IOperand* Stack::top(){
  return a_stack.top();
}
​
std::string Stack::toString() const{
  std::ostringstream out;
  std::stack<const IOperand*> stackCopy(a_stack);
​
  while(!stackCopy.empty()) {
      out << stackCopy.top()->toString() << std::endl;
      stackCopy.pop();
  }
  return out.str();
}