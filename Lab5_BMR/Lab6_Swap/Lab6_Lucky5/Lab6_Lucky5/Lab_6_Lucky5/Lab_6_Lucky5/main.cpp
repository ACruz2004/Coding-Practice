//  This Program Will have 5 random numbers outputted, the user will input 5 and will have a response depending on if the five selected match.
//  Lab6_Lucky_5
//  Created by Anthony Cruz on 9/30/23.

//Include Statements
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::endl; using std:: cin; using std::cout;
//Function Prototypes

int main() {
//Function Prototypes
const int arraysize = 10;
int chosen[arraysize];
void assign (int[], int);
void draw(int[], int);
bool check (int[],int, int, int[]);
//User Numbers
void entry(int[], int);
const int input = 5;
int userinput[input];
void printout(int[]);
//Assign
assign(chosen, 10);
//Draw
draw(chosen, 10);
//Enter
entry(userinput, 5);
//Check The userinput
check(userinput, 10, input, chosen);
    if (check(userinput, 10, input, chosen) == true) {
        cout << "Congratulations! You are a Lucky duck!" << endl;
    }
    else {
        cout << "Sorry you lost *womp womp*" << endl;
    }
    printout(chosen);
}

//Definitions

//Assign
void assign(int cho[], int asize) {
    for(int i = 0; i < asize; ++i) {
        cho[i] = -1;
    }

}
//Check
bool check (int cho[],int arrSize, int numb, int arrprev[]) {
    //another bool to use as return value
    bool checkres = false;
    if (numb != 5){
        for (int i=1; i < arrSize; ++i)
            if (numb == cho[i]) {
                //return
                checkres = true;
            }
    }
    for (int i=1; i < arrSize; ++i)
        if (arrprev[i] == cho[i]) {
            //return
            checkres = true;
        }
    return checkres;
}
//Draw
void draw(int cho[], int asize) {
    int numb;
    int errprov[0];
    //random number generator
    srand(time(nullptr) % 100);
    
    //errorprovention
    errprov[0] = 1;
    
    for(int i = 0; i < asize; ++i)
    while (i < asize) {
        numb = rand() % 100;
        //If error check check
        check(cho, asize, numb, errprov);
        if (check(cho, asize, numb, errprov) == false) {
            cho[i] = numb;
            i++;
        }

    }
    
    
}
void entry(int userinput[],int input) {
    //userinput is the array while input is the integer for the size (5)
    cout << "Welcome to the lottery! Enter your lucky 5: " << endl;
    for (int u = 0; u < input; u++) {
        cin >> userinput[u];
    }
}
void printout(int arrvar[]) {
    cout << "The lotto numbers were: " << arrvar[0] << " " << arrvar [1] << " " << arrvar [2] << " " << arrvar[3] << " " << arrvar[4] << " " << arrvar[5] << " " << arrvar[6] << " " << arrvar[7] << " " << arrvar[8] << " " << arrvar[9];
}
