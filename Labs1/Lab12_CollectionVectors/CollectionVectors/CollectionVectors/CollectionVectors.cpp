// Created by Anthony Cruz
// 11/28/23
//Collection Vectors.Cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; using std::vector;
char userinput = 'i';
double usernum;
vector <double> myCollection;

int main() {

    //do while statement to run the code

    do {
        cout << "Enter operation [(a)dd, (r)emove, (q)uit] and a number: ";
        //Taking in user inputs
        cin >> userinput;
        cin >> usernum;
        
        //if statements for inputs
        if (userinput == 'a') {
            vector<double>::iterator id;
            //Basically Checks The Vector For The Number
            id = find(myCollection.begin(), myCollection.end(), usernum);
            //If the iterator is not at the end of the vector (meaning it found the number) It Displays an error
            if (id != myCollection.end()) {
               cout << "This number is already in there" ;
            }
            else {
                myCollection.push_back(usernum);
                for(vector<double>::iterator id = myCollection.begin();
                     id != myCollection.end(); ++id)
                    cout << *id << " ";
            }

        }
        if (userinput == 'r') {
            vector<double>::iterator id;
            id = find(myCollection.begin(), myCollection.end(), usernum);

            if (id != myCollection.end()){
                myCollection.erase(id);
                for(vector<double>::iterator id = myCollection.begin();
                     id != myCollection.end(); ++id)
                    cout << *id << " ";
            }
            else {
                cout << "Number is not in vector :( ";
            }
        }
        
        cout << endl;
    }
    while (userinput != 'q');
}
