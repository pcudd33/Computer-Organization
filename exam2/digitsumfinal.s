.cpu cortex-a53
.global digitsumfinal
.text

mod:
	sdiv r2, r0, r1		
	mul r2, r2, r1
	sub r0, r0, r2
	bx lr

digitsumfinal:
	push {r4, r5, lr}
	mov r4, r0				//put the number give through command line into r4
	mov r5, #0				//this is going to be the location where I add up all of the final sums 
	
while:
	cmp r4, #0				//this is the comparison that takes place in the while loop 
	beq endwhile			//branch to the endwhile is r4 = 0
	mov r0, r4				//set up for the mod function 
	mov r1, #10 			//we want to mod by 10 becuase that is how we will take out the last digit 
	bl mod					//call mod
	add r5, r5, r0			//add r0 and r5 together so that we keep track of the total 
	sdiv r4, r4, r1			//divide by ten in order to shift all of the digits in the number input by the command line by 1 space 
	b while
	
endwhile:
	mov r0, r5				//put the final sum in r0 becuase that is the numbner that gets returned 
	pop {r4, r5, lr}
	bx lr
