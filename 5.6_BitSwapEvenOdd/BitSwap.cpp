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
    
}
