//
//  Charliescollection.cpp
//  Lab10_CharliesCollection
//
//  Created by Anthony Cruz on 11/13/23.
//

#include <iostream>
#include "test.hpp"

using namespace std;

int main() {
    
    int size = 0;
    double *a = new double[size];
    
    //Beginning (asking for input)
    char input = 'i';
    double number;
    
    //While loop for quit function
    while (input != 'q' || input != 'Q') {
        cout << "Charlie, enter operation [a/r/q] and number: ";
        //Get input
        cin >> input;
        //Get Number
        cin >> number;
        
        //Add function
        if (input == 'a' || input == 'A') {
            addNumber(a, number, size);
        }
        else if (input == 'r' || input == 'R') {
            removeNumber(a, number, size);
        }
        else if (input == 'q' || input == 'Q') {
            break;
        }
        else {
            cout << "Please enter a valid input" << endl;
        }
        //Outputting the Collection
        cout << "Your Current Sequence is: ";
        
        output(a, size);
        
        cout << endl;
    }
    cout << "Goodbye Charlie!" << endl;
}
