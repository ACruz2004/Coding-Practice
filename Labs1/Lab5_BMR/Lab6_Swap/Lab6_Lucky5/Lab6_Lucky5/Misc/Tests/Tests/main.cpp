//
//  main.cpp
//  Tests
//
//  Created by Anthony Cruz on 10/10/23.
//
#include <iostream>
using namespace std;
void numadd(int &num, int);
int totnum;
bool playagain = false;
char playchar;
bool fift = false;
int main() {
    //ognum
    int ognum = 10;
    int secnum = 0;
    //add
    do {
        numadd(secnum, ognum);
        
        cout << "Your answer is " << (ognum + secnum) << endl;
        
        if ((ognum + secnum) != 15) {
            fift = true;
        }
        
        fift ? cout << "That sucks, your number wasn't the best number ever 15...you should kys fr fr" << endl : cout << "15?!? I FUCKING LOVE 15!?! AHAHAHSDFAHSFU" << endl ;
        
        cout << "Play again? (Y/N): " << endl;
        
        cin >> playchar;
        
        if (playchar == 'n' || playchar == 'N') {
            cout << "Goodbye" << endl;
            playagain = true;
        }
        else if (playchar == 'y' || playchar == 'Y') {
            playagain = false;
        }
    }
    while (playagain == false);
        
}
    
void numadd(int& num, int og) {
    cout << "The original number is: " << og << endl;
    cout << "Please enter a number to add to " << og;
    cin >> num;
}
