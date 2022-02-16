#include <stdio.h>
#include <limits.h>

int main(void) {
	/*signed char i = 127;
	signed char l = CHAR_MAX;
	signed char xx = 0x7F;
	i = 1 + i;
	printf("%d\n", i);

	int j = 0b01111111111111111111111111111111;
	int k = INT_MAX; //INT_MAX is the largest int
	int kk = 0x7FFFFFFF;

	printf("%d %d %d\n", j + 1, k, kk);

	unsigned int z = UINT_MAX;
	unsigned int zz = 0xFFFFFFFF;

	printf("%u %d\n", z, zz);

	int w = 79;
	//the ~ inverted the bits and we added one 
	//that is the twos compliment operation 
	printf("%d %d %d\n", w*-1, -w, ~w + 1);

	int q = -1;
	int qq = 0xFFFFFFFF;
	printf("%d %d\n",q, qq);*/

	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(char));
	printf("%d\n", sizeof(double));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(long long));
	printf("%d\n", sizeof(long int));
	printf("%d\n", sizeof(long double));
	printf("%d\n", sizeof(unsigned char));
	printf("%d\n", sizeof(signed char));
	printf("%d\n", sizeof(unsigned int));
	


	int x = 5;
	int *p = &x;
	printf("%d\n", p);

	double z = 3.5;
	x + 23.1;

	

















}