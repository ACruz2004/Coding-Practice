// bigint Test Program
//
// Tests:  multiply, uses ==
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(1);
        bigint right(0);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == 1);
        assert(right  == 0);
        assert(result == 0);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(1);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == 0);
        assert(right  == 1);
        assert(result == 0);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(123);
        bigint right(56);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   ==  123);
        assert(right  ==   56);
        assert(result == 6888);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(65);
        bigint right(321);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   ==    65);
        assert(right  ==   321);
        assert(result == 20865);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(9999);
        bigint right(2);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   ==  9999);
        assert(right  ==     2);
        assert(result == 19998);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(2);
        bigint right(999999);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   ==       2);
        assert(right  ==  999999);
        assert(result == 1999998);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(99);
        bigint right(99);
        bigint result;

        // Test
        result = left * right;

        // Verify
        assert(left   ==  99);
        assert(right  ==  99);
        assert(result ==  9801);
    }


    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("2222");
        bigint right("888888888888888888888888888888888888");
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "2222");
        assert(right  == "888888888888888888888888888888888888");
        assert(result == "1975111111111111111111111111111111109136");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("777777777777777777777777777777777777777777777");
        bigint right("333333");
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "777777777777777777777777777777777777777777777");
        assert(right  == "333333");
        assert(result == "259258999999999999999999999999999999999999999740741");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("111111111111111111111111111111111111111111");
        bigint right("999999999999999999999999999999999999999999");
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "111111111111111111111111111111111111111111");
        assert(right  == "999999999999999999999999999999999999999999");
        assert(result == "111111111111111111111111111111111111111110888888888888888888888888888888888888888889");
    }
    
    //Add test cases as needed.
    //Added by me

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("11203981099072734098527345908713095739057093857109571903745908171509134709");
        bigint right(2);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "11203981099072734098527345908713095739057093857109571903745908171509134709");
        assert(right  == 2);
        assert(result == "22407962198145468197054691817426191478114187714219143807491816343018269418");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("20000000000034052709380942342304928409284209357237528903420948209328509574523986528974365987234659873246598273645987316458364587913649576134598136458193745613894568723945613849561387346589736159834651938456138945761345");
        bigint right(14);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "20000000000034052709380942342304928409284209357237528903420948209328509574523986528974365987234659873246598273645987316458364587913649576134598136458193745613894568723945613849561387346589736159834651938456138945761345");
        assert(right  == 14);
        assert(result == "280000000000476737931333192792268997729978931001325404647893274930599134043335811405641123821285238225452375831043822430417104230791094065884373910414712438594523962135238593893859422852256306237685127138385945240658830");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(250);
        bigint right(2);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == 250);
        assert(right  == 2);
        assert(result == 500);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("111111111111111111111111111111111111111111");
        bigint right(1);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "111111111111111111111111111111111111111111");
        assert(right  == 1);
        assert(result == "111111111111111111111111111111111111111111");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("5273509283556138945619385613485976358973456981354698153534789011839571093457130948561345971349805713409586315983461908346715801375103485713904857130957138597134589013745");
        bigint right("999999999999999999999999999999999999999999");
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "5273509283556138945619385613485976358973456981354698153534789011839571093457130948561345971349805713409586315983461908346715801375103485713904857130957138597134589013745");
        assert(right  == "999999999999999999999999999999999999999999");
        assert(result == "5273509283556138945619385613485976358973451707845414597395843392453957607480771975104364616651652178620574476412368451215767240029132135908191447544641155135226242297943624896514286095142869042861402865410986255");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("4590353036467349693769877394698376760932760938276902876902876092834769028764903867930284672390469023894672093867293084769036209346782934769827390467209346790237469082734690872394672903476902834769820374698273649823674983147597134598137591835791034768913476891374698137649830167059813745198357494983475981364791834671930457918304759813761398476910374698013746");
        bigint right("94590353036467349693769877394698376760932760938276902876902876092834769028764903867930284672390469023894672093867293084769036209346782934769827390467209346790237469082734690872394672903476902834769820374698273649823674983147597134598137591835791034768913476891374698137649830167059813745198357494983475981364791834671930457918304759813761398476910374698013746");
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "4590353036467349693769877394698376760932760938276902876902876092834769028764903867930284672390469023894672093867293084769036209346782934769827390467209346790237469082734690872394672903476902834769820374698273649823674983147597134598137591835791034768913476891374698137649830167059813745198357494983475981364791834671930457918304759813761398476910374698013746");
        assert(right  == "94590353036467349693769877394698376760932760938276902876902876092834769028764903867930284672390469023894672093867293084769036209346782934769827390467209346790237469082734690872394672903476902834769820374698273649823674983147597134598137591835791034768913476891374698137649830167059813745198357494983475981364791834671930457918304759813761398476910374698013746");
        assert(result == "434203114281466489906847835227323634799300138791192519014849436572885932568796569196068338267521390605264294209007202604830992264125375267100745119371545401514444771018837126602388398507734120895584645058171216777745696690602375296901681070026215117951544902507624249782719252078801812048596884945151731236823459206572608750208278687032221194790448698945169866601912259714254601191056080148196870882157643741188485462179763082436197504329622987040650218188362251948542244354931112128594962125156095177699418228759857702450208825394248877429602328729319680280807408348269862737747568659634309570520287153514678998205421823090972384728482613984001753387722308809908644747465738539176295796921030953685811225197604952516");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("999999999999999999999999999999999999999999");
        bigint right("999999999999999999999999999999999999999999");
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "999999999999999999999999999999999999999999");
        assert(right  == "999999999999999999999999999999999999999999");
        assert(result == "999999999999999999999999999999999999999998000000000000000000000000000000000000000001");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("1234567891011121314151617181920");
        bigint right("1234567891011121314151617181920");
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "1234567891011121314151617181920");
        assert(right  == "1234567891011121314151617181920");
        assert(result == "1524157877515647915714744640673134422038842655613362374886400");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("20191817161514131211109876543210");
        bigint right("20191817161514131211109876543210");
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "20191817161514131211109876543210");
        assert(right  == "20191817161514131211109876543210");
        assert(result == "407709480284016586744252568985795380495074175109367778997104100");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("1983457189037508913750981379857130489571938750981375908137095713908457908347590813784957130984598634590314856018934758901374598346539845631986589364589137645983");
        bigint right("1983457189037508913750981379857130489571938750981375908137095713908457908347590813784957130984598634590314856018934758901374598346539845631986589364589137645983");
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "1983457189037508913750981379857130489571938750981375908137095713908457908347590813784957130984598634590314856018934758901374598346539845631986589364589137645983");
        assert(right  == "1983457189037508913750981379857130489571938750981375908137095713908457908347590813784957130984598634590314856018934758901374598346539845631986589364589137645983");
        assert(result == "3934102420744576370263336865976309084952438049421503931733662411767750852404087475675809135680321288907075381200566233502073006853585803171761923997048250983677507176729923948576363826094861000200936648080887268529732050550798686327024460847144975086889824594805898843069156230971513399039492867810733415538390636036289");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(500);
        bigint right(2);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == 500);
        assert(right  == 2);
        assert(result == 1000);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(12487);
        bigint right(234);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == 12487);
        assert(right  == 234);
        assert(result == "2921958");
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(42134);
        bigint right(234);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == 42134);
        assert(right  == 234);
        assert(result == "9859356");
    }

    std::cout << "Done testing multiply" << std::endl;
    return 0;
}