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
        bi = bi.times10(1);

        // Verify
        assert(bi == 30);  
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test
        bi = bi.times10(2);

        // Verify
        assert(bi == 300);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(387);

        // Test
        bi = bi.times10(3);

        // Verify
        assert(bi == 387000);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(987654321);

        // Test
        bi = bi.times10(1);

        // Verify
        assert(bi == "9876543210");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(8473);

        // Test
        bi = bi.times10(5);

        // Verify
        assert(bi == "847300000");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("02457345783057380535908345");

        // Test
        bi = bi.times10(14);

        // Verify
        assert(bi == "0245734578305738053590834500000000000000");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(7);

        // Test
        bi = bi.times10(30);

        // Verify
        assert(bi == "7000000000000000000000000000000");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1);

        // Test
        bi = bi.times10(100);

        // Verify
        assert(bi == "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("102398104983402984123490813242");

        // Test
        bi = bi.times10(4);

        // Verify
        assert(bi == "1023981049834029841234908132420000");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(30);

        // Test
        bi = bi.times10(10);

        // Verify
        assert(bi == "300000000000");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("9385748957358943758937598345739857982375824759824759847598237498274598235743982572985");

        // Test
        bi = bi.times10(415);

        // Verify
        assert(bi == "93857489573589437589375983457398579823758247598247598475982374982745982357439825729850000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    }
  

    std::cout << "Done testing times_10" << std::endl;
    return 0;
}



