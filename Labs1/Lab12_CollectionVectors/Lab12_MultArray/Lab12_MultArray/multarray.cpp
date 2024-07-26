// keeping track of the path taken by the mouse in the maze
// using a multidimentional array
// Anthony Cruz
// 11/28/23

#include <iostream>
using namespace std;
// maze dimensions
const int mazeLength = 6;
const int mazeWidth = 6;
int pathway[[]];
int main(){
    
    int mouseX = 0; // current mouse X index
    int mouseY = 0; // current mouse Y index
    
    bool maze[mazeLength][mazeWidth]; // declare mouse maze tracking array
    maze[mouseX][mouseY]= true;  // place mouse in the top-left corner
    
    // Initialization
    for(int i=0; i < mazeLength; ++i)
        for(int j=0; j < mazeWidth; ++j)
            maze[i][j] = i * mazeWidth + j;
    
    //Taking in the user input
    char userinput = 'i';
    
    while (userinput != 'q' || 'Q') {
        cout << "Enter a mouse direction: (U)p, (D)own, (L)eft, (R)ight, or (Q)uit... " << endl;
        //cin
        cin >> userinput;
        
        
        //Up
        if (userinput == 'u' || userinput == 'U') {
            if (mouseX > 0) {
                mouseX = mouseX - 1;
                maze[mouseX][mouseY] = false;
            }
        //Right
        }
        if (userinput == 'R' || userinput == 'r') {
            mouseY = mouseY + 1;
            maze[mouseX][mouseY] = false;
        //Down
        }
        if (userinput == 'd' || userinput == 'D') {
            mouseX = mouseX + 1;
            maze[mouseX][mouseY] = false;
        //Left
        }
        if (userinput == 'l' || userinput == 'L') {
            mouseY = mouseY - 1;
            maze[mouseX][mouseY] = false;
        //Quit
        }
        if (userinput == 'q' || userinput == 'Q') {
            break;
        }
        
        
        //Maze Print
        cout << "  a b c d e f " << endl;
        //One
        cout << "1 ";
        for (int j=0; j < mazeWidth; ++j){
            if (maze[0][j] == false) {
                cout << "* ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
        //Two
        cout << "2 ";
        for (int j=0; j < mazeWidth; ++j){
            if (maze[1][j] == false) {
                cout << "* ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
        //Three
        cout << "3 ";
        for (int j=0; j < mazeWidth; ++j){
            if (maze[2][j] == false) {
                cout << "* ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
        //Four
        cout << "4 ";
        for (int j=0; j < mazeWidth; ++j){
            if (maze[3][j] == false) {
                cout << "* ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
        //Five
        cout << "5 ";
        for (int j=0; j < mazeWidth; ++j){
            if (maze[4][j] == false) {
                cout << "* ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
        //Six
        cout << "6 ";
        for (int j=0; j < mazeWidth; ++j){
            if (maze[5][j] == false) {
                cout << "* ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
       
        
        
    }
}

