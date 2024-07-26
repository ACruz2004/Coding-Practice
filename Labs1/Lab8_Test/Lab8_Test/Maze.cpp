
//  Maze.cpp
//  Lab8_Test
//
//  Created by Anthony Cruz on 10/24/23.

#include <iostream>
#include "Maze.hpp"
using std::cout; using std::cin; using std::endl;

//Print Room Function
//..
//..
void printRoom(const Room& var) {
    cout << var.x << "," << var.y;
    
}

// Good Direction Function
//..
//..
bool goodDirection(const Room &rm, const char dr) {
    //right
    if (dr == 'r') {
        if (rm.x + 1 >= 4) {
            return false;
        }
    }
    //left
    else if (dr == 'l') {
        if (rm.x - 1 <= 0) {
            return false;
        }
    }
    //up
    else if (dr == 'u') {
        if (rm.y + 1 > 'a' + mazeSize + 1) {
            return false;
        }
    }
    //down
    else if (dr == 'd') {
        if (rm.y + 1 < 'a' - mazeSize - 1) {
            return false;
        }
    }
    return true;
}

// Create Adjacent Function
//..
//..
Room createAdjacent(const Room &rm, const char dr) {
 //   int xcord = Room().x;
 //   int ycord = Room().y;
    Room adjroom;
    //Direction: Up
    if (dr == 'u') {
        adjroom.y = rm.y - 1;
        adjroom.x = rm.x;
        }
    //Direction: Down
    else if (dr == 'd') {
        adjroom.y = rm.y + 1;
        adjroom.x = rm.x;
    }
    //Direction: Left
    else if (dr == 'l') {
        adjroom.x = rm.x - 1;
        adjroom.y = rm.y;
    }
    //Direction: Right
    else if (dr == 'r') {
        adjroom.x = rm.x + 1;
        adjroom.y = rm.y;
    }
    //Function returns a structure
    else if (dr == 'q') {
        adjroom.x = -1;
        adjroom.y = '*';
    }
    return adjroom;
    }

//Next room function
//..
//..
// returns {-1,*} if the user wants to quit

const Room nextMove(const Room& currentRoom) {
    //error and loop protection
    bool works = false;
    char input = '\0';
    
    cout << "What direction would you like to move? (r- right, l- left, u- up, d- down, q - quit. " << endl;
    
   
    
    while (works == false) {
    
    cin >> input;
        
        //Right
        if (input == 'r') {
            if (goodDirection(currentRoom, input) == true) {
                works = true;
                createAdjacent(currentRoom, input);
            }
            else {
                cout << "Out of wall, please make another selection";
            }
            
        }
        //Left
        else if (input == 'l') {
            if (goodDirection(currentRoom, input) == true) {
                works = true;
                createAdjacent(currentRoom, input);
            }
            else {
                cout << "Out of wall, please make another selection";
            }
            
        }
        //Up
        else if (input == 'u') {
            if (goodDirection(currentRoom, input) == true) {
                works = true;
                createAdjacent(currentRoom, input);
            }
            else {
                cout << "Out of wall, please make another selection";
            }
            
        }
        //Down
        else if (input == 'd') {
            if (goodDirection(currentRoom, input) == true) {
                works = true;
                createAdjacent(currentRoom, input);
            }
            else {
                cout << "Out of wall, please make another selection";
            }
            
        }
        else if (input == 'q') {
            cout << "Goodbye";
            createAdjacent(currentRoom, input);
            }
        else {
            cout << "Please enter a valid input: " << endl;
            works = false;
            
        }
    
    }
    return createAdjacent(currentRoom, input);
}

//Pick Adjacent function
//..
//..

// selects a random room adjacent to Room rm
// uses goodDirection() and createAdjacent()
const Room pickAdjacent(const Room &rm) {
    
    char input = 'i';
    
    bool reroll = true;
    
    int randnum = (rand() % 4) + 1;
    /*
     Room randpickup;
     Room randpickdown;
     Room randpickleft;
     Room randpickright;
     */
    Room pickedroom;
    
    //Right function
    while (reroll == true) {
        if (randnum == 1) {
            reroll = false;
            input = 'r';
            pickedroom.x = rm.x + 1;
            pickedroom.y = rm.y;
        if (goodDirection(pickedroom, input) == true) {
            createAdjacent(pickedroom, input);
            }
        }
        //left function
        else if (randnum == 2) {
            reroll = false;
            input = 'l';
            pickedroom.x = rm.x - 1;
            pickedroom.y = rm.y;
        if (goodDirection(pickedroom, input) == true) {
            createAdjacent(pickedroom, input);
            }
        }
        else if (randnum == 3) {
            reroll = false;
            input = 'u';
            pickedroom.y = rm.y - 1;
            pickedroom.x = rm.x;
        if (goodDirection(pickedroom, input) == true) {
            createAdjacent(pickedroom, input);
            
            }
        }
        else {
            reroll = false;
            input = 'd';
            pickedroom.y = rm.y + 1;
            pickedroom.x = rm.x;
        if (goodDirection(pickedroom, input) == true) {
            createAdjacent(pickedroom, input);
            }
        }
        
    }
    return pickedroom;
}


//Match Room defenition
//..
//..
bool matchRoom(const Room& R1, const Room& R2) {
    bool decision = false;
    if (R1.x == R2.x && R1.y == R2.y) {
        decision = true;
    }
    return decision;
}

//printPair Defenition
//..
//..
void printPair(const RoomPair& pair) {
    cout << "(" << pair.one.x << "," << pair.one.y << ")" << " , " << "(" << pair.two.x << "," << pair.two.y << ")";
}


//pickpair Defenition
//..
//..
// selects a random wall, uses pickAdjacent()
const RoomPair pickPair() {
    int randnum = (rand() % 4) + 1;
    char randchar;
    
    if (randnum == 1) {
        randchar = 'a';
    }
    else if (randnum == 2) {
        randchar = 'b';
    }
    else if (randnum == 3) {
        randchar = 'c';
    }
    else {
        randchar = 'd';
    }
    
    RoomPair Randompair = { {(2 + (rand() % 3)), randchar }, {pickAdjacent(Randompair.one)} };
    
    
    return Randompair;
}

//Match Room Function
//..
//..
bool matchPair(const RoomPair& wall, const RoomPair& move) {
    bool decision = false;
    if (wall.one.x == move.one.x && wall.one.y == move.one.y ) {
        decision = true;
    }
    
    return decision;
}

// Clear Walls Function
//..
//..
void clearWalls(RoomPair pair[] ) {
    for (int i = 0; i < numWalls; ++i) {
        pair[i].one.x = -1;
        pair[i].one.y = '*';
        pair[i].two.x = -1;
        pair[i].two.y = '*';
    }
    
}


//Print Maze Function
//..
//..
void printMaze(const RoomPair pair[]) {
    // prints the locations of all the internal
    //walls of the maze
    // uses printPair
    for (int i = 0; i < numWalls; ++i) {
       printPair(pair[i]);
        cout << " , ";
    }
    
}

//Checkmaze function
//..
//..
bool checkMaze(const RoomPair pair[], const RoomPair &move) {
    bool decision = false;
    for (int i = 0; i < numWalls; ++i) {
        if (pair[i].one.x == move.one.x && pair[i].one.y == pair[i].two.y) {
             decision = true;
        }
    }
    return decision;
}

// places internal walls in random locations of the maze
void build(RoomPair store[]) {

    for (int storedwalls = 0; storedwalls < numWalls;) {
        pickPair();
        checkMaze(store, pickPair());
        if (checkMaze(store, pickPair()) == false) {
            store[storedwalls].one.x = pickPair().one.x;
            store[storedwalls].one.y = pickPair().one.y;
            store[storedwalls].two.x = pickPair().two.x;
            store[storedwalls].two.y = pickPair().two.y;
            ++storedwalls;
        }
  
        
    }
       
}
