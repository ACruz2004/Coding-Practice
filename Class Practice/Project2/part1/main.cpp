#include <iostream>

#include "stack.hpp"

int main() {
	// Write test code for stack
	// Make sure to cover different data types for the stack
	
	// With Int
	{
		stack<int> s;
		s.push(1);
		s.push(2);
		s.push(3);

		while(!s.isEmpty()) {
			std::cout << s.pop() << std::endl;
		}
	}
	// With Char
	{
		stack<char> s;
		s.push('a');
		s.push('b');
		s.push('c');

		while(!s.isEmpty()) {
			std::cout << s.pop() << std::endl;
		}
	}
	//With Double
	{
		stack<double> s;
		s.push(1.1);
		s.push(2.2);
		s.push(3.3);

		while(!s.isEmpty()) {
			std::cout << s.pop() << std::endl;
		}
	}
	//With string
	{
		stack<std::string> s;
		s.push("one");
		s.push("two");
		s.push("three");

		while(!s.isEmpty()) {
			std::cout << s.pop() << std::endl;
		}
	}

	// TESTS FOR CONSTRUCTORS
	/////////////////////////
	/////////////////////////
	
	///// Default /////
	{
        stack<int> intStack;
        stack<double> doubleStack;
        stack<char> charstack;

           if (intStack.isEmpty())
               std::cout << "1" << std::endl;
          
           if (doubleStack.isEmpty())
               std::cout << "2" << std::endl;
          
            if (charstack.isEmpty())
                std::cout << "3" << std::endl;

    }
    std::cout << "Default Constructor Tested." << std::endl;

	///// Copy /////
	{
        
        stack<int> intStack;
        intStack.push(1);
        intStack.push(2);
        intStack.push(3);
        
        stack<int> intStack2(intStack);
        
        assert(intStack.top() == intStack2.top());
        intStack.pop();
        intStack2.pop();
        
        assert(intStack.top() == intStack2.top());
        intStack.pop();
        intStack2.pop();
        
        assert(intStack.top() == intStack2.top());
        intStack.pop();
        intStack2.pop();
        
    }
    
    {
        
        stack<int> intStack;
        intStack.push(13);
        intStack.push(26);
        intStack.push(31);
        
        stack<int> intStack2(intStack);
        
        assert(intStack.top() == intStack2.top());
        intStack.pop();
        intStack2.pop();
        
        assert(intStack.top() == intStack2.top());
        intStack.pop();
        intStack2.pop();
        
        assert(intStack.top() == intStack2.top());
        intStack.pop();
        intStack2.pop();
        
    }
    
    {
        
        stack<int> intStack;
        intStack.push('\0');
        intStack.push(2);
        intStack.push('\0');
        
        stack<int> intStack2(intStack);
        
        assert(intStack.top() == intStack2.top());
        intStack.pop();
        intStack2.pop();
        
        assert(intStack.top() == intStack2.top());
        intStack.pop();
        intStack2.pop();
        
        assert(intStack.top() == intStack2.top());
        intStack.pop();
        intStack2.pop();
        
    }
	std::cout << "Copy Constructor Tested." << std::endl;

	// Default Constructor
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
    
    std::cout << "Destructor Tested." << std::endl;

	///// Push Pop /////
    {
        stack<int>  test;
        int testvar1 = 1;
        int testvar2 = 2;
        int testvar3 = 3;

        test.push(testvar1);
        test.push(testvar2);
        test.push(testvar3);

        // VERIFY
        std::cout << test.top() << std::endl;
        assert(test.top() == 3);
        assert(!test.isEmpty());
        test.pop();
        std::cout << test.top() << std::endl;
        assert(test.top() == 2);
        assert(!test.isEmpty());
        test.pop();
        std::cout << test.top() << std::endl;
        assert(test.top() == 1);
        assert(!test.isEmpty());
        
        // TEST POP
        test.pop();
        
        //VERIFY
        assert(test.isEmpty());
    }
    
    std::cout << "Push and Pop Tested." << std::endl;

	{
        stack<int> placeholder;
        stack<int> placeholder2;
        
        stack<int> intStack;
        intStack.push(3);
        intStack.push(2);
        intStack.push(1);
        
        stack<int> intStack2;
        intStack2.push(9);
        intStack2.push(8);
        intStack2.push(7);
        
        stack<int> intStack3;
        intStack3.push(4);
        intStack3.push(5);
        intStack3.push(6);
       
        placeholder = intStack2;
        placeholder2 = intStack3;
        intStack3 = placeholder;
        intStack2 = placeholder2;

        
        
        // VERIFY
        std::cout << intStack.top() << std::endl;
        assert(intStack.top() == 1);
        assert(!intStack.isEmpty());
        intStack.pop();
        std::cout << intStack.top() << std::endl;
        assert(intStack.top() == 2);
        assert(!intStack.isEmpty());
        intStack.pop();
        std::cout << intStack.top() << std::endl;
        assert(intStack.top() == 3);
        assert(!intStack.isEmpty());
        
        // TEST POP
        intStack.pop();
        
        //VERIFY
        assert(intStack.isEmpty());
        
        // VERIFY
        std::cout << intStack2.top() << std::endl;
        assert(intStack2.top() == 6);
        assert(!intStack2.isEmpty());
        intStack2.pop();
        std::cout << intStack2.top() << std::endl;
        assert(intStack2.top() == 5);
        assert(!intStack2.isEmpty());
        intStack2.pop();
        std::cout << intStack2.top() << std::endl;
        assert(intStack2.top() == 4);
        assert(!intStack2.isEmpty());
        
        // TEST POP
        intStack2.pop();
        
        //VERIFY
        assert(intStack2.isEmpty());
        
        // VERIFY
        std::cout << intStack3.top() << std::endl;
        assert(intStack3.top() == 7);
        assert(!intStack3.isEmpty());
        intStack3.pop();
        std::cout << intStack3.top() << std::endl;
        assert(intStack3.top() == 8);
        assert(!intStack3.isEmpty());
        intStack3.pop();
        std::cout << intStack3.top() << std::endl;
        assert(intStack3.top() == 9);
        assert(!intStack3.isEmpty());
        
        // TEST POP
        intStack3.pop();
        
        //VERIFY
        assert(intStack3.isEmpty());
    }
    std::cout << "Assignment Tested." << std::endl;
	std::cout << "Main Tests Completed!" << std::endl;
}
