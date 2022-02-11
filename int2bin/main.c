#include <stdio.h>
#include "int2bin.h"

// Seems to crash on 123456789. It shouldn't.
// That was a test case. 18/20

int main(int argc, char *argv[]){
int scanner;
printf("Enter an int: "); 
scanf("%d", &scanner);

	if(scanner < 0){
			printf("Bye.\n");
		}

	while(scanner > 0){
		printf("%d = ", scanner);
		int2bin(scanner);
		printf("\nEnter an int: "); 
		scanf("%d", &scanner);
				
	}
}
	
