/*
int pow_rec(int a, int b){
	
	if (b == 0){			//if1
		return 1;			//end1
	}else if(b % 2 == 1){			//if2
		return a * pow(a, b-1);		//end2
	}else if(b % 2 == 0){					//if3
		return pow(a, b/2) * pow(a, b/2));	//end3
	}
}
*/

.global pow_rec
.cpu cortex-a53
.text

mod:
	sdiv r2, r0, r1		
	mul r2, r2, r1
	sub r0, r0, r2
	bx lr
	
pow_rec:
	push {r4-r6, lr}
	mov r4, r0			//mov a into r4
	mov r5, r1			//mov b into r5
	cmp r5, #0
	beq end1
	mov r0, r5			//move b into r0 to set up mod
	mov r1, #2			//move 2 into r1 to set up mod
	bl mod
	cmp r0, #1			//check if its odd
	beq end2
	cmp r0, #0			//check if its even 
	beq end3

end1:
	mov r0, #1
	pop {r4-r6, lr}
	bx lr

end2:
	mov r0, r4
	sub r1, r5, #1		//b - 1
	bl pow_rec			//pow(a, b-1)
	mul r0, r0, r4 		//a * pow(a, b-1)
	pop {r4-r6, lr}
	bx lr
	
end3: 
	mov r6, #2
	mov r0, r4
	sdiv r1, r5, r6		//b / 2
	bl pow_rec			//pow(a, b/2)
	mul r0, r0, r0 		//pow(a, b/2) * pow(a, b/2)
	pop {r4-r6, lr}
	bx lr
