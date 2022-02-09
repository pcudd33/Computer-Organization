#include <stdio.h>
double f2c(double i){
	double c = (i-32)*(5/9);
	printf("%f\n", c);
}