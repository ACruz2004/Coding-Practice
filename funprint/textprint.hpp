//HPP File For funprint 
//Was gonna do a class but it's obsolite fr fr
#ifndef TEXT_HPP
#define TEXT_HPP

#include<iostream>
#include<curses.h> 
#include<cstring>
#include<unistd.h>

//Text Function Declarations
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::string text; //The String to be manipulated
void greetings(); //Simple Welcome
void shapeSelection(); //The text that asks for the selection of the shape
void speedSelection(); //The text that asks for the selection of the speed
int speed = 50000;
std::string shapeInput;
int speedInput;



//Code For The Functions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void greetings() {
    speed = 50000;
    //Greeting
    text = "Welcome To The Program...";
    //Ints for length
    int length = 0;
    int j = 0;
    //Setting the length
    while (text[j] != 0) {
        ++length; ++j;
    }
    for (int i = 0; i < length; ++i) {
        std::cout << text[i];
        usleep(speed);
        fflush( stdout );
    }
    std::cout << std::endl;
}

void shapeSelection() {
    speed = 50000;
    //Selection
    text = "Make A Shape Selection( [ ] Square  or   @Amogus ): ";
    //Ints for length
    int length = 0;
    int j = 0;
    //Setting the length
    while (text[j] != 0) {
        ++length; ++j;
    }
    for (int i = 0; i < length; ++i) {
        std::cout << text[i];
        usleep(speed);
        fflush( stdout );
    }
    std::cout << std::endl;
    std::cin >> shapeInput;
}

void speedSelection() {
    speed = 50000;
    //Selection
    text = "What speed (1000000 = 1 second)";
    //Ints for length
    int length = 0;
    int j = 0;
    //Setting the length
    while (text[j] != 0) {
        ++length; ++j;
    }
    for (int i = 0; i < length; ++i) {
        std::cout << text[i];
        usleep(speed);
        fflush( stdout );
    }
    std::cout << std::endl;
    std::cin >> speedInput;
}



#endif
