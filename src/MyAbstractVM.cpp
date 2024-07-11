#include <iostream>
#include <fstream>
#include <string>
#include "../include/IOperandBase.h"
#include "../include/Operands.h"
#include "../include/Calculator.h"
#include "../include/Stack.h"
#include "../include/Exceptions.h"

int main(int argc, char** argv){
    MyAbstractVM myVM;
    std::string line;   

    //std::cout << argc << std::endl;

    if (argc == 2) //use file
    {
        //std::cout << argv[1] << std::endl;
        std::ifstream in (argv[1]);
        if (!in.good()){
            std::cout << "Could not open input file" << std::endl;
        }
        try {
            bool hasExit = false;

            while (std::getline(in, line)){

                //std::cout << "line: |" << line << "|" << std::endl;
                
                if (line == "exit" || line == ";;")
                {
                    hasExit = true;
                    break;
                }
                
                myVM.executeInstruction(line);
            }
        
            if (!hasExit)
            {
                throw MyAbstractVMException("Error: Don't have an instruction exit");
            }
            
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        in.close();
    }else{
        try {

            bool hasExit = false;

            while (std::getline(std::cin, line)){

                if (line == "exit" || line == ";;"){
                    hasExit = true;
                    break;
                }
                
                myVM.executeInstruction(line);
            }

            if (!hasExit)
            {
                throw MyAbstractVMException("Error: Don't have an instruction exit");
            }
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    } 

    return 0;
}
