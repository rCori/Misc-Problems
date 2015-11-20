/*ReverseFunction.tpp
 * purpose of this file is to implement the
 * template functions defined in ReverseFunction.h
 * It will be included in the .h file at the end so
 * the compiler can generate definitions of the function
 * as needed at compile time.
 */


#include <assert.h>
#include <cstddef>

//Swap two values in an array of any type
template<typename T> 
void swapInArray(T* inputArray, int x, int y){
    //First do some bounds checking on the array to
    //make sure what we are swapping is valid.
    //First get the array bounds. This is a hacky way
    //of doing it that relies on the next unallocated element
    //after the array ends is null
    unsigned int arraySize = 0;
    //suppress a warning
    #pragma GCC diagnostic ignored "-Wpointer-arith"
    for(unsigned int i = 0; inputArray[i] != NULL; i++){
        arraySize++;
    }
    //Now make assertions that x and y fall within
    //the array bounds
    assert(x >= 0);
    assert(x < arraySize);
    assert(y >= 0);
    assert(y < arraySize);
    //Now create a temp and use it to do the standard swap
    T temp;
    temp = inputArray[x];
    inputArray[x] = inputArray[y];
    inputArray[y] = temp;
    //Now we are done, return
    return;
}
