// tests Charlie's double numbers collection implementation
// Anthony Cruz
// 11/07/2023

#include "test.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;


int main(){

   int size=5;  // setting collection array size
   double *a = new double[size]; // allocating dynamic array

   // collection initializing array
   a[0] = 0.; a[1] = 10.; a[2] = 20.; a[3] = 30.; a[4] = 40.;

   cout << "Collection: ";
   output(a, size); // printing out the array

   cout << "Collection value: " << value(a, size) << endl;


   // asking user to input a number
   cout << "Input number to find in Charlie's collection: ";
   double number;
   cin >> number;

   // checking if the input number is in the collection
   int index = check(a, number, size);
   if (index == -1)
      cout << "The number is not Charlie's collection" << endl;
   else
      cout << "The number is at position " << index << endl;



   // adding a new number to the collection
   addNumber(a, 55.5, size);
   cout << "Charlie's collection after adding a new number: "; output(a, size);

   // adding a duplicate numbe r to collection
   // the function should not add it
   addNumber(a, 20., size);
   cout << "Charlie's collection after adding existing number: "; output(a, size);

   
   removeNumber(a, 10., size);
   cout << "Charlie's collection after removing a number: "; output(a, size);


   delete [] a; // deallocating the array

}

