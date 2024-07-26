//  collection.cpp
//  Lab10_TestCollection
//  Xcode on Mac
//  Created by Anthony Cruz on 11/7/23.

#include "test.hpp"
#include <iostream>

using namespace std;


//First Part Functions
//>>
//>>
//>>
//>>



//Output function
//..
//Basically the Print function
void output(const double *colPtr, const int size) {
    
    for (int i = 0; i < size; ++i) {
        cout << colPtr[i] << " ";
    }
    cout << endl;
}

//Value Function
//..
// returns the sum of all the values in array "colPtr" of "size"
double value(const double *colPtr, const int size) {
    
    //double and sum declarations
    double sum = 0.0;
    
    for (int i = 0; i < size; ++i) {
        sum = sum + colPtr[i];
    }
    
    return sum;
}


//Second part functions
//>>
//>>
//>>
//>>

//Check Function
// returns the index of the element in array "colPtr" of "size"
// that corresponds to the element holding "number"
// if number is not in the array, returns -1
int check(const double *colPtr, const double number, const int size) {
    double checknum = -1.0;
    
    for (int i = 0; i < size; ++i) {
        
        if (number == colPtr[i]) {
            checknum = i;
        }
    }
    
    return checknum;
}

//Third Part Functions
//>>
//>>
//>>
//>>

//Add number function
// adds "number" to the array pointed to by "colPtr" of "size".
// if the number is not already there, if "number" is there - no action
// Note, the size of the array is thus increased.
void addNumber(double *&colPtr, const double number, int &size) {
   // int increase = 0;
   // int newsize = size + increase;
    if(check(colPtr, number, size) == -1){
        double *newPtr = new double[size + 1];
        
        for (int i = 0; i < size; ++i) {
            newPtr[i] = colPtr[i];
        }
        newPtr[size] = number;
        
        colPtr = new double[size + 1];
        
        for (int i = 0; i < size; ++i) {
            colPtr[i] = newPtr[i]  ;
        }
        
        colPtr[size] = number;
        
        size = size + 1;
        
        //colPtr[size] = number;
        
        delete [] newPtr;
        }
    }


//Remove Number Function
// removes a "number" from array "colPtr" of "size".
// if "number" is not there -- no action
// note, "size" changes
void removeNumber(double *&colPtr, const double number, int &size) {
    
    if(check(colPtr, number, size) != -1){
        double *newPtr = new double[size - 1];
        
        //Finding a match
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (colPtr[i] != number) {
                newPtr[j] = colPtr[i];
                j++;
            }
        }
        
        colPtr = new double[size - 1];
        
        for (int i = 0; i < size; ++i) {
            colPtr[i] = newPtr[i]  ;
        }
        
        size = size - 1;
        
        
        delete [] newPtr;
    }
}


