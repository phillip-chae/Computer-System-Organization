#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h> 
#include <sys/wait.h>
#include <stdlib.h> 
#include<signal.h>
//Author Phillip Chae
 
//Initialization here so that handle_sigint does not give error
int secs=0;
pid_t ppid;
//When receiving a Signal Interrupt by ForkProcessPractice, make sec = 0 ;
void handle_sigint(int sig) { 
       	secs = 0;
} 

int main(int argc, char **argv){
	sleep(1);
	signal(SIGINT, handle_sigint);
     	int i;   
  	int j;
	printf("\n");
  	while(secs<6) {
     		printf("Time:%i\n",secs);
     		fflush(0);
     		sleep(1);
     		secs++;
      		printf("\r\b\r");
  	}
	//Get the parent id and send a Signal Interrupt signal since time is up
	ppid = getppid();
	kill(ppid, SIGINT);
 	return 0;
}
 
