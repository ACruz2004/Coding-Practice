//  Postfix.cpp
//
//  This will be the file that reads the infix and postfix expressions
//

#include "utilities.hpp"

int main() {
    // Gets the name of the input file
    std::string inName;
    std::cout << "Select an input file: ";
    std::cin >> inName;
    
    std::ifstream inFile(inName);
    if (!inFile) {
        std::cout << "Error, file could not be found or is misspelled" << std::endl;
        return -1;
    }
    
    // Gets the name of the output file
    std::string outName;
    std::cout << std::endl << "Select an output file (if none is selected then it will print to screen): ";
    std::cin >> outName;
    
    std::ofstream outFile(outName); // Output file
    
    bool boolfile = false;
    if (!outFile) {
        std::cout << "Error, file could not be found or is misspelled" << std::endl;
        std::cout << "Infix to postfix expression: " << infixToPostfix(outFile, inFile, boolfile);
        return -1;
    } else {
        boolfile = true;
        infixToPostfix(outFile, inFile, boolfile);
    }
  
    return 0;
}
