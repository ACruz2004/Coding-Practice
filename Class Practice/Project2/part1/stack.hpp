// Anthony Cruz 7/9/2024 
// Project 2
// Part 1 
// Stack.hpp

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <cassert>

#include "node.hpp"

// START OF TEMPLATE CLASS
template <typename T>
// STACK
class stack {
public:
    // * Means Done
    stack () {tos = nullptr;};       // Default Constructor*
    stack (const stack<T>& ) ;       // Copy Constructor*
    ~stack();                        // Destructor*

    void swap           (stack<T>&); // Constant time swap*
    stack<T>& operator= (stack<T>) ; // Operator =*

    bool isEmpty()   const;          // isEmpty*
    bool isFull ()   const;          // isFull*
    T pop       ()        ;          // pop *not const**
    T top       ()   const;          // top*
    void push   (const T&);          // push*


private: 
    node<T> *tos;

};

///// Copy Constructor /////
//DIR: copy constructor: make a copy of the given stack//
template <typename T>
stack<T>::stack(const stack<T>& actual) {
    node<T> *temp = actual.tos;      // The node temp is set to actual.tos
    node<T> *bottom = 0;             // Bottom node is set to 0
    tos = 0;
    while (temp != 0) {
        if (tos == 0) {
            tos = new node<T>          (temp->data);
            bottom = tos;            // Set bottom to tos, fixes prev error
        } else {
            bottom->next = new node<T> (temp->data);
            bottom = bottom->next;
        }
        temp = temp->next;
    }     
} // Done with copy constructor

///// Destructor /////
//DIR: destructor: Free all the linked list items//
template <typename T>
stack<T>::~stack() {
    delete tos;
}

///// Swap /////
//DIR: swap(): constant Ime swapping, for copy assignment//
template <typename T>
void stack<T>::swap(stack<T>& rhs) {
    node<T> *temp = tos;
    tos = rhs.tos;
    rhs.tos = temp;
    //tos is the only thing that needs swapped in this case
}

///// Operator= /////
//DIR: copy assignment: assignment operator overload (operator=) using copy and swap idiom//
template <typename T>
stack<T>& stack<T>::operator=(stack<T> rhs) {
    swap(rhs);
    return *this;
}

///// IsEmpty /////
//DIR: isEmpty(): determine if the stack is empty//
template <typename T>
bool stack<T>::isEmpty() const {
    return (tos == 0);    // Just check if tos is equal to 0
}

///// IsFull /////
//DIR: isFull(): determine if the stack is full (using std::nothrow to create a new//
template <typename T>
bool stack<T>::isFull() const {
    node<T> *temp = new(std::nothrow) node<T>(); // Uses nothrow
    if (temp == 0) {
        return true;
    }
    delete temp;          //MAKE SURE TO DELETE TEMP
    return false;
}

///// pop /////
//DIR: pop(): remove the top item from the stack, and return the value of the top//
template <typename T>
T stack<T>::pop() {
    assert(!isEmpty());
    T result = tos->data;
    node<T> *temp = tos;
    tos = tos->next;
    delete temp;
    
    return result;
}

///// top /////
//DIR: top(): return the value of the top item without removing it from the stack//
template <typename T>
T stack<T>::top() const {
    assert(!isEmpty());
    return tos->data;
}

///// push /////
//DIR: push(): adds new item to the top of the stack. If the stack is full, terminate the program//
template <typename T>
void stack<T>::push(const T& item) {
    assert(!isFull());
    node<T> *temp = new node<T>(item);
    temp->next = tos;
    tos = temp;
}
#endif 