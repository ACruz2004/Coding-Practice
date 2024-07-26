//  fib.cpp
//
//  Created by Anthony Cruz on 6/24/24
//
#include <iostream>

//Tail recursive
int fibTail(int num,int a, int b) {
    if (num == 0) {
        return a;
    }
    if (num == 1) {
        return b;
    }
    return fibTail(num - 1, b, a + b);
}

//Regular Recursive
int fib(int n) {
    int result;
    if (n <= 1) return n;
    result = fib(n-1) + fib(n -2);
    return result;
}

int main() {
    
    int n = 20;
    for (int i = 0; i < n; ++i)
        std::cout << fib(i) << " ";
    
        std::cout << std::endl;
    
    for (int i = 0; i < n; i++)
        std::cout << fibTail(i, 0, 1) << " ";
    
        std:: cout << std::endl;
}
