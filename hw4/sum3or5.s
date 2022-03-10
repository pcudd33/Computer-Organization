/*
int sum3or5(int n) {
	int sum = 0; 
	int i = 0;
	while(i < n){
		if(i % 3 == 0 || i % 5 == 0){
			sum = sum + i;
	}
	i++;
}
	return sum;
}
*/

.cpu cortex-a53
.global sum3or5
.text

mod:
	sdiv r2, r0, r1		//i = r0 and 3 = r1  for the second if i = r0 and 5 = r1
	mul r2, r2, r1
	sub r0, r0, r2
	bx lr
	
sum3or5:
	push { r4, r5, r6, lr } 
	mov r4, r0
	mov r5, #0				//this is sum 
	mov r6, #0				//this is i
	
while:
	cmp r6, r4
	beq endwhile			//could also be bge 
	mov r0, r6 
	mov r1, #3
	bl mod 
	cmp r0, #0				//this is the compare == in the if 
	beq if
	mov r0, r6 				
	mov r1, #5
	bl mod 
	cmp r0, #0	
	beq if
	
	add r6, r6, #1		    //else statement so increment i no matter what
	b while	
	
if:
	add r5, r5, r6
	add r6, r6, #1
	b while


endwhile:
	mov r0, r5
	pop { r4, r5, r6, lr }
	bx lr

