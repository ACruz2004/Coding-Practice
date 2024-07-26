//  Created by Anthony Cruz on 7/10/2024
//  INFIX2POSTFIZ
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
    
    while (i < infix.length()) {
        while (i < infix.length() && infix[i] == ' ') {
            i++;
        }
        
        // Extract the token
        token.clear();
        while (i < infix.length() && infix[i] != ' ') {
            token += infix[i];
            i++;
        }

        if (token == ")") {
            std::string right = s.pop();
            std::string oper = s.pop();
            std::string left = s.pop();
            s.push(left + " " + right + " " + oper);
        } else if (token != "(" && !token.empty()) {
            s.push(token);
        }
    }
    
    while (!s.isEmpty()) {
        postfix = s.pop() + " " + postfix;
    }


    return postfix;
}

int main() {
    std::ifstream infile("data.txt");
    if (!infile.is_open()) {
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) {
        if (line.empty()) continue;
        
        if (line.back() == ';') {
            line.pop_back();
        }
        std::string postfix = infix2postfix(line);
        std::cout << line << std::endl;
        std::cout << postfix << std::endl;
        std::cout << std::endl;
    }

    return 0;
}