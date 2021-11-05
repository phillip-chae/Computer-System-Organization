#include <stdio.h>

int is_little_endian(){
	unsigned int checker = 1;
	char *checkAddress = (char*)&checker;
	if(*checkAddress) return 1;
	else return 0;
}
int c_compress(int x, int y){
	int xmask = 0x000000FF;
	int ymask = 0xFFFFFF00;
	x = x & xmask;
	y = y & ymask;
	return (x | y);
}
unsigned int replaceByte(unsigned int word, unsigned int loc, unsigned int swapee){
	loc = 8 * loc;
	swapee = swapee << loc;
	unsigned int word1 = (word >> (loc +8)) << (loc + 8);
	unsigned int word2 = (word << (32 - loc)) >> (32-loc);
	return word1 | word2 | swapee ;	
}
int checkit(char *s, int x){
	if(s == "a"){
		if(x != 0) return 1;
		return 0;
	}
	if(s == "b"){
		if(x != 0xFFFFFFFF)return 1;
		return 0;
	}
	if(s == "c"){
		if((0x1 & x) != 0) return 1;
		return 0;
	}
 	if(s == "d"){
		if((0x80000000 & x) != 0) return 1;
		return 0;
	}
	return -1;
}
int main(){
	//Test i_little_endian()	
	if(is_little_endian()==1) printf("\nThis machine is little endian\n\n");
	else printf("This machine is big endian\n\n");

	//Test c_compress (Specifically made the numbers result 0 if compression is done correctly)
	int x = 0xFFFFFF00;
	int y = 0x000000FF;
	printf("Test 1: x is %d (0x%X) and y is %d (0x%X).\n",x,x,y,y);	
	printf("The compression results in: %d (0x%X)\n",c_compress(x, y),c_compress(x, y));
   x = 0x12345678;
   y = 0x87654321;
   printf("Test 2: x is %d (0x%X) and y is %d (0x%X).\n",x,x,y,y);	
	printf("The compression results in: %d (0x%X)\n\n",c_compress(x, y),c_compress(x, y));


	//Test replaceByte
	unsigned int word = 0x12345678;
	unsigned int loc = 1;
	unsigned int swapee = 0x90;
	printf("The word is 0x%X, replace location is %d, replacing variable is 0x%X\n",word,loc,swapee);
	printf("The result of replaceByte is: 0x%X\n\n", replaceByte(word,loc,swapee));

	//Test checkit
	printf("Test 1: Checkit with letter %s and integer %d returns %d\n", "a", 0, checkit("a",0));
	printf("Test 2: Checkit with letter %s and integer %d returns %d\n", "b", 1, checkit("b",1));
	printf("Test 3: Checkit with letter %s and integer %d returns %d\n", "c", 23, checkit("c",23));
	printf("Test 4: Checkit with letter %s and integer %d returns %d\n", "d", 23, checkit("d",23));

	return 0;
}

