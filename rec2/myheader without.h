#include <stdlib.h>
#include <time.h>
int rollDice(){
	int v1, v2;
	/*srand(time(NULL));*/
	v1 = rand()%5 + 1;
	v2 = rand()%5 + 1;
	return (v1 + v2);
}
