//  Created by Anthony Cruz on 7/11/2024
//  POSTFIXEVAL
//  Project 2 Part 2

#include <iostream>
#include <fstream>
#include <string>
#include "stack.hpp" // Linking this program to stack from Part 1

std::string infix2postfix(const std::string& infix) {
    stack<std::string> s;
    std::string postfix;
    std::string token;
    int i = 0;
    
    while (i < infix.size()) {
        while (i < infix.size() && infix[i] == ' ') {
            i++;
        }
        
 
        token.clear(); // Use clear
        while (i < infix.size() && infix[i] != ' ') {
            token += infix[i];
            i++;
        }

        if (token == ")") {
            std::string rhs = s.pop(); // Pop rhs

            std::string oper = s.pop(); // Pop operator

            std::string lhs = s.pop(); // Pop the lhs

            s.push(lhs + " " + rhs + " " + oper);

        } else if (token != "(" && !token.empty()) {
            s.push(token);
        }
    }
    
    while (!s.isEmpty()) {
        postfix = s.pop() + " " + postfix;
    }

  
    if (!postfix.empty() && postfix[postfix.size() - 1] == ' ') {
        postfix[postfix.size() - 1] = 0;
    }

    return postfix;
}

int evaluatePostfix(const std::string& postfix) {
    stack<int> s;
    std::string token;
    size_t i = 0;
    
    while (i < postfix.size()) {
        // If there is a space, increase i by one
        while (i < postfix.size() && postfix[i] == ' ') {
            ++i;
        }
        
        
        token.clear(); // std::string
        while (i < postfix.size() && postfix[i] != ' ') {
            token += postfix[i];
            ++i;
        }

        if (!token.empty()) { // Empty instead of isEmpty for std::string
            //s.push(token - int('0')); This has issues
            return 0; // Error here prints zero as result
            
        } else {
            int rhs = s.pop();
            int lhs = s.pop();
            if (token == "+") { // Token for + (add)
                s.push(rhs + lhs);
            } else if (token == "-") { // Token for - (sub)
                s.push(rhs - lhs);
            } else if (token == "*") { // Token for * (mul)
                s.push(rhs * lhs);
            } else if (token == "/") { // Token for / (div)
                s.push(rhs / lhs);
            }
        }
    }
    
    return s.pop();
}

int main() {

    std::ifstream infile("data.txt"); // set infile to data.txt
    std::string line;
    while (std::getline(infile, line)) {  // Used getline to read the file
        if (line.empty()) continue;  // Found solution to error, use continue
        if (line[line.size() - 1] == ';') { 
            line.erase(line.size() - 1);
        }
        std::string postfix = infix2postfix(line);

        int result = evaluatePostfix(postfix);

        std::cout << line << std::endl; // Print the infix
        std::cout << postfix << std::endl; // Print the postfix
        std::cout << "Result: " << result << std::endl; // Print the result

        std::cout << std::endl;
    }

    return 0; // Return 0
}