#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Author: Phillip Chae
//Purpose of program: Take user input virtual address and return a corresponding value stored in the address within the cache
//


//************Structures needed for the lookups******************
//
//A TLB structure that contains all of actual TLB components: set index, tag, and PPN
typedef struct TLB{
	char index;
	//The array variables hold one more index value than needed because of the necessity of null operator
	char tag[3];
	char ppn[3];	
}TLB;
//A Page Table structure that emulates Page Table
typedef struct PT{
	char vpn;
	char ppn[3];
//Structure that emulates cache;
}PT;
typedef struct cache{
	char index;
	char tag[3];
	char bo0[3];
	char bo1[3];
	char bo2[3];
	char bo3[3];
}cache;

//Function declaration needed because it is used before it is specified later on down the line
int hexToInt(char hex);


//************Methods used for searchup************

//Summary: Takes the user input address to lookup the corresponding PPN in the TLB
//Input: User input address; The TLB array taht contains all TLB values
//Output: PPN corresponding to locations specified
char* TLBlu(char *input, TLB tlbarr[]){
	int TLBT = hexToInt(input[0])*16 + hexToInt(input[1]);	
	int TLBi = hexToInt(input[2])/4;
	int i; int hit = 0;
	char* n = "0";
	//Searches through a match through all TLB entries
	for(i = 0; i <16; i ++){
		if(TLBT == hexToInt(tlbarr[i].tag[0])*16 + hexToInt(tlbarr[i].tag[1])  
		&& TLBi == hexToInt(tlbarr[i].index)){ 
			n = tlbarr[i].ppn;
			hit = 1;
		}
	}
	if(hit == 1)printf("The PPN retrieved from TLB: %s\n",n);
	else {printf("Corresponding PPN not found in TLB, searching in Page Table\n");}
	return n;	
}
//Summary: Takes the user input address to lookup the corresponding PPN in the Page Table
//Input: User input address; The Page Table array that contains all Page Table values
//Output: PPN corresponding to locations specified 
char* PTlu(char *input, PT ptarr[]){
	int VPN = hexToInt(input[1])*4 + hexToInt(input[2])/4;
	int i; int hit = 0;
	char* n = "0";
	for(i = 0; i < 16; i++){
		if(VPN == hexToInt(ptarr[i].vpn)){
			n = ptarr[i].ppn;
			hit = 1;
		}
	}
	if(hit == 1)printf("The PPN retrieved from Page Table: %s\n", n);
	else {printf("Corresponding value not found in Page Table\n");}
	return n;
}
//Summary: Takes the PPN derived from the TLB or Page Table and uses it along with the user input address to find the value.
//Input: the PPN derived from either TLB or Page Table; the user input virtual address; the cache array that contains all cache values
//Output: Value held in the cache in the respective location.
char* caLu(char *ppn, char* input, cache carr[]){
	int i = 0;
	int tag = hexToInt(ppn[0])*16 + hexToInt(ppn[1]);
	int ci =  hexToInt(input[2])%4*4 + hexToInt(input[3])/4;
	int co =  hexToInt(input[3])%4;
	char* n = "0";
	int hit = 0;
	for(i = 0; i < 16; i++){
		if(tag == hexToInt(carr[i].tag[0])*16 + hexToInt(carr[i].tag[1]) 
		&& ci == hexToInt(carr[i].index)){
			hit = 1;
			if(co == 0) n = carr[i].bo0;
			if(co == 1) n = carr[i].bo1;
			if(co == 2) n = carr[i].bo2;
			if(co == 3) n = carr[i].bo3;
		}
	}
	if(hit == 1) printf("The value being returned from cache: %s\n", n);
	else printf("Not able to find value in cache\n");
	return n;
}
//Summary: Emulates the search process: (1) Look at TLB for the PPN with the virtual address. (2) If not found, search the Page Table for the PPN.(3) If PPN found, look up at the cache to find the value in the user input address. (4)If not, result in "Cannot be determined"
//Input: User input address; All necessary structure arrays
//Output: Value stored in the address
void searchDriver(char *input, TLB tlbarr[], PT ptarr[], cache carr[]){
	char* ppn = TLBlu(input,tlbarr);
	if (strcmp(ppn, "0") == 0){
		ppn = PTlu(input, ptarr);
	}
	char* ret = caLu(ppn,input,carr);
	if (strcmp(ret, "0") == 0) printf("Cannot be determined\n");	
}
//Summary: Converts each indiviudal hexadecinal characters to corresponding integer values for easier comparison and alterations.
//Input: A hexadecimal character from user input address
//Output: A decimal number equivalent to the hexadecinal character
int hexToInt(char hex){
	int n;
	if(hex > '0' && hex < '9') return n = hex - 0x30;
	else {
		switch(hex){
			case 'A': case 'a': n = 10; break;
			case 'B': case 'b': n = 11; break;
			case 'C': case 'c': n = 12; break;
			case 'D': case 'd': n = 13; break;
			case 'E': case 'e': n = 14; break;
			case 'F': case 'f': n = 15; break;
			default: return 0;
		}
	}
	return n;
}
//**********Main Function**************
int main(){
	FILE *fp;
	fp = fopen("Project4Input.txt", "r");
	if(fp == NULL){
		printf("There was a problem reading the file");
		return -1;
	}
	//Initialize struct arrays
	TLB tlbarr[16]; PT ptarr[16]; cache carr[16];
	int TLBi = 0; int PTi = 0; int caci = 0;
	//The input variable will store each individual line for the system to process it 
	char* input = (char*)malloc(25*sizeof(char));
	printf("/////////////////////////////INPUT TEXT FILE/////////////////////////////\n");
	//Keep scanning each line until EOF
	for(;;){
		fgets(input,25,fp);
		//The line by line print of input text file for debug purposes
		printf("%s\n", input);
		//If the input is TLB, store it accordingly to the data type specific index values
		if (input[0] == 'T'){
			tlbarr[TLBi].index = input[4];
			tlbarr[TLBi].tag[0] = input[6];
			tlbarr[TLBi].tag[1] = input[7];
			tlbarr[TLBi].tag[2] = '\0';
			tlbarr[TLBi].ppn[0] = input[9];
			tlbarr[TLBi].ppn[1] = input[10];
			tlbarr[TLBi].ppn[2] = '\0';
			TLBi++;
		}
		//If the input is Page Table, store it accordingly
		else if (input[0] == 'P'){
			ptarr[PTi].vpn = input[5];
			ptarr[PTi].ppn[0] = input[7];
			ptarr[PTi].ppn[1] = input[8];
			ptarr[PTi].ppn[2] = '\0';
			PTi++;
		}
		//If the input is Cache, store in accordingly
		else if (input[0] == 'C'){	
			carr[caci].index = input[6];
			carr[caci].tag[0] = input[8];
			carr[caci].tag[1] = input[9];
			carr[caci].tag[2] = '\0';
			carr[caci].bo0[0] = input[11];
			carr[caci].bo0[1] = input[12];
			carr[caci].bo0[2] = '\0';
			carr[caci].bo1[0] = input[14];
			carr[caci].bo1[1] = input[15];
			carr[caci].bo1[2] = '\0';
			carr[caci].bo2[0] = input[17];
			carr[caci].bo2[1] = input[18];
			carr[caci].bo2[2] = '\0';
			carr[caci].bo3[0] = input[20];
			carr[caci].bo3[1] = input[21];
			carr[caci].bo3[2] = '\0';
			caci++;
		}
		//If the input is "DONE", stop the input process and begin the user input process
		else if (input[0] == 'D'){
			break;
		}
		//If the line is not within allowed format,give error and exit 
		else{
			printf("ERROR: INVALID DATA TYPE IDENTIFIER\n");
			exit(0);
		}	
	}
	printf("////////////////////////////////////////////////////////////////////////////\n\n///////////////////////////////USER INPUT SECTION///////////////////////////////////\n");
	//Free allocated memory from previous process and scan functions
	free(input); input = NULL;
	freopen("/dev/tty","r",stdin);
	int i;
	char* user = (char*)malloc(5*sizeof(char));
	for (i = 0; i < 3; i ++){
		//Prompt to enter virtual address, whcih will be stored in user
		printf("Enter a virtual address: ");
		scanf("%s", user);
		//Make sure that the system recognizes this as string
		user[4] = '\0';
		searchDriver(user,tlbarr,ptarr,carr);
		printf("\n");
		
	}
	//Free allocated user memory
	free(user); user = NULL;
	printf("///////////////////////////////END OF PROGRAM//////////////////////////////////////");
	return 0;	
}