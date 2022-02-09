#include <stdlib.h>
#include <stdio.h>

#include "f2c.h"
int main(int argc, char *argv[]){
	printf("What integer would you like converted to celcius: ");
	double i = atof(argv[1]);
	f2c(i);
}

