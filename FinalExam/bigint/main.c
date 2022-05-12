#include "bigint.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	  
    BigInt *x = make_int(argv[1]);
    BigInt *z = div10(x);
    BigInt *w = mul10(x);
    byte n = mod10(x);
    int s = checksum(x);
    
    print_int(z);
    print_int(w);
    printf("%c\n", n);
    printf("%d\n", s);
    
    free(x); 
    free(z); 
    free(w); 

    return 0;
}
