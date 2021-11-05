/*
Steps:
1.) Input numerical text
2.) Divide the number into two parts an, bn, which adds up to the original number.
   -Convert this into indices list where only 1's are recorded while 0 is not. In this list,
   -an format: i1, i3, ...
   -bn format: i2, i4, ... where i1 is the smallest 1. 
3.) Output the two numbers an and bn in decimal format.
*/

#include <stdio.h>
int * compress(int n){
	int i, j, twomax, counter;
	//The array that will be a binary representation
	int bin[31];
	//The array that will be all location of 1's in bin
	static int compr[31];

	//Fills bin with zeroes
	for(i = 0; i < sizeof(bin); i++){
		bin[i] = 0;
	}
	//Result a binary array and subtract n to 0
	while(n>0){
		twomax = 1;
		counter = 0;
		while(twomax < n/2){
			twomax*=2;
			counter++;
		}
		n-=twomax;
		bin[counter] = 1;
	}
	//Results in comp array with all the location of 1's
	j = 0;
	for(i = 0; i < sizeof(bin); i++){
		if(bin[i] == 1){
			compr[j] = i;
			j++;
		}
	}
	return compr;
}
	
int main(){
	int n, a, b, i, j, tm;
	int *comp;
	
	//for until no new line
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		comp = compress(n);
		a = 0;
		b = 0;
		//Add up the a value;
		for(i = 0; i < sizeof(comp); i+=2){
			tm = 1;
			j = 0;
			while(j < comp[i]){
				tm*=2;
				j++;
			}
			a+=tm;
		}
		//Add up the b value
		for(i = 1; i < sizeof(comp); i+=2){
                        tm = 1;
                        j = 0;
                        while(j < comp[i]){
                                tm*=2;
                                j++;
                        }
                        b+=tm;
                }
		printf("%d %d\n", a, b);	
	}
	return 0;
}
