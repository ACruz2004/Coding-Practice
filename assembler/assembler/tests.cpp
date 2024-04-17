//  Stack class test program
//
//  Tests: Assignment
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        stack<int> myStack;
          myStack.push(1);
          myStack.push(2);
          myStack.push(3);
            
      
    }
    
    {
        stack<int> myStack;
          myStack.push(1);
          myStack.push(2);
          myStack.push(3);
            
          myStack.pop();
          myStack.pop();
          myStack.pop();
    }
    
    
    std::cout << "Done testing Assignment." << std::endl;
    return 0;
}

