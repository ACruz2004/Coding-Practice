
//  Created by Anthony Cruz on 4/3/24.
//



#include "utilities.hpp"
#include "../string/string.hpp"
#include "../string/string.cpp"
#include "stack.hpp"

String infixToPrefix(std::ofstream("data3-1.txt")) {
//Read the file
    String token;
    stack<String> stack;
    

    while (in >> token && token != ";") {
        if (token == ")") {
            String right =stack.pop();
            String oper = stack.pop();
            String left = stack.pop();
            stack.push(left + right + oper);
        } 
        else if (token != "(") {
            stack.push(token);
        }
        return stack.pop();
    }

}
   