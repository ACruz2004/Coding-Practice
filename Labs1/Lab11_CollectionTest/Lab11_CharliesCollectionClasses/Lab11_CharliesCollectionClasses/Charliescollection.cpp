//  Charliescollection.cpp
//  Lab11_CharliesCollection
//  Created by Anthony Cruz on 11/22/23.
//

#include <iostream>
#include "test.hpp"

using namespace std;

int main() {
    
    Collection c1;
    
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
            c1.addNumber(number);
        }
        else if (input == 'r' || input == 'R') {
            c1.removeNumber(number);
        }
        else if (input == 'q' || input == 'Q') {
            break;
        }
        else {
            cout << "Please enter a valid input" << endl;
        }
        //Outputting the Collection
        cout << "Your Current Sequence is: ";
        
        c1.output();
        
        cout << "The total of these numbers is: ";
        
        c1.value();
        
        cout << endl;
    }
    cout << "Goodbye Charlie!" << endl;
}

