//Homework 1 due Friday, January 28th 
//Parker Cuddeback, CS220 Spring 22

//angle brackets around an include/header file indicate that it
//is a system header file
#include <stdio.h>

#include "sum3or5.h"
#include "sequence.h"
#include "diamond.h"

int main(void) {
	int n;
	printf("sum3or5 of 10 is %d\n", sum3or5(10));
	printf("sequence of 10 is %d\n", sequence(10));
	printf("the longest sequence is %lld\n", longest());
	while(n != -1){
	printf("Enter a non-neative odd integer: ");
	scanf("%d", &n);
	if(n > 0 || n < -1){
	diamond(n);
	}
	}
	while(n = -1){
	printf("bye!\n");
	break;
	}
}