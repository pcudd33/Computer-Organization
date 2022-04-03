#include "simulate.h"
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
	
    if (argc < 0){
                printf("No command line argument input");
                return 0;
                }
	
	if (argc == 0){
				printf("invalid command line argument\n");
				return 0;
				}
				
	if (argc > 3){
				printf("too many command line arguments\n");
				return 0;
				}
				
	if (argc < 3){
				printf("invalid command line argument\n");
				return 0;
				}
                
                
    int isdigit1 = verify(argv[1]);         //make sure that the two things we enter into the command line 
    int isdigit2 = verify(argv[2]);         //are in fact integers so the program wont crach 
    
    if(isdigit1 && isdigit2 == 1){
    
        int n = atoi(argv[1]);
        int times_run = atoi(argv[2]);
        int sum = 0;

        for (int i = 0; i < times_run; i++) {
            sum = sum + simulate(n);
        }

        // cast runs to a double
        printf("%.2f\n", sum/(double) times_run);
    }
}
