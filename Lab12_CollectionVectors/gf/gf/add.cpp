// File: multiply.cpp
//
// CS 23001 Project 1 bigint
//
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"


std::ifstream file("data1-2.txt");

int main() {
    std::ifstream in;
    //Test for success of opening the file in your program.
    file.open("data1-2.txt");
    if(!file.is_open()) {
        std::cerr << "File not found: data1-2.txt" << std::endl;
        exit(1);
    }
    
    bigint lhs;
    bigint rhs;
    bigint total;
   

    
//All output must be labeled and neat.
//The command make multiply will build and run this program.
    
//Read in two big numbers (i.e., input bigint) and write both out separated by a blank line.
//Until end of file

    while (!file.eof()) {
        //Read two bigints
        file >> lhs;
        file >> rhs;
        
        //Print them out
        std::cout << lhs << " " << rhs;
        
        //Multiply the two together and write the result.
        lhs * rhs;
        
        std::cout << " = " << total;
    }
       
    std::cout << std::endl;
    file.close();
    return 0;
}
