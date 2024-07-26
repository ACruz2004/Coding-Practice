//  collection.cpp
//  Lab11.CollectionTest
//  Created by Anthony Cruz on 11/22/23.


#include <iostream>
#include "test.hpp"

using namespace std;

//Part One Functions
//>>
//>>

//Void Constructor
 Collection::Collection(){
     size_ = size();
        col_ = new double[size_];
}

//Output function
//..
//The Print Function
void Collection::output() const{
    for (int i = 0; i < size_; ++i) {
        cout << col_[i] << " ";
    }
    cout << endl;
}


//Check Function
//..
// returns index of element containg "number" or -1 if none
int Collection::check(double number) {
    double checknum = -1.0;
    
    for (int i = 0; i < size_; ++i) {
        
        if (number == col_[i]) {
            checknum = i;
        }
    }
    
    return checknum;
}

//Addnumber Function
//..
// adds number to the collection
void Collection::addNumber(double number) {
    //Check
    if(check(number) == -1){
        double *newcol_ = new double[size() + 1];
        
        for (int i = 0; i < size_; ++i) {
            newcol_[i] = col_[i];
        }
        newcol_[size_] = number;
        
        col_ = new double[size_ + 1];
        
        for (int i = 0; i < size_; ++i) {
            col_[i] = newcol_[i]  ;
        }
        
        col_[size_] = number;
        
        size_ = size_ + 1;
        
        //colPtr[size] = number;
        
        delete [] newcol_;
        }
    else{
        cout << "Number is already in collectionz";
    }
    }

//RemoveNumber Function
//..
// deletes the number from the collection
void Collection::removeNumber(double number) {
    
    if(check(number) != -1){
        double *newcol_ = new double[size_ - 1];
        
        //Finding a match
        int j = 0;
        for (int i = 0; i < size_; i++) {
            if (col_[i] != number) {
                newcol_[j] = col_[i];
                j++;
            }
        }
        
        col_ = new double[size_ - 1];
        
        for (int i = 0; i < size_; ++i) {
            col_[i] = newcol_[i]  ;
        }
        
        size_ = size_ - 1;
        
        
        delete [] newcol_;
    }
    else{
        cout << "Number is not in collection!" << endl;
    }
}

//>>
//>>

//Part Two Functions
//>>
//>>

//Copy Constructor
//..
//..
Collection::Collection(const Collection& collect){
    size_ = collect.size_;
    col_ = new double[size_];
    for(int i = 0; i < size_; ++i) col_[i] = collect.col_[i];
}
//Destructor
//..
//..
Collection::~Collection(){
    delete [] col_;
}
//Overload Assignment
//..
//..
const Collection& Collection::operator= (const Collection& ovr){
    if (this != &ovr){
        size_ = ovr.size_;
        delete [] col_;
        col_ = new double[size_];
        for (int i=0; i < size_; i++)
            col_[i] = ovr.col_[i];
       }
       return *this;
}

//>>
//>>

//Value Function
//..
//..

void Collection::value() {
    double addednum = 0;
    //Loop
    for (int i=0; i < size_; i++)
        if (col_[i] != 0) {
            addednum = addednum + col_[i];
        }
    cout << addednum;
}

