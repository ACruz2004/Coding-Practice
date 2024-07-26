//Bigint.cpp   /////////////////////////////////////////////
//Anthony Cruz ///////////////////////////////////////////// 
//5/23/2024    /////////////////////////////////////////////
//CS23001      /////////////////////////////////////////////

//Include Guards
#ifndef BIGINT_HPP
#define BIGINT_HPP

#include<iostream>
//Assertions used for testing
#include<cassert>

//Global Constant For Capacity
const int CAPACITY = 720;

//Defines a bigint class
//..
class bigint {
//Public
public:
    //Default Ctor
    bigint();
    //Bigint->int Ctor
    bigint(int);
    //Bigint->char[] Ctor
    bigint(const char[]);

    //Debug Print
    void debugPrint(std::ostream& out) const;
    
    //Overload Operators:
    //Operator<<
    friend std::ostream& operator<<(std::ostream&, const bigint& right);
    //Operator==
    bool operator==(const bigint&) const;
    //Operator[]
    bigint operator[] (int) const;
    //Operator+
    bigint operator+ (const bigint&) const;
    //* Operator
    bigint  operator*   (const bigint&) const;
    //timeDigit(int)
    bigint timesDigit(int) const;
    //times10(int)
    bigint times10(int) const;


private:
    //Number Array
    int numbArr[CAPACITY];
};

//Overload Operator For Milestone 2
    std::istream& operator>>(std::istream&, bigint&);
#endif