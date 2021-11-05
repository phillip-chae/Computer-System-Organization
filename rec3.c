#include <stdio.h>

void swapref(int*, int*);

int main(){
	/*Initialization of all necessary variables*/
	int a, b, x, y, temp;

	/*Processes to swap references*/
	printf("Enter x and y value for swapping reference: \n");
	scanf("%d%d", &x, &y);

	printf("Before swapping reference:\nx = %d\ny = %d\n", x, y);
	swapref(&x,&y);
	printf("After swapping referece:\nx = %d\ny = %d\n", x, y);

	/* Processes to swap values*/
	printf("Enter a and b value for swapping values:\n");
	scanf("%d%d", &a, &b);

	printf("Before swapping values:\na = %d\nb = %d\n", a, b);
	temp = a;
	a = b;
	b = temp;
	printf("After swapping values:\na = %d\nb = %d\n", a, b);

	return 0;
}
void swapref(int *a, int *b){
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}
