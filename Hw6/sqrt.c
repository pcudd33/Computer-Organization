#include "sqrt.h"

double fabs(double n) {
	if (n < 0){
		n = -n;
	}
	return n;
}
#define epsilon .000001
double sqrt(double n) {
	
	double r = n;			//initial guess at r 
	
	while (fabs(n - (r * r)) > epsilon){
		r = (r + n / r) / 2.0;
}
	return r;
}
