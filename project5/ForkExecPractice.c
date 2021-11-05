#include <unistd.h> 
#include <sys/types.h> 
#include <errno.h> 
#include <stdio.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
#include<time.h>
//Author: Phillip Chae
//
//Initializing variables here so that hanle_sigint doesnt result error 
pid_t pid;
int mque = 0;
int timesup = 0;
//Dictates what ForkPractice.c will do when it receives a Signal Interrupt from ProcessPractice
void handle_sigint(int sig){
	printf("Time is up!\n");
	mque++;
	timesup = 1;
}
//Description: Gets 
int main(int argc, char **argv)
{
	srand(time(NULL));
	int i, j, k;
	printf("How many questions would you like?");
	scanf("%d", &k);
	//Make array of random integers to perform operations on
	int rn[2*k];
	for(j = 0; j < 2*k; j++){
		rn[j] = rand()%10 + 1;
	}
	//Make array of random integers that will decide what the operation will be
	int ro[k];
	for(j = 0; j < k; j++){
		ro[j] = rand()%3;
	}
	//Counters of each possibility in answering
  	int cans = 0; int ians = 0;  
  	int child_status;
	int ans, num, timesup;
	//Loop for the number of questions that the user asked for
	for(i = 0; i < k; i ++){
		timesup = 0;
		pid = fork();
		if (pid == 0) {
    			pid= execve("ProcessPractice",NULL, NULL);
     		}
		//If statements for different operations
		if(ro[i] == 0){
			ans = rn[2*i] + rn[2*i + 1];
			printf("What is %d + %d", rn[2*i], rn[2*i + 1]);
		}
		if(ro[i] == 1){
                        ans = rn[2*i] - rn[2*i + 1];
                        printf("What is %d - %d", rn[2*i], rn[2*i + 1]);
                }
		if(ro[i] == 2){
                        ans = rn[2*i] * rn[2*i + 1];
                        printf("What is %d * %d", rn[2*i], rn[2*i + 1]);
                }
		//Check if the answer input is correct or incorrect, and break if the 5 second time limit passes
		while(timesup == 0){
			scanf("%d", &num);
                	signal(SIGINT,handle_sigint);
   			if (num==ans){
           			printf("You win                    \n" );
				cans++;
           			kill(pid, SIGKILL);
				break;
      			}
			 else if (num==0) {
               			kill(pid, SIGINT);
               			printf("%i resetting time       ",num);     
               			printf("\r\b\r");  
       			}
			else if (timesup == 1){
				printf("Times up!!");
				break;
			}
			else {
                   		printf("%i incorrect - try again ",num);
				ians++;  
                   		printf("\r\b\r");
             		}
      
   		}
   	}
	printf(" You had %d correct answers, %d incorrect answers, and %d missed questions.\n", cans, ians, mque);
	return(0);	
}

  
