#include "bigint.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

BigInt *make_int(const char *s) {
	
	BigInt *b = malloc(sizeof(BigInt)); // this is the same as saying b = new BigInteger in java / also malloc bc thats how much storage each big int needs and size of is equal to 8 but its a magic number
	
	//(*b).n = strlen(s);		// this is assigning n with the length of the array so we know how long to make the bigint
	b->n = strlen(s);  //this is short hand for what is above
	// have to say b-> because n doesnt exisit outside of the struct
	b->digits = malloc(b->n);  	//this is a pointer to the array so b->digits accesses the array 
	//b -> n means folow the pointer firs so we end up in the struct 
	
	//copy digits from s into digits array
	for (int i = 0; i < b->n; i++) {
		b->digits[i] = s[b->n - 1 - i] - '0'; //everything inside the s[] is to make sure it adds the numbers in the correct indexes and the -48 is the ascii conversion 
	}
	return b;
}

BigInt *make_zero(int n) {
	char tmp[n+1];
	memset(tmp, '0', n);
	tmp[n] = 0;				// null terminate the string 
	return make_int(tmp);
}

void print_int(const BigInt *b) {
	int beginning = b->n - 1;
	
	while (b->digits[beginning] == 0){
		beginning--;
	}
		for (int i = beginning; i >= 0; i--) {
			printf("%hhd", b->digits[i]); // digits is a poiunter to the array so [] allows us to access the inforamtion at each index
		}
		printf("\n");
}

BigInt *div10(const BigInt *x) {
	BigInt *result = make_zero(x->n -1);
	for(int i = 0; i < result->n; i++) {
		result->digits[i] = x->digits[i + 1];
	}
	return result;
}


BigInt *mul10(const BigInt *x) {
	BigInt *result = make_zero(x->n + 1); // make an array that is one longer than the one before because we are adding 0
	for(int i = 0; i < x->n; i++) {// loop throught the new array and insert at n-1 becuase n is the new 0	
		result->digits[i + 1] = x->digits[i];// it is i + 1 because i is = 0
	}
	return result; 
}

byte mod10(const BigInt *x) { // there is a type error here 
	byte n = x->digits[0] % 10;	// take from the location we want in x and take off the end and put it into n
	return n;	// return the the byte
}
/*int checksum(int n) {
    int sum = 0;

    while (n > 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    
    return sum % 10; 
}
*/
int checksum(const BigInt *x) {
	int sum = 0;
	
	for (int i = 0; i < x->n; i++) {
		sum += x->digits[i];
	}
	return sum;
}


