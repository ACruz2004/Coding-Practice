
//  maze.cpp
//  Lab9_Test
//  Created by Anthony Cruz on 10/31/23.

#include "maze.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout; using std::cin; using std::endl;

//Defining Room
//..
//..
Room::Room() :
    x_(-1), y_('*') {}

//Print Function for Room
//..
//..
void Room::print() const {
    cout << x_ << " , " << y_;
}

//Pick Function
//..
//..
void Room::pick() {
    //X
    int x = (rand() % 4) + 1;
    //Y
    //Character Picker
    int randnum = (rand() % 4) + 1;
    
    if (randnum == 1) {
        y_ = 'a';
    }
    else if (randnum == 2) {
        y_ = 'b';
    }
    else if (randnum == 3) {
        y_ = 'c';
    }
    else {
        y_ = 'd';
    }
    
    x_ = x;
}
    
//PickAdjacent function
// selects a random adjacent room
// uses goodDirection() and createAdjacent()
const Room Room::pickAdjacent() {
    int randnum;
    char randinput = 'i';
    bool reroll = true;
    
    while (reroll == true) {
        randnum = (rand() % 4) + 1;
        if (randnum == 1) {
            randinput = 'r';
            if (goodDirection(randinput) == true) {
                reroll = false;
            }
        }
        else if (randnum == 2) {
            randinput = 'l';
            if (goodDirection(randinput) == true) {
                reroll = false;
            }
        }
        else if (randnum == 3) {
            randinput = 'u';
            if (goodDirection(randinput) == true) {
                reroll = false;
                }
            }
        else if (randnum == 4) {
            randinput = 'd';
            if (goodDirection(randinput) == true) {
                reroll = false;
            }
        }
    }
    return createAdjacent(randinput);
}

//Gooddirection Frunction
//..
//..
bool Room::goodDirection(const char dr) const {
    
    bool decision = true;
    
    //right
    if (dr == 'r') {
        if (x_ + 1 > 4) {
            decision = false;
        }

    }
    //left
    else if (dr == 'l') {

        if (x_ - 1 < 0) {
            decision = false;
        }
    }
    //up
    else if (dr == 'u') {
        if (y_ + 1 > 'a' + mazeSize_ + 1) {
            decision = false;
        }
    }
    //down
    else if (dr == 'd') {
        if (y_ + 1 < 'a' - mazeSize_ - 1) {
            decision = false;
       }
    }

    return decision;

}
// returns the room adjacent to this room in the specified direction
// assumes the direction is inside the maze
const Room Room::createAdjacent(const char dr) const{
    Room adjroom;
    adjroom.x_ = x_;
    adjroom.y_ = y_;

    //Direction: Up
        if (dr == 'u') {
            adjroom.y_ -= 1;
            adjroom.x_ = adjroom.x_;
        }

        //Direction: Down
        else if (dr == 'd') {
            adjroom.y_ += 1;
            adjroom.x_ = adjroom.x_;
        }

        //Direction: Left
        else if (dr == 'l') {
            adjroom.x_  -= 1;
            adjroom.y_ = adjroom.y_;
        }

        //Direction: Right
        else if (dr == 'r') {
            adjroom.x_ += 1;
            adjroom.y_ = adjroom.y_;
        }

        //Quit Function
        else if (dr == 'q') {
            adjroom.x_ = -1;
            adjroom.y_ = '*';
        }
    return adjroom;

}

//Next Move Function
//..
//..
const Room Room::nextMove() const {
    bool works = false;
        char input = '\0';
    
        cout << "What direction would you like to move? (r- right, l- left, u- up, d- down, q - quit. " << endl;
        while (works == false) {
            cin >> input;
            
            //Right
            if (input == 'r') {
                if (goodDirection(input) == true) {
                    works = true;
                    createAdjacent(input);
                   
                }
               else {
                    cout << "Out of wall, please make another selection";
                }
            }
            //Left
            else if (input == 'l') {
                if (goodDirection(input) == true) {
                    works = true;
                    createAdjacent(input);
                }
                else {
                    cout << "Out of wall, please make another selection";
                }
            }

            //Up
            else if (input == 'u') {
                if (goodDirection(input) == true) {
                    works = true;
                    createAdjacent(input);
                }
                else {
                    cout << "Out of wall, please make another selection" << endl;

                }
            }
            
            //Down
            else if (input == 'd') {
                if (goodDirection(input) == true) {
                    works = true;
                    createAdjacent(input);
                }
                else {
                    cout << "Out of wall, please make another selection";
                }
            }
            
            //Quit
            else if (input == 'q') {
                cout << "Goodbye";
                createAdjacent(input);
            }

            else {

                cout << "Please enter a valid input: " << endl;
                works = false;

            }
        }
    return createAdjacent(input);
}

//Match Room Function
bool matchRoom(const Room& oldroom, const Room& newroom) {
    //Error Prev.
    bool decision = false;
    
    if (oldroom.x_ == newroom.x_ && oldroom.y_ == newroom.y_){
        decision = true;
    }
    else if (oldroom.x_ == newroom.y_ && oldroom.y_ == newroom.x_) {
        decision = true;
    }
    return decision;
}

//Room pair function
//..
//..
void RoomPair::print() const {
    one_.print();
    cout << " | ";
    two_.print();
}

//Room pair function
//..
//selects a random wall, uses Room::pickAdjacent()
void RoomPair::pick() {
    one_.pick();
    two_ = one_.pickAdjacent();
}

//Matchpair function
//..
// returns false otherwise, uses matchRoom() note that r1|r2 matches r2|r1
bool matchPair(const RoomPair& oldroom, const RoomPair& newroom) {
    //Error Prev.
    bool decision = false;
    
    if (matchRoom(oldroom.one_, newroom.two_)) {
        decision = true;
    }

    return decision;
}


//Maze Print
// prints the locations of all the internal walls of the maze
// and current mouse location
void Maze::print() const {
    for (int i = 0; i < numWalls_; i++) {
        cout << "(";
        walls_[i].print();
        cout << ")";
        cout << " ";
    }
}

//Checkmaze function
//..
// returns true if RoomPair matches one of the walls in the maze
bool Maze::checkMaze(const RoomPair& move) const {
    bool decision = false;
    for (int i = 0; i < numWalls_; i++) {
        if (matchPair(walls_[i], move)) {
            decision = true;
        }
    }
    return decision;
}

//Build Function
// places internal walls in random locations of the maze
// all walls are different
void Maze::build() {
    for (int storedwalls = 0; storedwalls < numWalls_;) {
        walls_[storedwalls].pick();
        checkMaze(walls_[storedwalls]);
        if (checkMaze(walls_[storedwalls]) == false) {
            ++storedwalls;
        }
    }
}

// takes the room to move the mouse to
// moves the mouse there and returns true if no walls (move is possible)
// does not move the mouse and returns false if wall
bool Maze::move(const Room& newroom) {
    bool decision = false;
    if (checkMaze({newroom, currentRoom_}) == false && checkMaze({currentRoom_, newroom}) == false) {
        currentRoom_ = newroom;
        decision = true;
    }
    return decision;
}


