#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "float.h"

//Author: Phillip Chae
//Purpose of program: Disassemble float values into their respective sign, exponent, and mantissa values and return them.

int is_special ( float f ) 
{
   //Returns 1 if it is a special float, which is NaN and INFINITY and 0 otherwise
	if (isnan(f) || isinf(f)) return 1;
    	return 0;
}

//Returns the mantissa of the float
float get_M  ( float f ) 
{
   //If special value, return respective mantissa
	if(isinf(f)) return 0.0;
	if(isnan(f)) return 0.5;
   //Otherwise, use formula from float, sign, and exponent to calculate and return;
	return f / get_s(f) / pow(2, get_E(f));	
}

//Returns sign of the float
int get_s ( float f ) {	
   //Set an unsigned int pointer to the float
	unsigned int* p = (unsigned int*)&f;
   //Shift all the other values except the sign position to right so that *p now only contains the sign
   *p = *p >>31;
   //Interpret the sign binary value
	if (*p == 0) return 1;
	return -1;
}

//Return the exponent of the float
int get_E ( float f )
{	
   //Check if f is special number and return respective value
	if(isnan(f) || isinf(f)) return 255;
   //Otherwise start normal function
	int counter = 0;
   //n is f without its sign values.
	float n = f/get_s(f); 
   //Categorize if number is positive exponent or negative exponent
	if(n > 1){
		n = n/2;
		while(n>=1){
			n = n/2;
         //This is technically the exponent value as you are dividing by two per exponent
			counter++;
         //Break when it is greater than 127 as memory storage for exponent only goes up to 127
			if(counter >= 127) break;
		}
		return counter;
	}
	if(n < 1){
                while(n<1){
                        n = n*2;
         //Break for same reason as previous except below
			if(counter <= -126) break;
                        counter--;
                }
		return counter;
        }
   //Return 0 if f = 0
	return 0;
}
