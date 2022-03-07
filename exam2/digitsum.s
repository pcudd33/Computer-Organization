


.cpu cortex-a53
.global digitsum
.text
	
//divide by 1000 and if it isnt greater than zero continue then check 100 then 10 
digitsum:
push {r4-r10, lr}
mov r1, #1
mul r5, r0, r1		//store the original number so we can keep doing division on it 
mov r4, #1000
sdiv r0, r5, r4
cmp r0, #0
blt div1000	//if r0 is less than 0 go to 
mov r10, r0 //store the digit that was returned by dividing by 1000 into r10 for later addition
mov r4 #100
sdiv r0, r5, r4
cmp r0, #0
blt div100 	 //check to see if the digit retured is less than zero to see if we have more digits to add together 
mov r9, r0
mov r4 #10
sdiv r0, r5, r4
cmp r0, #0
blt div10
mov r8, r0
b additon


div1000: //ran out of time but was going to have all of these store the numbers that they were able to take out and call addition on them 
b additon 

div100:
b additon

div10: // make all of these do the addition and return the final values in r0 
b addtion

addition:
add r1 r10, r9
add r0 r1, r8
pop { r4-r10, lr}
bx rl 

	
