#include <stdio.h>
#include "myheader.h"
#include <stdbool.h>

int main(){
	int i;
	bool pos = true;
	int win = 0;
	int loss = 0; 
	int val, counter;
	for(i = 0; i < 1000; i++){
		val = rollDice();
		counter = 0;
		if(val == 7){
			win++;
		}
		else{
			while(pos){
				if (val == rollDice()){
					win++;
					break;
				}
				if (rollDice() == 7){
					loss++;
					break;
				
				}
			}
		}
	}
	printf("Number of wins: %d\n", win);
	printf("Number of losses: %d\n", loss);
	return 0;
}
