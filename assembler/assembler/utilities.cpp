//
//  utilities.cpp
//  assembler
//
//  Created by Anthony Cruz on 4/3/24.
//

//UTILITES.CPP

#include "utilities.hpp"


String infixToPostfix(std::ostream& outputFile, std::istream& in, bool boolfile) {
//Read the file
    String token;
    stack<String> stack;
    

    while (in >> token && token != ";") {
        while(token != ";" && token != "") {
        if (token == ")") {
            String right = stack.top();
            stack.pop();
            String oper = stack.top();
            stack.pop();
            String left = stack.top();
            stack.pop();
            stack.push(left + right + oper);
        }
        else if (token != "(") {
            stack.push(token);
        }
        in >> token;
    }

  
    String postfixExpression = stack.top();

    // If boolfile is true, write postfix expression to outputFile
    if (boolfile) {
        outputFile << postfixExpression << std::endl;
    } else {
        std::cout << "Postfix expression: " << postfixExpression << std::endl;
    }
    // Clear the stack for the next expression
        while (!stack.empty()) {
            stack.pop();
        }
     }
    
    return "";
}

    


