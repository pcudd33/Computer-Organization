//static variables are stored in global memory
//loacl variables note allocated to registers are stored on the stack
//the read-modify-write operation is a fundemental computer sciecne concept
//	ldr, modify, str
//ldr, str, the ARM proccessor is called a load/store archiceture
//all operations happen in register taht are loaded from memory
//and then stored


.global simulate
.cpu cortex-a53
.data			//allocate global memory 

//a word is the width, in bytes of the natural size of the machine
//4 bytes
seedhack: .word 0

.text


mod:
	sdiv r2, r0, r1		
	mul r2, r2, r1
	sub r0, r0, r2
	bx lr
	
simulate:
	push {r4-r10, fp, lr }
	mov r6, #366
	mov r5, r0
	
	//local variable get stored on the stack if you can't put them in a register
	sub sp, sp, r6, lsl #2 // shift r1 by two and then subtract
	mov r7, sp  		   //store starting address of array in r7
	ldr r4, =seedhack 	   //put the address of seedhack in r4
	
	//set up call to memset
	mov r0, r7				// r7 contains the base address of the array to set up for memset
	mov r1, #0				//this is becuase we are goingto put 0's in th array
	mov r2, r6, lsl #2		//this will contain 1464 which is 366 lsr 2
	bl memset	
	
	//read / modify / write
	ldr r8, [r4] 		   //get the value of seedhack
	add r8, r8, #1		   //increment seedhack
	str r8, [r4]		   //put incremented value back in the memory location of seedhack
	
	//call time
	mov r0, #0				//set up time
	bl time
	add r0, r0, r8			
	bl srand
		
	mov r9, #0 				// set up i = 0
	
while1:
	mov r4, #0
	cmp r9, r5				// compare i and n 
	bge end1				//if i >= to n go to end1
	bl rand 				// the random number generated from rand() goes into r0
	mov r1, r6				//r1 now is equal to 366
	bl mod					// call to mod
	mov r10, #4				//set up the next add function
	mul r4, r0, r10	    
	add r7, r7, r4	        // r0 is the random number that gets multiplied by 4 for the bytes 
	ldr r0, [r7]			//add the value of r0 to the sp
	add r0, r0, #1			//read - modify - write
	str r0, [r7]
	mov r7, sp			
	add r9, r9, #1			
	b while1
	
end1:
	mov r9, #0				//reset the value of i to 0
	b while2		
		
while2:	
	mov r4, #0				// set up the add funciton
	cmp r9, r6				// compare i and DAYS
	bge end3
	mul r4, r9, r10
	add r7, r7, r4			//add r9 which is i which was multiplied by 4 to the sp
	ldr r0, [r7]
	mov r7, sp				//load the value at index i
	cmp r0, #2				// compare r0 with 2 to see if multiple people share a birthday
	bge end2
	add r9, r9, #1			// increment 1
	b while2			
	
end2:
	 
	add sp, sp, r6, lsl #2	// add 1464 to the sp
	pop {r4-r10, fp, lr}
	mov r0, #1				// 1 = true
	bx lr

end3:
	
	add sp, sp, r6, lsl #2	//add 1464 to the sp
	pop {r4-r10, fp, lr}
	mov r0, #0				// 0 = false
	bx lr
