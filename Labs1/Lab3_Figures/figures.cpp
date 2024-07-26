//Figures.cpp Xcode
// This Program Is Asking a Figure size and then print a figure of the user supplied size and character
// Lab3_Figures
//Make the single file figures.cpp
//Anthony Cruz
//Sent From Xcode on Macbook
#include <iostream>

using std::cin; using std::cout; using std::endl;
//integers
int size;
char paintChar;

int main(){
    cout << "Input a figure size: " << endl;
    cin >> size;
    cout << "Input a Character: " << endl;
    cout << endl;
    cin >> paintChar;
    for (int i = 0; i < size; i++) { //outer loop
        for (int j = 0; j < size; j++) { //inner loop
            cout << paintChar;
        }
        cout << endl;
    }
    //Second
    cout << endl;
    for (int i = 0; i < size; i++) { //outer loop
        for (int j = 0; j < size; j++) { //inner loop
            
            if (i == 0){
                cout << paintChar;
            }
            else if (j == 0) {
                cout << paintChar;
            }
            else if (j == size - 1 ) {
                cout << paintChar;
            }
            else if (i == size - 1) {
                cout << paintChar;
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < size; i++) { //outer loop
        for (int j = 0; j < size; j++) { //inner loop
            if (i == j) {
                cout << paintChar;
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < size; i++) { //outer loop
        for (int j = 0; j < size; j++) { //inner loop
            //row plus column equals figure size minus one.
            if ((i + j) == size - 1) {
                cout << paintChar;
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < size; i++) { //outer loop
        for (int j = 0; j < size; j++) { //inner loop
            //row plus column equals figure size minus one.
            if ((i + j) == size - 1) {
                cout << paintChar;
            }
            //i = j
            if (i == j) {
                cout << paintChar;
            }
            
            if (i == 0){
                cout << paintChar;
            }
            else if (j == 0) {
                cout << paintChar;
            }
            else if (j == size - 1 ) {
                cout << paintChar;
            }
            else if (i == size - 1) {
                cout << paintChar;
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

