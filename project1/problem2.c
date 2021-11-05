#include <stdio.h>
int main(){
	int i, n;
	int R, G, B;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d, %d, %d", &R, &G, &B);
		if(R < 0 || R > 255 || G < 0 || G > 255 || B < 0 || B > 255)
			printf("INVALID VALUES\n");
		else
			printf("#%02x%02x%02x\n", R,G,B);
	}
	return 0;
}
