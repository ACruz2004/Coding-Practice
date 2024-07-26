// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test
        bi = bi.timesDigit(4);

        // Verify
        assert(bi == 12);  //Will FAIL, fix and add test cases.
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        //Testing Carry
        bigint bi(30);

        // Test
        bi = bi.timesDigit(5);

        // Verify
        assert(bi == 150);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        //Testing Carry
        bigint bi(12);

        // Test
        bi = bi.timesDigit(62);

        // Verify
        assert(bi == 744);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        //Testing Carry
        bigint bi(125);

        // Test
        bi = bi.timesDigit(62);

        // Verify
        assert(bi == 7750);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        //Testing Carry
        bigint bi(999);

        // Test
        bi = bi.timesDigit(999);

        // Verify
        assert(bi == 998001);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        //Testing Carry
        bigint bi("6464378461");

        // Test
        bi = bi.timesDigit(2);

        // Verify
        assert(bi == "12928756922");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        //Testing Carry
        bigint bi("6464378461");

        // Test
        bi = bi.timesDigit(230);

        // Verify
        assert(bi == "1486807046030");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        //Testing Carry
        bigint bi("1234567891011121314151617181920");

        // Test
        bi = bi.timesDigit(12345);

        // Verify
        assert(bi == "15240740614532292623201714110802400");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        //Testing Carry
        bigint bi("12345678910111213141516171819201234567891011121314151617181920");

        // Test
        bi = bi.timesDigit(123456789);

        // Verify
        assert(bi == "1524157876267350007346189164370872964587626735000734618916437072054880");
    }
    //Add test cases as needed.
    
    std::cout << "Done testing bigint * digit" << std::endl;
    return 0;
}
