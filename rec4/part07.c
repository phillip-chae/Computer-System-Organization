#include <stdio.h>
#include <assert.h>
#include "util.h"

/*
Using the or operator is good for turning designated bits on.
*/

int main()
{
    short a = 0b1010000; // Binary 80

    /* TODO: Initialize 'mask' such that when 'a' is
       OR'ed with it turns the last three bits of 'a' on
       (bits that are on are equal to 1) and leaves the other
       bits unchanged. */
    short mask = 0b0000111;
    assert((a | mask) == 0b1010111);

    /* TODO: Initialize 'decimal_result' with a decimal
        number so that the assertion passes.  */
    short decimal_result = 87;
    assert((a | mask) == decimal_result);

    part_completed(7);

    return 0;
}
