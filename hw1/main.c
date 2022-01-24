//Homework 1 due Friday, January 28th 
//Parker Cuddeback, CS220 Spring 22

//angle brackets around an include/header file indicate that it
//is a system header file
#include <stdio.h>

#include "sum3or5.h"
#include "sequence.h"

int main(void) {
	printf("sum3or5 of 10 is %d\n", sum3or5(10));
	printf("sequence of 10 is %d\n", sequence(10));
	printf("the longest sequence is %d\n", longest());
}