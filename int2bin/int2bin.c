#include <stdio.h>

void int2bin(int n){
int counter;
char str[n];
int index;
	//this also works but doesn't use the array
	/*if(n > 0){
		int2bin(n/2);
		printf("%d", n % 2);
	}*/

while(n > 0){
	if(n % 2 == 0){
		str[index] = '0';
		index++;
	}
	if(n % 2 == 1){
		str[index] = '1';
		index++;
	}

n = n / 2;
}

for(int i = index - 1; i >= 0; i--){
	printf("%c", str[i]);
}

	
}