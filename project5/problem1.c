#include <stdio.h>
#include <time.h>
int main(){
	//The sin
	clock_t t;
	FILE *fp;
	int sum, i, l, temp, number = 0;
	int prime;
	t = time(NULL);
	for(i = 1; i <100001; i++){
		sum = 0;
		temp = i;
		prime = 1;
		while(temp > 0){
			sum += temp%10;
			temp /= 10;
		}
		for(l = 2; l < i/2; l++){
			if (i%l == 0){
				prime = 0;
				break;
			}
		}
		if (sum == 11 && prime == 1){
			fp = fopen("problem1.txt", "w");
			fprintf(fp, "%d ", i);
			number++;
			fclose(fp);
		}
	}
	t = time(NULL) - t + 1;
	printf("%f seconds elapsed for program to execute\n", (double)t);
	
	//The fork processin
	int j, k;
	t = time(NULL);
        for(i = 0; i <10; i++){
		if(fork() == 0){
			k = (i + 1)*10000;
			for(j = i*10000 + 1; j < k; j++){
                		sum = 0;
                		temp = i;
                		while(temp > 0){
                        		sum += temp%10;
                        		temp /= 10;
                		}
				for(l = 2; l < i/2; l++){
                        		if (i%l == 0){
						prime = 0;
						break;
					}
                		}
                		if (sum == 11 && prime == 1){
                        		fp = fopen("problem1.txt", "w");
                        		fprintf(fp, "%d ", i);
                        		fclose(fp);
                		}
			}
			exit(0);
		}
        }
        t = time(NULL) - t + 1;
        printf("%f seconds elapsed for program to execute\n", (double)t);
}
