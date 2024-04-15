//Lab8_Game
//Anthony Cruz

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "maze.h"

using std::cout; using std::cin; using std::endl;

RoomPair mymaze[numWalls];


int main() {
    
    build(mymaze);
    
    bool decision = false;
    char charinput;
    
    cout << "The starting room is: " << startRoom.x <<  "," << startRoom.y << endl;
    
    cout << "Would you like to see the walls? (Y/N) " << endl;
    cin >> charinput;
    
    Room mousepos;
    mousepos.x = 1;
    mousepos.y = 'a';
    
    
   
    
    
    
    
    //Takes input of walls
    if (charinput == 'Y' || charinput == 'y') {
        decision = true;
    }
    
    if (decision == true) {
        printMaze(mymaze);
    }
    
    while (mousepos.x != 4 && mousepos.y != 'd') {
        printRoom(mousepos);
        cout << endl;
        nextMove(mousepos);
        
        Room newmoveroom = nextMove(mousepos);
        
        RoomPair mousepair;
        mousepair.one = mousepos;
        mousepair.two = newmoveroom;
        
        if (checkMaze(mymaze, mousepair) == false) {
            mousepos = newmoveroom;
            }
        else {
            cout << "You hit a wall!" << endl;
        }
        
    }
    cout << "You win!";
}

