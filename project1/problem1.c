/*
Steps: 
1.) Convert and input the strings in text into multiple variables.
   -N Dates; MM/DD hh:mm:ss
2.) Check that the date has valid numbers
   -Month <= 12, Day <=31, Hour <= 24, Minute <=60, Second<= 60
3.) Convert each based on corresponding bits
   -0~3 ones ss, 4~6  tens ss, 7~10 ones mm, 11~13 tens mm, 14~17 ones hh, 18~19 tens hh, 20~23 ones DD, 24~25 tens DD, 26~29 ones MM, 30 tens MM 
4.) Add the numbers together and output
*/

#include <stdio.h>
#include <stdlib.h>
int convertDate(char *s){	
	int MM, DD, hh, mm, ss;
	int MMt, MMo, DDt, DDo, hht, hho, mmt, mmo, sst, sso;
	//Parse string into respective substrings;
	MM = atoi(&s[0]);
	DD = atoi(&s[3]);
	hh = atoi(&s[6]);
	mm = atoi(&s[9]);
	ss = atoi(&s[12]);

	//Check validity of dates
	if(MM < 1 || MM > 12) return -1;
	if(DD < 1 || DD > 31) return -1;
	if(hh < 0 || hh > 23) return -1;
	if(mm < 0 || mm > 59) return -1;
	if(ss < 0 || ss > 59) return -1;

	MMt = MM/10; MMo = MM%10;
	DDt = DD/10; DDo = DD%10;
	hht = hh/10; hho = hh%10;
	mmt = mm/10; mmo = mm%10;
	sst = ss/10; sso = ss%10;

	return(sso | (sst<<4) | (mmo<<7)| (mmt<<11) | (hho<<14) | (hht<<18) | (DDo<<20) | (DDt<<24) | (MMo<<26) | (MMt<<30));
return 0;
}

int main(){
	int i, n, result;
	char filter[14];
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%*c%[^\n]", filter);
		printf("Input: %s\n",filter);
		result = convertDate(filter);
		if(result==-1) printf("ERROR: Invalid Date\n");
		else printf("%d\n",result);
	}
	return 0;
}
