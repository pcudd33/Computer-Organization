/*
double fabs(double n) {
	if (n < 0){
		n = -n;
	}
	return n;
}
#define epsilon .000001
double sqrt(double n) {
	
	double r = n;			//initial guess at r 
	
	while (fabs(n - (r * r)) > epsilon){
		r = (r + n / r) / 2.0;
}
	return r;
}
*/

.global sqrt
.global fabs
.cpu cortex-a53
.fpu neon-vfpv4
.text

fabs:
	ldr r0, =zero
	vldr.f64 d1, [r0]		//set up the compare statement
	vcmp.f64 d0, d1 		//compare n < 0
	vmrs APSR_nzvc, FPSCR	//copy the floating-point flags to the integer cpu	
	bgt end_fabs			//bgt uses the integer program status register 
	ldr r0, =neg_one		//laod the address of neg_one into r0
	vldr.f64 d1, [r0]		//load -1.0 into d1
	vmul.f64 d0, d0, d1		// n * -1.0 or fabs
end_fabs:
	bx lr

sqrt:
	push {lr}
	vpush {d8, d9, d10, d11, d12}
	vmov.f64 d8, d0			//n is in d8
	vmov.f64 d9, d8			// r is in d9
	
while:
	vmul.f64 d10, d9, d9	//multiply r * r
	vsub.f64 d11, d10, d8	//n - (r * r) is sotred within d11
	vmov.f64 d0, d11		//set up the call to fabs 

	bl fabs
	ldr r0, =epsilon
	vldr.f64 d1, [r0]
	vcmp.f64 d0, d1			//fabs() > epsilon 
	vmrs APSR_nzvc, FPSCR	//copy the floating-point flags to the integer cpu


	ble endwhile	
	vdiv.f64 d12, d8, d9	// n / r into d12
	vadd.f64 d12, d12, d9	//r + (n/r) into d12
	ldr r0, =two
	vldr.f64 d1, [r0]
	vdiv.f64 d9, d12, d1	//move (r + (n/r)) / 2.0 into d9 to so it can run again 
	b while

endwhile:	//return r
	vmov.f64 d0, d9
	vmrs APSR_nzvc, FPSCR	//copy the floating-point flags to the integer cpu
	vpop {d8, d9, d10, d11, d12}
	pop {lr}
	bx lr
	
.data
.align 3		//2^3 = 8 bytes
neg_one:	.double -1.0
zero: 		.double 0.0
two:		.double 2.0
epsilon:	.double 0.000001
