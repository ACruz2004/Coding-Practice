// functions to manipulate Charlie's collection
// Anthony Cruz
// 11/07/2023

#ifndef COLLECTION_HPP
#define COLLECTION_HPP

// prints the values in array "colPtr" of "size"
void output(const double *colPtr, const int size);

// returns the sum of all the values in array "colPtr" of "size"
double value(const double *colPtr, const int size);

// returns the index of the element in array "colPtr" of "size"
// that corresponds to the element holding "number"
// if number is not in the array, returns -1
int check(const double *colPtr, const double number, const int size);

// adds "number" to the array pointed to by "colPtr" of "size".
// if the number is not already there, if "number" is there - no action
// Note, the size of the array is thus increased.
void addNumber(double *& colPtr, const double number, int &size);

// removes a "number" from array "colPtr" of "size".
// if "number" is not there -- no action
// note, "size" changes
void removeNumber(double *& colPtr, const double number, int &size);

#endif // COLLECTION_HPP
