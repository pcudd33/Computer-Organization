typedef unsigned char byte;

typedef struct {
		byte *digits;				//pointer to block of memory where everything will be stored (like an array)
		int n;						// length of the array of digits
} BigInt;

// make int allocates memry for the big integer
// it is the job of the caller to free it when 
// done using it.
extern BigInt * make_int(const char *s); //the pointer here is the same as a reference (in java when you do b = New Big.Integer) b is the same as the pointer in this case its a reference to the big int type
// const means that nothing in make_int will be altered
extern void print_int(const BigInt *b);

extern BigInt *div10(const BigInt *x);

extern BigInt *mul10(const BigInt *x);

extern byte mod10(const BigInt *x);

extern int checksum(const BigInt *x);
