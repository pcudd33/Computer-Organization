//Parker Cuddeback
//hw4
//due firday march 11th 
//CS220Spring22

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "sum3or5.h"
#include "sequence.h"



int verify(char *str){
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		if(!(isdigit(str[i]))){
			return 0;
			}
		}
		return 1;
	}

int main(int argc, char *argv[]){
	
			//check if equal to 0 error
			if (argc == 0){
				printf("invalid command line argument\n");
				return 0;
				}
				
			//check if greater than 2 error
			if (argc > 2){
				printf("too many command line arguments\n");
				return 0;
				}
				
			//check if it is not an integer via verify 
			
			if (verify(argv[1]) == 0){
				printf("what was input was not a non-negative integer\n");
				return 0;
				}
				
			int n = atoi(argv[1]); //making sure that what is being taking in is in integer form even if it passes all other tests
			
			if (n < 0){
				printf("invlaid intger: %d\n", n);
				return 0;
				}
				
			printf("the sum3or5 of %d is %d\n", n, sum3or5(n));
			printf("the sequence of %d is %d\n", n, sequence(n));

}
