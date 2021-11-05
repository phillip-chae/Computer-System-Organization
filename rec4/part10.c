#include <stdio.h>
#include <assert.h>
#include "util.h"

/*
Bitwise operators can also aid you in creating masks.
*/

/* TODO: Make a function flip_bit that takes the inputs (n, number)
         and then returns the number with the nth bit from the right flipped.
         (with the ones bit being the 0th bit)*/
int flip_bit(int n, int number)
{
    /* Hint: Use a bit shift in order to get your mask into place
             and then use the XOR operator in order to flip the desired bit. */
     int mask = 0b1;
     mask = mask << n;
     return (number ^ mask);   
}

int main()
{
    assert(flip_bit(0, 0) == 1);
    assert(flip_bit(1, 0) == 2);
    assert(flip_bit(2, 10) == 14);
    assert(flip_bit(2, 3) == 7);
    assert(flip_bit(4, 0) == 16);

    part_completed(10);

    return 0;
}
