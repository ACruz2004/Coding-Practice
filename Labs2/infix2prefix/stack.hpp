//
// File: stack.hpp
//
// Programmer:
// Date:        Spring 2024
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//
#ifndef STACK_HPP
#define STACK_HPP

#include <new>
#include <cassert>
//#include "../string/string.hpp"
#include "string.h"


template<typename T>
class Node {
public:
    Node() : next(0) {};
    Node(const T& x) : data(x), next(0) {};
    T data;
    Node<T>* next;
};


// CLASS INV:
//
template <typename T>
class stack {
public:
    stack     () {tos = nullptr;};  //Done
              stack     (const stack<T>& ); //Done
              ~stack    ();         // Done
    //TOS is the only thing needed to swap
    void      swap      (stack<T>&);// Done
    stack<T>& operator= (stack<T>); // Done
    
    bool      empty     () const;   // Done
    bool      full      () const;   // Done
    T         top       () const;   // Done
    T         pop       ();         // Done
    void      push      (const T&); // Done

private:
    Node<T>   *tos;
};

// STACK(CONST STACK<T>
template <typename T>
stack<T>::stack(const stack<T>& actual) {
    Node<T> *temp = actual.tos;
    Node<T> *bottom = 0;
    tos = 0;
    while (temp != 0) {
        if (tos ==0) {
            tos = new Node<T>(temp->data);
            bottom = tos;
        } else {
            bottom->next = new Node<T>(temp->data);
            bottom = bottom->next;
        }
        temp = temp->next;
    }
}

//PUSH
template <typename T>
void stack<T>::push(const T& item) {
     assert(!full());
     Node<T> *temp = new Node<T>(item);
     temp->next = tos;
     tos = temp;
}

//SWAP
template <typename T>
void stack<T>::swap(stack<T>& rhs) {
    Node<T> *temp = tos;
    tos           = rhs.tos;
    rhs.tos       = temp;
}

//FULL
template<typename T>
bool stack<T>::full() const {
    Node<T> *temp = new(std::nothrow) Node<T>();
    if (temp == 0) {// No memory
        return true;
    }
    delete temp;
    return false;
}

//EMPTY
template <typename T>
bool stack<T>::empty() const {
    return tos == 0;
}

//TOP & POP
//POP
template <typename T>
T stack<T>::pop() {
    assert(!empty());
    T result = tos->data;
    Node<T> *temp = tos;
    tos = tos->next;
    delete temp;
    
    return result;
}
//TOP
template <typename T>
T stack<T>::top() const {
    assert(!empty());
    return tos->data;
}

//DESTRUCTOR
template <typename T>
stack<T>::~stack() {
    Node<T> *temp;
    while (tos != 0) {
        temp = tos;
        tos = tos->next;
        delete temp;
    }
}

template <typename T>
stack<T>& stack<T>::operator= (stack<T> rhs) {
    swap(rhs);
    return *this;
}
#endif
