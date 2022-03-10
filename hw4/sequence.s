/*
int sequence(int n) { 
	int length = 0;
	while( n > 1){
		if(n % 2 == 0 ){
			n = n/2;
			length = length +1;
		}else{
			n = (n * 3) + 1;
			length = length +1;
	}
}
length += 1;
return length;
}
*/

.cpu cortex-a53
.global sequence
.text

mod:
	sdiv r2, r0, r1		
	mul r2, r2, r1
	sub r0, r0, r2
	bx lr
	
	//int n is going to be stored in r4 due to mod overwriting r0 
	//length will be stored within r5 
sequence:
	push { r4-r6, lr }
	mov r4, r0	
	mov r5, #0
	

while:
	cmp r4, #1		//compare n to 1
	beq endwhile	//if n is equal to 1 continue 
	mov r0, r4		//move n into r0 so its ready for mod
	mov r1, #2		//move 2 into r1 so its ready for mod
	bl mod			//go to mod
	cmp r0, #0		//compare the value returned from mod to 0 to check if condition
	beq if			//if the condition is met then go to if
	bne else		//if the condition is not met go to else 
	b while			//loop through the while again
	
	
if:
	add r5, r5, #1	//itterate length by 1
	mov r6, #2		//store 2 in r7 so we can do division
	sdiv r4, r4, r6	 // divide n by 2
	b while			//loop back through the while until the while condition is met 

else:
	add r5, r5, #1	//iterate length by 1
	mov r6, #3		//store 2 in r7 so we can do division
	mul r4, r4, r6	// divide n by 3
	add r4, r4, #1	//itterate length by 1 
	b while			// loop back through the while until the while condition is met
	

endwhile:
	add r5, r5, #1	//add one to length so that we account for when n = 1
	mov r0, r5		//move length into r0
	pop { r4-r6, lr }
	bx lr
