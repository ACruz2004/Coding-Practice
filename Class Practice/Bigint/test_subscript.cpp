// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(800);

        // Test 
        bigint digit = bi[0];

        // Verify
        assert(bi    == 800);
        assert(digit == 0);

        digit = bi[1];
        assert(bi    == 800);
        assert(digit == 0);
        
        digit = bi[2];
        assert(bi    == 800);
        assert(digit == 8);


    }
    
    {
        // Setup
        bigint bi(123);

        // Test 
        bigint digit = bi[0];

        // Verify
        assert(bi    == 123);
        assert(digit == 3);

        digit = bi[1];
        assert(bi    == 123);
        assert(digit == 2);
        
        digit = bi[2];
        assert(bi    == 123);
        assert(digit == 1);


    }

    {
        // Setup
        bigint bi(31415);

        // Test 
        bigint digit = bi[0];

        // Verify
        assert(bi    == 31415);
        assert(digit == 5);

        digit = bi[1];
        assert(bi    == 31415);
        assert(digit == 1);
        
        digit = bi[2];
        assert(bi    == 31415);
        assert(digit == 4);

        digit = bi[4];
        assert(bi    == 31415);
        assert(digit == 3);

        digit = bi[3];
        assert(bi    == 31415);
        assert(digit == 1);


    }

    {
        // Setup
        bigint bi(100);

        // Test 
        bigint digit = bi[0];

        // Verify
        assert(bi    == 100);
        assert(digit == 0);

        digit = bi[1];
        assert(bi    == 100);
        assert(digit == 0);
        
        digit = bi[2];
        assert(bi    == 100);
        assert(digit == 1);


    }

    {
        // Setup
        bigint bi(991);

        // Test 
        bigint digit = bi[0];

        // Verify
        assert(bi    == 991);
        assert(digit == 1);

        digit = bi[1];
        assert(bi    == 991);
        assert(digit == 9);
        
        digit = bi[2];
        assert(bi    == 991);
        assert(digit == 9);


    }

    {
        // Setup
        bigint bi(4321);

        // Test 
        bigint digit = bi[0];

        // Verify
        assert(bi    == 4321);
        assert(digit == 1);

        digit = bi[1];
        assert(bi    == 4321);
        assert(digit == 2);
        
        digit = bi[2];
        assert(bi    == 4321);
        assert(digit == 3);

        digit = bi[3];
        assert(bi    == 4321);
        assert(digit == 4);


    }

    {
        // Setup
        bigint bi(8675);

        // Test 
        bigint digit = bi[0];

        // Verify
        assert(!(bi    == 309));
        assert(digit == 5);

        digit = bi[1];
        assert(bi    == 8675);
        assert(digit == 7);
        
        digit = bi[3];
        assert(bi    == 8675);
        assert(digit == 8);


    }

    //TEST WITH NOTHING IN THE BIGINTg
    { 
        // Setup
        bigint bi("");

        // Test 
        bigint digit = bi[0];

        // Verify
        assert(bi == 0);
        assert(digit == 0);



    }

    {
        // Setup
        bigint bi("9876543210");

        // Test 
        bigint digit = bi[0];

        // Verify
        assert(bi    == "9876543210");
        assert(digit == 0);

        digit = bi[1];
        assert(bi    == "9876543210");
        assert(digit == 1);
        
        digit = bi[2];
        assert(bi    == "9876543210");
        assert(digit == 2);

        digit = bi[3];
        assert(bi    == "9876543210");
        assert(digit == 3);
        
        digit = bi[4];
        assert(bi    == "9876543210");
        assert(digit == 4);

        digit = bi[5];
        assert(bi    == "9876543210");
        assert(digit == 5);
        
        digit = bi[6];
        assert(bi    == "9876543210");
        assert(digit == 6);

        digit = bi[7];
        assert(bi    == "9876543210");
        assert(digit == 7);
        
        digit = bi[8];
        assert(bi    == "9876543210");
        assert(digit == 8);

        digit = bi[9];
        assert(bi    == "9876543210");
        assert(digit == 9);
        
    }

    {
        // Setup
        bigint bi("0123456789");

        // Test 
        bigint digit = bi[0];

        // Verify
        assert(bi    == "0123456789");
        assert(digit == 9);

        digit = bi[1];
        assert(bi    == "0123456789");
        assert(digit == 8);
        
        digit = bi[2];
        assert(bi    == "0123456789");
        assert(digit == 7);

        digit = bi[3];
        assert(bi    == "0123456789");
        assert(digit == 6);
        
        digit = bi[4];
        assert(bi    == "0123456789");
        assert(digit == 5);

        digit = bi[5];
        assert(bi    == "0123456789");
        assert(digit == 4);
        
        digit = bi[6];
        assert(bi    == "0123456789");
        assert(digit == 3);

        digit = bi[7];
        assert(bi    == "0123456789");
        assert(digit == 2);
        
        digit = bi[8];
        assert(bi    == "0123456789");
        assert(digit == 1);

        digit = bi[9];
        assert(bi    == "0123456789");
        assert(digit == 0);
        
    }

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

