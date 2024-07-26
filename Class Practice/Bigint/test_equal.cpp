// bigint Test Program
//
// Tests:   ==, uses bigint(int)
//
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(0);
        // Test 
        assert(bi == 0);
        // Verify
        std::cout << "0 == ";
        std::cout << bi;
        std::cout << std::endl;
    }
    
    {
        // Setup
        bigint bi1(1234);
        bigint bi2(1234);
        // Test
        assert(bi1 == bi2);
        // Verify
        std::cout << bi1;
        std::cout << " == ";
        std::cout << bi2;
        std::cout << std::endl;
    }

    {
        // Setup
        bigint bi1(1234);
        bigint bi2(234);
        // Test
        assert(!(bi1 == bi2));
        // Verify
        std::cout << bi1;
        std::cout << " != ";
        std::cout << bi2;
        std::cout << std::endl;
    }

    {
        // Setup
        bigint bi1(1234);
        bigint bi2(123);
        // Test
        assert(!(bi1 == bi2));
        // Verify
        std::cout << bi1;
        std::cout << " != ";
        std::cout << bi2;
        std::cout << std::endl;
    }
    {
        // Setup
        bigint bi1(123);
        bigint bi2(1234);
        // Test
        assert(!(bi1 == bi2));
        // Verify
        std::cout << bi1;
        std::cout << " != ";
        std::cout << bi2;
        std::cout << std::endl;
    }

    //Added by me
    ///////////////////////////////////////////////////////////////////////
    {
        // Setup
        bigint bi1("1039485015810495815098");
        bigint bi2("1039485015810495815098");
        // Test
        assert((bi1 == bi2));
        // Verify
        std::cout << bi1;
        std::cout << " == ";
        std::cout << bi2;
        std::cout << std::endl;
    }



    {
        // Setup
        bigint bi1("10394850158104958150980");
        bigint bi2("1039485015810495815098");
        // Test
        assert(!(bi1 == bi2));
        // Verify
        std::cout << bi1;
        std::cout << " != ";
        std::cout << bi2;
        std::cout << std::endl;
    }

    {
        // Setup
        bigint bi1("");
        bigint bi2("");
        // Test
        assert((bi1 == bi2));
        // Verify
        std::cout << bi1;
        std::cout << " == ";
        std::cout << bi2;
        std::cout << std::endl;
    }

    {
        // Setup
        bigint bi1("123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960");
        bigint bi2("123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960");
        // Test
        assert((bi1 == bi2));
        // Verify
        std::cout << bi1;
        std::cout << " == ";
        std::cout << bi2;
        std::cout << std::endl;
    }

    //Testing bigint with 600 characters
    {
        // Setup
        bigint bi1("123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960240395703295470129571043957130495873409186016534985619571409571349571395798013759017345103451956139547816598136958365813678591374659813653897561398467519387561983756139847561389569147561934587632856238456238951356713450365626523904562365987465189374561398563025613058103957301945713948571398456346139874561375913875913468539178406304895719340571985743958643871561390851305987139058316534795061347138946713980467130946871747613409867134907139076430896713940671384096788");
        bigint bi2("123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960240395703295470129571043957130495873409186016534985619571409571349571395798013759017345103451956139547816598136958365813678591374659813653897561398467519387561983756139847561389569147561934587632856238456238951356713450365626523904562365987465189374561398563025613058103957301945713948571398456346139874561375913875913468539178406304895719340571985743958643871561390851305987139058316534795061347138946713980467130946871747613409867134907139076430896713940671384096788");
        // Test
        assert((bi1 == bi2));
        // Verify
        std::cout << bi1;
        std::cout << " == ";
        std::cout << bi2;
        std::cout << std::endl;
    }

    {
        // Setup
        bigint bi1("1234567891011121314151617181920212223242526272829303132333435363738394041424344454647error051525354555657585960240395703295470129571043957130495873409186016534985619571409571349571395798013759017345103451956139547816598136958365813678591374659813653897561398467519387561983756139847561389569147561934587632856238456238951356713450365626523904562365987465189374561398563025613058103957301945713948571398456346139874561375913875913468539178406304895719340571985743958643871561390851305987139058316534795061347138946713980467130946871747613409867134907139076430896713940671384096788");
        bigint bi2("123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960240395703295470129571043957130495873409186016534985619571409571349571395798013759017345103451956139547816598136958365813678591374659813653897561398467519387561983756139847561389569147561934587632856238456238951356713450365626523904562365987465189374561398563025613058103957301945713948571398456346139874561375913875913468539178406304895719340571985743958643871561390851305987139058316534795061347138946713980467130946871747613409867134907139076430896713940671384096788");
        // Test
        assert(!(bi1 == bi2));
        // Verify
        std::cout << bi1;
        std::cout << " != ";
        std::cout << bi2;
        std::cout << std::endl;
    }

    
    std::cout << "Done testing ==." << std::endl;
    return 0;
}

