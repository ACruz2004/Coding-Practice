// bigint Test Program
//
// Tests:  int constructor and output << operator.
//         uses ==
// 
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        //------------------------------------------------------
        // Test: Construct with 0
        // Setup fixture

        // Test 
        bigint bi(0);

        // Verify
        assert(bi == 0);
        std::cout << "0 == ";
        std::cout << bi;
        std::cout << std::endl;
        
    }

    {
        //------------------------------------------------------
        // Test: Construct with 1
        // Setup fixture

        // Test 
        bigint bi(1);

        // Verify
        assert(bi == 1);
        std::cout << "1 == ";
        std::cout << bi;
        std::cout << std::endl;
        
    }

    {
        //------------------------------------------------------
        // Test: Construct with 100000
        // Setup fixture

        // Test 
        bigint bi(100000);

        // Verify
        assert(bi == 100000);
        std::cout << "100000 == ";
        std::cout << bi;
        std::cout << std::endl;
        
    }


    {
        //------------------------------------------------------
        // Test: Construct with two-digit value
        // Setup fixture

        // Test 
        bigint bi(27);

        // Verify
        assert(bi == 27);
        std::cout << "27 ==  ";
        std::cout << bi;
        std::cout << std::endl;

        // Verify
        bi = bigint(5006);   //Check re-assignment.
        assert(bi == 5006);
        std::cout << "5006 ==  ";
        std::cout << bi;
        std::cout << std::endl;

    }

    {
        //------------------------------------------------------
        // Test: Construct with six-digit value
        // Setup fixture

        // Test 
        bigint bi(456789);

        // Verify
        assert(bi == 456789);
        std::cout << "456789 == " << bi << std::endl;
    }

    //Added by me

    {

        // Test 
        bigint bi(32449);

        // Verify
        assert(bi == 32449);
        std::cout << "32449 == " << bi << std::endl;
    }

    {
        // Test 
        bigint bi("");

        // Verify
        assert(bi == 0);
        std::cout << "  == " << bi << std::endl;
    }

    {

        // Test 
        bigint bi(45423);

        // Verify
        assert(bi == 45423);
        std::cout << "45423 == " << bi << std::endl;
    }

    {

        // Test 
        bigint bi(9999);

        // Verify
        assert(bi == 9999);
        std::cout << "9999 == " << bi << std::endl;
    }

    {

        // Test 
        bigint bi(110);

        // Verify
        assert(bi == 110);
        std::cout << "110 == " << bi << std::endl;
    }

    {

        // Test 
        bigint bi(12345);

        // Verify
        assert(bi == 12345);
        std::cout << "12345 == " << bi << std::endl;
    }

    {

        // Test 
        bigint bi(12345);

        // Verify
        assert(!(bi == 54321));
        std::cout << "54321 != " << bi << std::endl;
    }

    {

        // Test 
        bigint bi(935);

        // Verify
        assert(bi == 935);
        std::cout << "935 == " << bi << std::endl;
    }

    {

        // Test 
        bigint bi(123456);

        // Verify
        assert(bi == 123456);
        std::cout << "123456 == " << bi << std::endl;
    }

    {

        // Test 
        bigint bi(98765);

        // Verify
        assert(bi == 98765);
        std::cout << "98765 == " << bi << std::endl;
    }

    {

        // Test 
        bigint bi(102030);

        // Verify
        assert(bi == 102030);
        std::cout << "102030 == " << bi << std::endl;
    }
    
    std::cout << "Done testing constructor bigint(int)." << std::endl;

    return 0;
}
