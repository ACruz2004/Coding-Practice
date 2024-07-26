//
//  main.cpp
//  Lab4_Age
//
//  Created by Anthony Cruz on 9/12/23.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using std:: cin; using std:: cout; using std:: endl;


int main() {
    // Declarations
    int guess;
    int year = 1000;
    int newyear = 0;
    int yearcount = 0;
    //Dragon Age Generation
    int dragonAge = (rand() * time(nullptr) % 100 + 1);
    
    //dev
        //cout << "Dragon Age is: " << dragonAge << endl;
    //The prompt
    cout << "The year is " << year << ", an old fat dude stole your girlfriend after a long night of modding his discord server..." << endl;
    //do whiles
    do {
        
        cout << "It is now the year " << year << ":" << endl;
        if (yearcount == 0 ){
            cout << "Yo dawg, I cought ur girl, a brand new kitten for my jar gawk gawk, guess my age.";
        }
        else if (yearcount != 0) {
            cout << "Yo dawg, I cought ur girl, she has been my kitten for " << newyear << " years gawk gawk, guess my age.";
        }
            cin >> guess;
        
        
         if (guess > dragonAge) {
            cout << "I'm too old for that big dawg, see you in 5 years..." << endl;
            cout << "You left like a dumb idiot moron man and came back 5 years after" << endl;
            
            dragonAge += 5;
            year +=5;
            newyear += 5;
            yearcount++;
        }
        else if (guess < dragonAge) {
            cout << "I'm older than that gawd dayum, see you in 5 years dummy..." << endl;
            cout << "You left like a dumb idiot moron man and came back 5 years after" << endl;
            dragonAge += 5;
            year +=5;
            newyear += 5;
            yearcount++;
        }
        
    }
    while (guess != dragonAge);
    
    do {
        cout << "Fine, have your girl back, she got uggy anyways" << endl;
        guess = 0;
    }
    while (guess == dragonAge);
    
}
//For header include #ifndef cpp name
//````      #define cpp.name
//            #endif
// use voids
