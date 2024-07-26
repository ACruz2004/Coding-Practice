// Lab7_Line Justify
//Anthony Cruz
//This Program will ask the user to input a string, then check if the code is 80 charachters long, then it will make the output 80 charachters by putting spaces after first, punctuation marks, then random words;
//Tuesday Oct 17th

//Code start
//Include statements
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

//using statements
using std :: string; using std :: cin; using std :: cout; using std :: endl;

//Prototypes
const int maximumlength = 80;
const int minimumlength = 40;

string punct("!:.?");
string space(" ");

void puncspread(string& , int, int);
void randspread(string&, int, int);

//Main function
int main() {
  // Declaring the string in main function, it will then be called by reference later on
    string input;
    
    //The user will now input their line and it will be stored as a string
    cout << "Please input your text: ";
    
    //The getline will take the user inout and put it into the string input
    getline(cin, input);
    
    // use cout << input; to test if input is stored *Y*
    
    //Calling the punctuation function that takes in string, const in  max (80) and const int min (40)
    puncspread(input, maximumlength, minimumlength);
    
    //Calling randspread if text is still less than 80 characters
    cout<< endl;
    
    randspread(input, maximumlength, minimumlength);
    
    cout << input;
}

void puncspread(string& inp, int max, int min) {
    // States if the length is less than fourty then do the thing, in the instructions it says if its less than fourty keep it the same so this function will only run if the input is more than 40.
    

   // int pos=s.find_first_of(afind);
    //while (pos != string::npos){
   //    cout << s << pos << endl;
   //    s.insert(pos + 1, " insert ");
  //     pos=s.find(afind, pos+1);
    if (inp.length() > min && inp.length() < max) {
        int pos =inp.find_first_of(punct);
    //Now the code should search for the punctuation marks
        while (pos != string::npos) {
          inp.insert(pos +  1, "  ");
          pos = inp.find_first_of(punct, pos+3);
           
            //It found the first of the punctuation marks so now it has to add 2 spaces
            
        }
    }
}
void randspread(string& inp, int max, int min) {
    //From directions:
    //continue until the string is justified
    //randomly pick a position between 0 and 80
    //locate the first white space following this position
       //(make sure it is not the end of the string)
    //insert a space there
    while (inp.length() < max) {
        srand(time(nullptr) % 80);
        int pos = (rand() * time(nullptr)) % 80;
            inp.find(" ");
            inp.insert(pos,"  ");
            pos = inp.find(space, pos + 2);
        }
}

