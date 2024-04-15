// testing the implementation of class Collection
// Anthony Cruz
// 11/14/23

#include <iostream>
#include "collection.hpp"

using std::cout; using std::endl;


void testfunc(Collection); // function to test pass-by-value for collection

int main(){

   Collection c1;
    
   // testing regular member functions
   c1.addNumber(1.);
   c1.addNumber(2.);
   c1.addNumber(3.);
   c1.addNumber(3.); // trying to add duplicate, should not add it

   cout << "c1 size is after number addition is: " << c1.size() << endl;

   if(c1.check(1.) != -1) // check() returns -1 if number not present
      cout << "1 is present in the array" << endl;

   if(c1.check(5.) != -1)
      cout << "5 is present in the array" << endl;

   cout << "c1 before removal of 2.0: "; c1.output();
   c1.removeNumber(2.);
   cout << "c1 after removal of 2.0: "; c1.output();


   testfunc(c1); // testing copy constructor

   cout << "c1 after testfunc call: ";
   c1.output(); // if destructor is implemented correctly
                // this should print properly after testfunc completes

   Collection c2, c3;

   c3=c2=c1; // testing stackability of the overloaded assignment
   cout << "c3 after stackable assingment: ";
   c3.output();

   c3=c3; // testing protection against self-assingment
   cout << "c3 after self-assignment: ";
   c3.output();

}

// tests pass-by-value for object of class Collection
void testfunc(Collection c){ // copy constructor is invoked on "c"
    cout << "parameter c: ";
    c.output();
} // destructor is invoked when "c" goes out of scope


