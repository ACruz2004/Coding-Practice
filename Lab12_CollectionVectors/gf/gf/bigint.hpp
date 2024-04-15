
#ifndef bigint_h
#define bigint_h

#include <cassert>
#include <iostream>
//bigint.hpp
const int size = 500;

class bigint {
    public:
    bigint();
    bigint(int);
    bigint(const char[]);
    
    void debugPrint(std::ostream& out) const;
    //int  capacity()  const {return size - 1;}
    int  length()    const;
    
    //overload output operator
    friend std::ostream& operator<<(std::ostream&, const bigint& right);
    //Overload Input
    friend std::istream& operator>>(std::istream&, bigint&);
    //Comparison Operator
    bool    operator==  (const bigint&) const;
    bigint  operator+   (const bigint&) const;
    bigint  operator*   (const bigint&) const;
    char    operator[]  (int) const;
    bigint  timesDigit(int) const;
    bigint  times10(int) const;
    private:
    int numbarr[size];
    int digits;
};


    


#endif
