// Lab7_TextJustify
//Anthony Cruz
//Friday Oct 20th
//Code takes text from one file and transfers it to another while justified.
//Code start
//Include statements
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <fstream>
//using statements
using std :: string; using std :: cin; using std :: cout; using std :: endl;
using std::ifstream; using std::ofstream;
//Prototypes
const int maximumlength = 80;
const int minimumlength = 40;

string punct("!:.?");
string space(" ");

ifstream fin{"unjustified.txt"};
ofstream fout{"justified.txt"};

void puncspread(string& , int, int);
void randspread(string&, int, int);

//Main function
int main() {
    // Declaring the string in main function, it will then be called by reference later on
    string input;
    fin.open("unjustified.txt");
    
    while(getline(fin, input)) {
        
        // use cout << input; to test if input is stored *Y*
        
        //Calling the punctuation function that takes in string, const in  max (80) and const int min (40)
        puncspread(input, maximumlength, minimumlength);
        
        //Calling randspread if text is still less than 80 characters
        cout<< endl;
        
        randspread(input, maximumlength, minimumlength);
        
        fout << input << endl;
    }
    fin.close();
    fout.close();
}

void puncspread(string& inp, int max, int min) {
    
    if (inp.length() > min && inp.length() < max) {
        int pos =inp.find_first_of(punct);
    //Now the code should search for the punctuation marks
        while (pos != string::npos) {
            inp.insert(pos + 1, "  ");
          pos = inp.find(punct, pos+1);
            //It found the first of the punctuation marks so now it has to add 2 spaces
            
        }
    }
    fout << inp << endl;
}
void randspread(string& inp, int max, int min) {

    while (inp.length() < max) {
        srand(time(nullptr) % 80);
        int pos = (rand() * time(nullptr)) % 80;
        inp.find_first_of(space);
        //inp.insert(pos + 1, " ");
        pos = inp.find(space, pos + 1);
    }
    fout << inp << endl;
}

