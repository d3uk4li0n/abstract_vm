# abstract_vm
A machine capable of solving basic arithmetic operations, expressed in the form of assembly programs 

# Installation 
Run “make”  
“make fclean” to clean up afterwards

# Usage
and then you can test it with the provided test files  
./my\_abstract\_vm test\_files/every\_operation  
./my\_abstract\_vm test\_files/simple\_test  
./my\_abstract\_vm test\_files/simple\_add  

Or straight from the command line:  
./my\_abstract\_vm  
push int8(30)  
push int16(300)  
add  
dump  
300
