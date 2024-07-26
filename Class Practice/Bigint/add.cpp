// File: main.cpp
//
// CS 23001 Project 1 bigint 
//
// Basics for openning a file for milestone 2
//

#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream file;            // Define input stream
    file.open("data1-1.txt");      // Open a file
    if(!file) {                    // Make sure file opened correctly
        std::cerr << "File not found: data1-1.txt" << std::endl;
        exit(1);
    }
    
    //Until end of file
       //Read two bigints
       //Print them out
       //Add them together
       //Print out results
 
    
    char ch;
    bigint num1;
    bigint num2;
  
    while (file >> num1) {
        file >> num2;
        
        //Linecount and outputting the added ints      
        bigint sum = num1 + num2;
        std::cout << "The sum of " << num1 << " and " << num2 << " is: " << sum << '\n';
        file >> ch;
    }
        
    file.close();
    return 0;
}

