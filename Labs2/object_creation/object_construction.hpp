// Anthony Cruz
// Lab6 
// 6/17/24

#ifndef OBJECT_CONSTRUCTION_HPP
#define OBJECT_CONSTRUCTION_HPP

#include <iostream>

class dog {
public:
    dog();                      // Default Constructor
    dog(const dog&);            // Copy Constructor
    ~dog();                     // Destructor
    dog& operator=(const dog&); // Assignment Operator

private:
    dog* doggie;  
    bool bark;
};

#endif