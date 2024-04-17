//
//  utilities.hpp
//  assembler
//
//  Created by Anthony Cruz on 4/10/24.
//

#ifndef utilities_hpp
#define utilities_hpp

//BELOW CODE WONT WORK, THIS IS MEANT FOR ERROR CHECKING ON VISUAL STUDIO//
#include "../string/string.hpp"
#include <iostream>
#include <fstream>
#include "stack.hpp"
//INFIX TO PREFIX
//String infixToPrefix(std::istream&);

//INFIX TO POSTFIX
String infixToPostfix(std::ostream&, std::istream&, bool);


//String postfixToAl(const String&);
// If not operator
// s.push(v[i])

//String prefixToAl(const String&);
#endif /* utilities_hpp */
