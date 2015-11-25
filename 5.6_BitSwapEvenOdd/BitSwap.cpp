/* BitSwap.cpp
 * Implement a solution to problem 5.6 in Cracking the Coding
 * interview. The question is:
 * Write a function to swap odd and even bits in an integer
 * with as few instructions as possible (eg, bit 0 and bit 1
 * are swapped and so on). The only solution I and the book could
 * come up with operates of a fixed bit length integer. I will
 * be using 32 integers here.
 * Author: Ryan Cori
 * Date: 11/24/15
 */

#include <stdint.h>
#include <iostream>

//Function to return an int where the even and odd bits have
//swapped positions from the input int
int32_t BitSwapEvenOdd(int32_t num){
    //declare an int to return
    int32_t returnInt = -1;
    //Shift right for the odd bit mask
    int32_t rightShift = num >> 1;
    //Shift left for the even bit mask
    int32_t leftShift = num << 1;
    //Make odd bitmask
    //0101 = 5
    int32_t oddBitmask = 0x55555555;
    //Make even bitmask
    //1010 = a
    int32_t evenBitmask = 0xaaaaaaaa;
    returnInt = (rightShift & oddBitmask) | (leftShift & evenBitmask);
    return returnInt;
}

//Function for testing results of BitSwapEvenOdd
bool TestBitSwap(int32_t input, int32_t expected){
    //Create test result boolean flag
    bool testResult = false;
    //State what the test is
    std::cout << "Testing BitSwapEvenOdd" << std::endl;
    //Print the input and expected value
    std::cout << "Input value is " << input << " and the"
        " expected output is " << expected << std::endl;
    int32_t result = BitSwapEvenOdd(input);
    //Print the result
    std::cout << "Result is " << result << std::endl;
    //Successful test
    if(expected == result){
        std::cout << "Test pass" << std::endl;
        testResult = true;
    }
    //failed test
    else{
        std::cout << "Test fail" << std::endl;
    }
    //return test result
    return testResult;
}

int main(int argc, char** argv){
    //Start testing BitSwapEvenOdd
    bool allTestsPass = true;

    //22     = 0x00 00 00 00 00 01 01 10
    //41     = 0x00 00 00 00 00 10 10 01
    allTestsPass &= TestBitSwap(22,41);
    
    // 1161  = 0x00 00 01 00 10 00 10 01
    // 2118  = 0x00 00 10 00 01 00 01 10
    allTestsPass &= TestBitSwap(1161 , 2118);

    // 8237  = 0x00 10 00 00 00 10 11 01
    // 4126  = 0x00 01 00 00 00 01 11 10
    allTestsPass &= TestBitSwap(8237, 4126); 

    // 729   = 0x00 00 00 10 11 01 10 01
    // 486   = 0x00 00 00 01 11 10 01 10
    allTestsPass &= TestBitSwap(729, 486);

    // 19886 = 0x01 00 11 01 10 10 11 10
    // 36445 = 0x10 00 11 10 01 01 11 01
    allTestsPass &= TestBitSwap(19886, 36445);

    // 341   = 0x00 00 00 01 01 01 01 01
    // 682   = 0x00 00 00 10 10 10 10 10
    allTestsPass &= TestBitSwap(341, 682);

    //Print message for all tests passing or not
    if(allTestsPass){
        std::cout << "All tests have passed" << std::endl;
    }
    else{
        std::cout << "Some tests have failed" << std::endl;
    } 
}
