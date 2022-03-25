#include "digitsumfinal.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char* number = argv[1];
	
	if (number < 0){
		printf("No command line argument input");
	}
	
	if (argc == 0){
				printf("invalid command line argument\n");
				return 0;
				}
				
	if (argc > 2){
				printf("too many command line arguments\n");
				return 0;
				}
	
	printf("the digit sum of the digit that was input is %d\n", digitsumfinal(atoi(number)));
}
