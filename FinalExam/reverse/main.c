#include "reverse.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int verify(char *str){
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		if(!(isdigit(str[i]))){
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
			printf("the reverse of %d is %d", atoi(argv[1]), reverse(atoi(argv[1])));
			return 0;
		}
	}
}
