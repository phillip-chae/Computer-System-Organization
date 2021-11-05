//Author: Phillip chae
//Description: C representation of given_bar object file

//Takes two long values and returns one long value.
long bar(long a, long b){
	long c = 0;
	long rcx=11*a-14*b+1;
	while(a<=b){
		c+=rcx;
		a++;
	}
	return c;
}
