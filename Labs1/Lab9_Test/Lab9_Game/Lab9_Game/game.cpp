
//  game.cpp
//  Lab9_Game
//  Created by Anthony Cruz on 11/6/23.

#include "maze.h"
#include <iostream>
using std::cout; using std::cin; using std::endl;

int main() {
    Maze myMaze;
    //Make the start room
    Room startRoom; startRoom.makeStartRoom();
    //Make the cheese room
    Room cheeseRoom; cheeseRoom.makeCheeseRoom();
    //Build The Maze
    myMaze.build();

    //View maze walls prompt
    char input;
    cout << "Would you like to see the maze wall positions?" << endl;
    cin >> input;
    
    if (input == 'Y' || input == 'y') {
        myMaze.print();
    }
    bool contingame = true;
  
    Room myroom = startRoom;
    
    //Cannot figure out this error
    //Room and room should be the same
    while (myroom != cheeseRoom && contingame == true ) {
        myMaze.getCurrentRoom();
        myroom.print();
        myroom.nextMove();
        
        Room newroom = myroom.nextMove();
        
        RoomPair pair(myroom,newroom);
        
        myMaze.move(newroom);
        
        if (myMaze.move(newroom) == true) {
            cout << "Move successful" << endl;
        }
        else {
            cout << "You hit a wall!" << endl;
        }
    }
    cout << "You win!";
}
