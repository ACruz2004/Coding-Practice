// Anthony Cruz
// Lab6 
// 6/17/24

#include "object_construction.hpp"

// Default Constructor
dog::dog() {
    doggie = 0;
    bark = false;
    std::cout << "Called Default Constructor \n";
}

// Copy Constructor
dog::dog(const dog& secDog) : bark(secDog.bark) {
   
    doggie = new dog(*secDog.doggie);

    std::cout << "Called Copy Constructor \n";
}

// Destructor
dog::~dog() {
    delete doggie;
    std::cout << "Called Destructor \n";
}

// Assignment Operator
dog& dog::operator=(const dog& secDog) {
    bark = secDog.bark;
    delete doggie;
    if (secDog.doggie) {
        doggie = new dog(*secDog.doggie);
    }
    std::cout << "Called Assignment Operator \n";
    return *this;
}