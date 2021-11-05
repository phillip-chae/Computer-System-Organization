#include <stdio.h>
#include "myheader.h"
#include <stdlib.h>
int main(){
	int i;
	for(i = 0; i < 100000; i++){
		printf("%d ", rollDice());
	}
	return 0;
}
