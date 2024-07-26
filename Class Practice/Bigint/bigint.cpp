//Bigint.cpp
//Anthony Cruz 
//5/23/2024
//CS23001

#include "bigint.hpp"

//Default Ctor M1 
//DIR: A default ctor to initialize a bigint to zero
////////////////////////////////////////////////////
bigint::bigint() {
    for (int i = 0; i < CAPACITY; ++i) {
        numbArr[i] = 0;
    }
}

//Bigint->Int M1
//DIR: A constructor to initialize a bigint to an int value you provide [0, maxint]. Example: bigint(128).
////////////////////////////////////////////////////
bigint::bigint(int num) {
    for (int i = 0; i < CAPACITY; ++i) {
    //Get the % value of the original number and store it in a seperate int
    //EX THIS TURNS 128 TO JUST 8
    int digit = num % 10;
    //Store the digit to numbArr 
    numbArr[i] = digit; 
    //Divide the number by 10 to decrement the number by a place 
    //EX 128 IS NOW JUST 12
    num = num / 10;
    }
} 

//Bigint->Char[] M1
//DIR: A constructor to initialize a bigint to a const char[] you provide. 
//     You can assume what is provided is a valid bigint. Example: bigint("299793").
////////////////////////////////////////////////////
bigint::bigint(const char charray[]) {
//Find the length
    int length = 0;
    while (charray[length] != 0) ++length;
//Place each element of charray into a bigint by subtracting the int value by the int value of the character 0
    int i = 0;
    while (charray[i] != 0) {
        //Guard to make sure i doesn't go over length
        if (i > length + i) break;
         //Placement  Length - 1 
        numbArr[i] = int(charray[length - 1]) - int('0');
         //Increment i and decrement length
        ++i;
        --length;
    }
    //Leading zeros
    while (i < CAPACITY) {
        numbArr[i] = 0;
        ++i;
    }
}

//DebugPrint M1 
//DIR: It simply prints out every element of your bigint array starting from the highend (e.g., capacity-1) of the bigint to zero. Printing a "|" between each value will also be pretting helpful to help with debugging.
////////////////////////////////////////////////////
void bigint::debugPrint(std::ostream &out) const {
    //print numbArr
    for (int i = 0; i < CAPACITY; ++i) {
        out << numbArr[i] << " | ";
    }

}

//Comparison Operator M1
//DIR: Compares two Bigints to see if they are equal if so return true;
////////////////////////////////////////////////////
bool bigint::operator==(const bigint& bigintTwo) const {
    for (int i = 0; i < CAPACITY; ++i) {
        //check if any number in both bigints is unequal
        if (numbArr[i] != bigintTwo.numbArr[i]) {
            return false;
        }
    }
    //if they are return true
    return true;
}

//Subscript Operator M2
//DIR: Example: bigint a(2345); a[0] == 5 && a[1] == 4 && a[2] == 3 && a[3] == 2
////////////////////////////////////////////////////
bigint bigint::operator[](int num) const {
// //First find the length, length - num is what we're looking for
// int length = 0;
// for (int j = 0; j < CAPACITY; ++j) {
//     if (numbArr[j] != 0) {
//         ++length;
//     }
// }

// int result;                                         // Result storage
// result = numbArr[length - num];                     // The result is going to be the value of numbArr within length - number 
// return result;                                      // Returns result
    return numbArr[num];                               // Defenitely over-complicated that
}

//Addition Operator M2
//DIR: Overload the operator+ so that it adds two bigint together. bigint operator+(const bigint&) const;
////////////////////////////////////////////////////
bigint bigint::operator+(const bigint& secBigint) const {
    bool carry = false;                                 // This will be used to determine if a 1 gets carried or not
    bigint result;                                      // This will be used to store the result

    //For loop start
    for (int i = 0; i < CAPACITY; ++i) { 
        result.numbArr[i] = numbArr[i] + secBigint.numbArr[i]; // Add the i value of numbArr and secBigint
        // ONLY FOR NUMBERS THAT NEED A CARRY
        if (carry == true) {
            result.numbArr[i] = result.numbArr[i] + 1;  // If carry is true add 1 to the result
        }
        // Carry check
        if (result.numbArr[i] >= 10) {                  // If the sum of those numbers is greater than or equal to 10
            result.numbArr[i] = result.numbArr[i] - 10; // Subtract the sum by 10
            carry = true;                               // Set the carry bool to true
        } else {
        // If there is no need for a carry, the n carry is set to false
            carry = false;
        }
    }
    return result;                                     // Return the result
}

//Output Operator M1
//DIR: Outputs a bigint
////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream &out, const bigint& right) {
// Finds the length of the number so it doesn't print in reverse order
// This should fix the bug I have beesn having
    int length = 0;
    for (int j = CAPACITY - 1; j >= 0; --j) {
        if (right.numbArr[j] != 0) {
            length = j + 1;
            break;
        }
    }

    // Printing the Bigint
    // Also makes it so if it passes 80 it will start on a new line :0\n
    int count = 0;
    // I is the length of the bigint - 1 then you decrement the i instead of increment
    // When I did this before I incremented and not decremented which caused errors
    for (int i = length - 1; i >= 0; --i) { 
        out << right.numbArr[i];
        ++count;
        if (count == 80) {
            out << std::endl;
            count = 0;
        }
    }

    return out;
}

//Output Operator M2
//DIR: Read in any number of digits [0-9] until a semi colon ";" is encountered. 
//     The number may span over multiple lines
////////////////////////////////////////////////////
std::istream& operator>>(std::istream& in, bigint& rhs) {
    //char that stores what is loaded
    char load[CAPACITY];
    // char I used to get current character
    char ch;
    int i = 0;

    //Clear the rhs to prevent errors
    rhs = bigint();

    while (in.get(ch) && ch != ';') {
    // isDigit checks to make sure that ch is a digit value
        if (isdigit(ch)) {
            load[i++] = ch;
        }
    }
    load[i] = '\0';

    rhs = bigint(load);
    return in;
    // Still buggy but it works
}

// timesDigit(int) M3
// Dir: A method bigint timesDigit(int) const; to multiply a bigint and a single digit integer 
// between 0 and 9 Note that this is different than bigint * int because there the int will be 
// converted into a bigint automatically by the constructor so will end up being bigint * bigint.
bigint bigint::timesDigit(int number) const{
    bigint result;                    // The bigint that will store the result
    bool carry = false;               // This is the bool for the carry
    int carrynum = 0;                 // This number will be incremented based on the carry number
    for (int i = 0; i < CAPACITY; ++i){
        // Multiply number by each number in array
        result.numbArr[i] = numbArr[i] * number;
        // For the carry
        if (carry == true) {
            result.numbArr[i] = result.numbArr[i] + carrynum; 
        }
        if (result.numbArr[i] >= 10) {
            // The carry num needs to be reset every time there is a new carry num
            carrynum = 0;
            // Start of while loop for carry
            while(result.numbArr[i] >= 10) {
                result.numbArr[i] = result.numbArr[i] - 10; // Every time result[i] is more than ten, subtract 10 and increment carrynum
                ++carrynum;                                 // Carrynum incrementation
                carry = true;                               // Carry = true
            }
        }
        else {
            carry = false;                                  // Carry = false
        }
    }
    return result;                                          // Return result
}

// times10(int) M3
// Dir: to multiply a bigint by 10^n with n>0. (a.k.a. shift left base 10). 
// For example, given x == 234, x.times10(2) == 23400, that is 234 * 10^2. 
// This can be implemented simply by shifting the bigint n digits to the left.
bigint bigint::times10(int number) const {
    bigint result;                                  // Stores the result
    int place = number;                             // The tens place

    for (int i = 0; i < CAPACITY; ++i) {
        if (i < number) {
            result.numbArr[i + place] = numbArr[i]; // Makes the i + place of result the number in the i postition
            result.numbArr[i] = 0;                  // Makes the i postition zero
        }
        else {
            result.numbArr[i + place] = numbArr[i]; // Makes the i + place of result the number in the i postition
        }
    }
    return result;                                  // Returns the result
}

// operator*
// Dir: Implement this multiply using the shift left and times single digit methods above.
bigint bigint::operator*(const bigint& rhs) const{
     bigint multi;                                  // Bigint for multi
     bigint product = 0;                            // The product
    
    for (int i = 0; i < CAPACITY - 1; ++i) {
        if (numbArr[i] != 0) {         
            multi = rhs.timesDigit(numbArr[i]);     // Like in the project page
            product = product + multi.times10(i);
        }
    }
    return product;
}
