//Anthony Cruz
//This is a mini sort project
//Code from Xcode on Mac

#include <iostream>

using std:: cout; using std::cin; using std::endl;
//Function
void getNumber(int&, int&, int &);
void swap(int&, int&);
void showre(int, int, int);
int  main() {
int firstnum, secnum, thirdnum;
    //Gets the three numebers
    cout << "Enter three numbers: " << endl;
    getNumber(firstnum,secnum ,thirdnum);
    if (firstnum > secnum) {
        swap(firstnum, secnum);
        //showre(firstnum, secnum);
    }
    else if (firstnum > thirdnum) {
        swap(firstnum, thirdnum);
        //showre(firstnum, thirdnum);
    }
    else if (secnum > thirdnum) {
        swap(secnum, thirdnum);
        //showre(firstnum, thirdnum);
    }
    showre(firstnum, secnum, thirdnum);
}
//Function Defenitions
void getNumber(int& num1, int& num2, int& num3) {
    cout << "First: ";
    cin >> num1;
    cout << endl << "Second: ";
    cin >> num2;
    cout << endl << "Third: ";
    cin >> num3;
}
void swap(int& left, int& right) {
    const int tmp = left;
    left = right;
    right = tmp;
}
void showre(int out1, int out2, int out3) {
    cout << "Your Numbers are: " << out1 << " " << out2 << " "<<  out3 << endl;
}

    
   
