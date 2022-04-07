#include "pow_rec.h"

int pow_rec(int a, int b){
	
	if (b == 0){
		return 1;
	}else if(b % 2 == 1){
		return a * pow_rec(a, b-1);
	}else if(b % 2 == 0){
		return pow_rec(a, b/2 ) * pow_rec(a, b/2);
	}
}
