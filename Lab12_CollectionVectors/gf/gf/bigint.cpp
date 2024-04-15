//Bigint
//Project 1
//Anthony Cruz
#include "bigint.hpp"


//Constructor Numero Uno *WORKS*
//Directions/////////////////////////////////////////
//A default constructor to initialize a bigint to zero.
//Code

bigint::bigint() {
    for (int i = 0; i < size; ++i) {
        numbarr[i] = int(0);
    }
}


//Constructor Numero Dos (el constructor de int) *WORKS*
//Directions/////////////////////////////////////////
//A constructor to initialize a bigint to an int value you provide [0, maxint]. Example: bigint(128).
//Code
bigint::bigint(int number){
    
    for (int i = 0; i < size; ++i) {
        int digit = number % 10;
        numbarr[i] = digit;
        number = number / 10;
        // this turns the number into a fraction in which it will cut off due to it   being an int
    }
}



//Constructor Numero tres (char)
//Directions//////////////////////////////////////////
//A constructor to initialize a bigint to a const char[] you provide. You can assume what is provided is a valid bigint. Example: bigint("299793").
//Code
bigint::bigint(const char charray[]) {
    //while loop for finding the length
    int length = 0;
    while (charray[length] != 0) ++length;
    //while loop for placing
    int i = 0;
    while (charray[i] != 0) {
        if (i > length + i) break;
        numbarr[i] = int(charray[length - 1]) - int('0');
        ++i;
        --length;
    }
    while (i < size) {
        numbarr[i] = 0;
        ++i;
    }
}

void bigint::debugPrint(std::ostream& out) const {
    out << numbarr;
    for (int i = 0; i < size; i++) {
        out << numbarr[i] << " | ";
    }
    
}

//Comparison Operator
bool bigint::operator==(const bigint& secbigint) const {
    for (int i = 0; i < size; ++i) {
        if (numbarr[i] != secbigint.numbarr[i]) {
            return false;
            }
    }
    return true;
}

//Output Operator
    //std::ostream& operator<<(std::ostream& out, const bigint& right) {
    std::ostream& operator<<(std::ostream& out, const bigint& right) {
    bool printline = false;
    for (int i = 0; i < size; ++i) {
        if (right.numbarr[i]) {
            //if (printline ) out << "| ";
            out << right.numbarr[i];
                printline = true;
        }
    }
    return out;
}

//Input Operator
std::istream& operator>>(std::istream& input, bigint& rhs) {
    char load[size];
    char ch;
    int i = 0;
        
        //finding out how many numbers are in sequence
        input.get(ch);
        if (ch != ';') {
            input >> load[i];
            std::cout << ch;
            input.get(ch);
            ++i;

        }
        else {
            load[0] = 0;
        }
    rhs = bigint(load);
    return input;

}

//Plus Operator
bigint bigint::operator+(const bigint& rhs) const{
    bigint result;
    bool carry = false;
    for (int i = 0; i < size; ++i){
        result.numbarr[i] = numbarr[i] + rhs.numbarr[i];
        //Carry
        if (carry == true) {
            result.numbarr[i] = result.numbarr[i] + 1;
        }
        if (result.numbarr[i] >= 10) {
            result.numbarr[i] = result.numbarr[i] - 10;
            carry = true;
        }
        else {
            carry = false;
        }
    }
    return result;
}

char bigint::operator[](int i) const {
     return numbarr[i];
}

//Multiplication
bigint bigint::timesDigit(int number) const{
    bigint result;
    bool carry = false;
    int carrynum = 0;
    for (int i = 0; i < size; ++i){
        //Multiply number by each number in array
        result.numbarr[i] = numbarr[i] * number;
        //Carry
        if (carry == true) {
            result.numbarr[i] = result.numbarr[i] + carrynum;
        }
        if (result.numbarr[i] >= 10) {
            //NEED TO RESET THE CARRYNUM OR IT WILL GIVE WRONG OUTPUT
            carrynum = 0;
            //If the number is greater than 10, it will loop, subtracting 10 until the number is below 10
            //It will then (every time it loops) add one to the carry number which will add to the next number.
            while (result.numbarr[i] >= 10) {
                result.numbarr[i] = result.numbarr[i] - 10;
                carrynum = carrynum + 1;
                carry = true;
            }
        }
        else {
            carry = false;
        }
    }
    return result;
}

//Times 10
bigint bigint::times10(int number) const {
    bigint result;
    int place = number;
    
    for (int i = 0; i < size; ++i){
        if (i < number) {
            result.numbarr[i + place] = numbarr[i];
            result.numbarr[i] = 0;
        }
        else {
            result.numbarr[i + place] = numbarr[i];
        }
    }
    return result;
}

bigint bigint::operator*(const bigint& rhs) const{
     bigint multi;
     bigint product = 0;
    
    for (int i = 0; i < size - 1; ++i) {
        if (numbarr[i] != 0) {
            multi = rhs.timesDigit(numbarr[i]);
            product = product + multi.times10(i);
        }
    }
    return product;
}
