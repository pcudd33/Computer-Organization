#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "sqrt.h"
#include "pow_rec.h"

int verify(char *str) {
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		if(!(isdigit(str[i]))) {
			return 0;
			}
		}
		return 1;
	}

int main(int argc, char *argv[]) {
	
	if (argc == 0) {
		printf("ERROR: no command line arguments");
		return 1;
		
	}else if (argc == 2) {
		int isdigit1 = verify(argv[1]);   
		
		if (isdigit1 == 1) {
			printf("The square root of %f is %f\n", atof(argv[1]), sqrt(atof(argv[1])));
			return 0;
		}
		
	}else if(argc == 3) {
		int isdigit1 = verify(argv[1]);   
		int isdigit2 = verify(argv[2]); 
		
		if(isdigit1 && isdigit2 == 1){
			printf("%d raised to the power of %d is %d\n", atoi(argv[1]), atoi(argv[2]), pow_rec(atoi(argv[1]), atoi(argv[2])));
			return 0;
		}else{
			printf("ERROR: command line argument out of bounds. \n");
			return 1;
		}
		
	}else if(argc > 3){
		printf("ERROR: command line argument out of bounds. \n");
		return 1;
	}
	return 0;	
		
	//printf("%f\n", fabs(atof(argv[1])));
	
}

