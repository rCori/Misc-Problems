/* PowerOfTwo.cpp
 * Simple display to show my answer to question 5.4 in Cracking
 * The Coding Interview:
 * Explain what the following code does:
 * ((n&(n-1))==0)
 * The answer is it determines if n is a power of 2 
 * Author: Ryan Cori
 * Date: 11/23/15
 */


/* Explanation:
 * The condition is if a number is ANDed with itself -1 is 
 * 0. The result of an AND is 0 if and only if there is no bit
 * set to 1 int he same position between the two numbers. That
 * means for every valid bit i in numbers a and b, there is no
 * i where a[i] == 1 && b[i] == 1.
 * For n and n-1, this is only true if the binary representation
 * of n has only a single 1 followed by any number of 0s. Since
 * every binary bit represents a power of two, the only time this
 * is true for n is when n is a power of 2
 */
#include <iostream>

bool IsPowerOfTwo(int n){
    return ((n&(n-1))==0);
}

//Small wrapper for testing the function with console output
bool TestPowerOfTwo(int n, bool expected){
    //Make return test success flag
    bool testSuccess = false;
    std::cout << "Testing IsPowerOfTwo" << std::endl;
    bool result = IsPowerOfTwo(n);
    std::cout << "Expect that n=" << n << " as a power of 2 is "
        << std::boolalpha << expected << std::endl;;
    //print test results
    if(result == expected){
        std::cout << "Test success" << std::endl;
        testSuccess = true;
    }
    else{
        std::cout << "Test has failed" << std::endl;
    }
    return testSuccess;
}

int main(int argc, char** argv){
    bool totalSuccess = true;
    //Test some numbers for being powers of 2
    //First do actual powers of two
    totalSuccess &= TestPowerOfTwo(1,true); 
    totalSuccess &= TestPowerOfTwo(2,true);
    totalSuccess &= TestPowerOfTwo(4,true);
    totalSuccess &= TestPowerOfTwo(8,true);
    totalSuccess &= TestPowerOfTwo(16,true);
    //Second try numbers that are no powers of 2
    totalSuccess &= TestPowerOfTwo(3, false);
    totalSuccess &= TestPowerOfTwo(5, false);
    totalSuccess &= TestPowerOfTwo(6, false);
    totalSuccess &= TestPowerOfTwo(7, false);

    //Print if all tests are successful
    if(totalSuccess){
        std::cout << "All tests passed" << std::endl;
    }
    else{
        std::cout << "Some tests have failed" <<std::endl;
    }
}


