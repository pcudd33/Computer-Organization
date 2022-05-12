/*
char *reverse(char *s) {
   int reverse(int n, int r) {
		if (n == 0) {
			return r;
		}else{
			return reverse(n>>1, (r<<1) | (n&1));
		}
   }
}
*/


.global reverse
.cpu cortex-a53
.text

mod:
	sdiv r2, r0, r1		
	mul r2, r2, r1
	sub r0, r0, r2
	bx lr
	
reverse:
	push { r4, r5, lr}
	mov r4, r0
	mov r5, #0
	b if

if:
	cmp r4, #0
	beq end
	mov r0, r4
	mov r1, #10
	b mod
	add r5, r5, r0
	lsl r5, #1
	b if

end:
	mov r0, r3
	pop { r4, r5, lr}
	bx lr
