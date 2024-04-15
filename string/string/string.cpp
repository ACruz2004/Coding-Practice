//  string.cpp
//  string
//
//  Created by Anthony Cruz on 2/28/24.
//
#include <iostream>
#include "string.hpp"
#include <cassert>



//Default Constructor
//Empty string
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
String::String() {
  STRING_SIZE = 1;
  str = new char [STRING_SIZE];
  str[0] = '\0';
}

//String Char
// 'x'
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
String::String(char ch) {
    if (ch == '\0') {
        STRING_SIZE = 1;
        str = new char [STRING_SIZE];
        str[0] = '\0';
    } else {
        STRING_SIZE = 2;
        str = new char [STRING_SIZE];
        str[0] = ch;
        str[1] = '\0';
    }
}
//String Char[]
// "XYZ"
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
String::String(const char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    STRING_SIZE = i + 1;
    str = new char [STRING_SIZE];
    //loop for assigning s to str
    for (int j = 0; j < capacity(); ++j) {
        str[j] = s[j];
    }
    str[capacity()] = 0;
}

//String Destructor
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
String::~String() {
    delete[] str;
}

//Copy Constructor
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
String::String(const String& real) {
    STRING_SIZE = real.STRING_SIZE;
    str = new char[STRING_SIZE];
    for (int i = 0; i < capacity(); ++i) {
        str[i] = real.str[i];
    }
}

//Swap
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
void String::swap(String& rhs) {
    if (this == &rhs) return;
    char* temp      = str;
    str             = rhs.str;
    rhs.str         = temp;
    
    
    int ctemp       = STRING_SIZE;
    STRING_SIZE     = rhs.STRING_SIZE;
    rhs.STRING_SIZE = ctemp;
}

//Assignment
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
String& String::operator=(String rhs) {
    /*
    if (str == rhs.str) return *this;
    delete[] str;
    STRING_SIZE = rhs.length();
    str = new char[STRING_SIZE];

    for (int i = 0; i < STRING_SIZE; ++i) {
        str[i] = rhs.str[i];
    }
    
    str[STRING_SIZE] = '\0';
    
    return *this;
     */
    swap(rhs);
    return *this;
}

//Length
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
int String::length() const {
    int length = 0;
    while (str[length] != '\0'){
    ++length;
    }
    return length;
}

//Capacity
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
int String::capacity() const {
    return STRING_SIZE - 1;
}

// Char [] Operator
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
char String::operator[](int i) const {
    assert(i > 0);
    assert(i < length());
    return str[i];
}

// Char& [] Operator
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
char& String::operator[](int i) {
    assert(i >= 0);
    assert(i <= length());
    return str[i];
}

//Concantination
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
String& String::operator+=(const String& rhs) {
    int oset = length();
    STRING_SIZE = (length() + rhs.length()) + 1;
//
    int rhsLen = rhs.length();
    int i = 0;
    while (i < rhsLen) {
        if (oset + i >= STRING_SIZE) break;
        str[oset + i] = rhs.str[i];
        ++i;
        }
    str[oset + i] = '\0';
//Returns *this
//REMEMBER FOR ERROR CHECKING (in case it fails return something else)
    return *this;
}

//==Operator
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
bool String::operator==(const String& rhs) const {
    int i = 0;
    while ((str[i] != '\0') && (rhs.str[i] != '\0') && (str[i] == rhs.str[i])) {
        ++i;
    }
    return str[i] == rhs.str[i];
}

bool String::operator<(const String& rhs)  const {
    int  i = 0;
    
    while ((str[i] != 0) && (rhs.str[i] != 0)  )  {
        if (str[i] == rhs.str[i] ){
        ++i;
        }
        else {
            break;
        }
    }
    if ((str[i] == '\0') && (rhs.str[i] != '\0')) return true;
    if (str[i] < rhs.str[i]) return true;
           

    
    return false;
}

//Substring
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
String String::substr(int first, int last) const {
    if (first < 0) {
        first = 0;
    }
    if (last > length()){
        last = length() - 1;
    }
    if (first >= last){
        return String();
    }
    String result;
    
    int i = first;
    while (i <= last) {
        result.str[i - first] = str[i];
        ++i;
    }
    result.str[i - first] = 0;
    return result;
}


//Find Ch
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
int String::findch(int start,  char ch) const {
    int result = 0;
    for (int i = start; i < STRING_SIZE; i++) {
        if (str[i] == ch) {
            return result;
        }
        else{
            result = result + 1;
        }
    }
    return -1;
}

//Find Str
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
//- returns the location of str at or after start, returns -1 if not found.
int String::findstr(int start,  const String& rhs) const {
    int result = 0;
    for (int i = start; i < STRING_SIZE; i++) {
        if (str[i] == rhs[0]) {
            for (int j = 0; j < rhs.length(); ) {
                if (str[j + i] == rhs[0 + j]) {
                    if (j == rhs.length() - 1) {
                        return result;
                    }
                    ++j;
                }
                else{
                    break;
                }
            }
        }
        else{
            result = result + 1;
        }
    }
    return -1;
}

// << Operator
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& out, const String& rhs) {
    out << rhs.str;
    return out;
}

// >> Operator
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
std::istream& operator>>(std::istream& input, String& rhs) {
    int size = rhs.STRING_SIZE;
    char buff[size];
    if (!input.eof()) {
        input >> buff[0];
    }
    else {
        buff[0] = 0;
    }
    rhs = String(buff);
    return input;
}

// Vector
//.//////////////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<String> String::split(const char ch) const {
    int start = 0;
    int end = 0;
     
    std::vector<String> temp;
    while(end != -1){
        end = findch(start, ch);
         
        if(start == end){
            temp.push_back("");
        } else if(end != -1) {
            temp.push_back(substr(start, end - 1));
        }
        if (end == -1) {
            temp.push_back(substr(start, length()));
        }

        start = end + 1;
    }
    return temp;
}

//OUTSIDE OPERATORS//////////////////////////////////////////////////////////////////////////////////////////
String operator+(String       lhs,   const String& rhs) {
    return lhs += rhs;
}
bool operator==(const char  lhs[],   const String& rhs)  {
    return String(lhs) == rhs;
}
bool operator==(char          lhs,   const String& rhs)  {
    return String(lhs) == rhs;
}
bool operator< (const char  lhs[],   const String& rhs)  {
    return String(lhs) < rhs;
}
bool operator< (char          lhs,   const String& rhs)  {
    return String(lhs) < rhs;
}
bool operator<=(const String& lhs,   const String& rhs)  {
    return !(rhs < lhs);
}
bool operator!=(const String& lhs,   const String& rhs)  {
    return !(lhs == rhs);
}
bool operator>=(const String& lhs,   const String& rhs)  {
    return !(lhs <= rhs);
}
bool operator> (const String& lhs,   const String& rhs)  {
    return rhs < lhs;
}


