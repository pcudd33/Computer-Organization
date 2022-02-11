#include <stdio.h>

void int2bin(int n){
int counter;
char str[n];  // Ed: this line is a problem. n is 123456789
int index;
	//this also works but doesn't use the array
	/*if(n > 0){
		int2bin(n/2);
		printf("%d", n % 2);
	}*/

while(n > 0){
//this while loop pushes all 1s and 0s into the str array at index
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

//this for loop is going back through and putting them in 
for(int i = index - 1; i >= 0; i--){
	printf("%c", str[i]);
}

	
}
