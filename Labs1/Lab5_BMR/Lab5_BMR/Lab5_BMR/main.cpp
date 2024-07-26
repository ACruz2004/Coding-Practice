
//This is the BMR function for Lab 5
//Anthony Cruz

#include <iostream>

using std::endl; using std::cin; using std::cout;
//Function Prototypes
double bmrMen(double height, int age, double weight);
double bmrWomen(double height, int age, double weight);
double weight; int age; double height;
//Constant1 const cookies = 142
const int cookies = 142;

int main() {
char gender;

cout << "What is your gender? (m/f)" << endl;
cin >> gender;
//Weight
cout << "What Is Your Weight?: ";
cin >> weight;
//Height
int feet; int inches;
cout << "What is your Height? " << endl;
//Height in feet and inches
cout << "Feet: "; cin >> feet; cout << "Inches: "; cin >> inches;
//Convert height to inches
height = inches + (feet * 12);
//age
cout << "How old are you?: ";
cin >> age;

if (gender == 'm') {
cout << "You are Male!" << endl;
double bmrm;
    bmrm = bmrMen(height,age,weight);
    cout << "Your BMR is: " << bmrm;
    cout << "The amount of cookies you can eat per day is: " << (bmrm / cookies);
        
}
else if (gender == 'f') {
cout << "You are Female!" << endl;
    double bmrw;
        bmrw = bmrWomen(height,age,weight);
cout << "Your BMR is: " << bmrw;
cout << "The amount of cookies you can eat per day is: " << (bmrw / cookies);
}

}
//Function Defenitions
double bmrMen(double height, int age, double weight) {

double bmr;
bmr = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
    return bmr;
}
double bmrWomen(double height, int age, double weight) {

double bmr;
bmr = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
    return bmr;
}
