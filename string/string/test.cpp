// Tests: split, uses ==
//
/*
#include <iostream>
#include <cassert>
#include <vector>
#include "string.hpp"

//===========================================================================
int main () {
        {
            
            String s = "abc ef gh";
            std::vector<String> result1 = s.split(' ');
            assert(result1[0] == "abc");
            assert(result1[1] == "ef");
            assert(result1[2] == "gh");
        }
        {
            String s = "-a--b-";
            std::vector<String> result2 = s.split('-');
            assert(result2[0] == "");
            assert(result2[1] == "a");
            assert(result2[2] == "");
            assert(result2[3] == "b");
            assert(result2[4] == "");
        }
        {
            String s = "--";
            std::vector<String> result2 = s.split('-');
            assert(result2[0] == "");
            assert(result2[1] == "");
        }
        {
            String s = ".";
            std::vector<String> result2 = s.split('.');
            assert(result2[0] == "");
        }
        {
            String s = "When I go to the store I ride by horse";
            std::vector<String> result2 = s.split(' ');
            assert(result2[0] == "When");
            assert(result2[1] == "I");
            assert(result2[2] == "go");
            assert(result2[3] == "to");
            assert(result2[4] == "the");
            assert(result2[5] == "store");
            assert(result2[6] == "I");
            assert(result2[7] == "ride");
            assert(result2[8] == "by");
            assert(result2[9] == "horse");
        }
        {
            String s = "--------------";
            std::vector<String> result2 = s.split('-');
            assert(result2[0] == "");
            assert(result2[1] == "");
            assert(result2[2] == "");
            assert(result2[3] == "");
            assert(result2[4] == "");
            assert(result2[5] == "");
            assert(result2[6] == "");
            assert(result2[7] == "");
            assert(result2[8] == "");
            assert(result2[9] == "");
            assert(result2[10] == "");
            assert(result2[11] == "");
            assert(result2[12] == "");
            assert(result2[13] == "");
        }
        {
            String s = "-abx-";
            std::vector<String> result2 = s.split('-');
            assert(result2[0] == "");
            assert(result2[1] == "abx");
            assert(result2[2] == "");
        }
        {
            String s = "-abx-";
            std::vector<String> result2 = s.split('-');
            assert(result2[0] == "");
            assert(result2[1] == "abx");
            assert(result2[2] == "");
        }
        {
            String s = "-a--b--x--";
            std::vector<String> result2 = s.split('-');
            assert(result2[0] == "");
            assert(result2[1] == "a");
            assert(result2[2] == "");
            assert(result2[3] == "b");
            assert(result2[4] == "");
            assert(result2[5] == "x");
            assert(result2[6] == "");
        }
        {
            String s = "-a-b-x-";
            std::vector<String> result2 = s.split('-');
            assert(result2[0] == "");
            assert(result2[1] == "a");
            assert(result2[2] == "b");
            assert(result2[3] == "x");
            assert(result2[4] == "");
        }
        {
            String s = "WhenaIagotathis";
            std::vector<String> result2 = s.split('a');
            assert(result2[0] == "When");
            assert(result2[1] == "I");
            assert(result2[2] == "got");
            assert(result2[3] == "this");
        }
        {
            String s = "131.123.47.176 - - [18/Sep/2002:12:05:25 -0400] GET /~darci/ HTTP/1.0 200 5625";
            std::vector<String> result2 = s.split('.');
            assert(result2[0] == "131");
            assert(result2[1] == "123");
            assert(result2[2] == "47");
            assert(result2[3] == "176 - - [18/Sep/2002:12:05:25 -0400] GET /~darci/ HTTP/1");
        }
        
           std::cout << "Done testing split" << std::endl;
        return 0;
    }


       
    */

