#include <stdio.h>
void diamond(int n){

	//top half of the pyramid
 
	for(int t = 1; t <= n / 2 + 1; t++){
		for(int b = 1; b <= n-t; b++){
			printf(" ");
			
		}
		for(int b = 1; b <= 2*t - 1; b++){
			printf("*");
			
		}
		printf("\n");
	}
	//bottom half of the pyramid 
	for(int t = 1; t <= n / 2; t++){
		for(int b = 1; b <= (n / 2) + t; b++){
			printf(" ");
			
		}
		for(int b = 1; b <= (n - 2 * t); b++){
			printf("*");
			
		
		}
	printf("\n");
	}
}












