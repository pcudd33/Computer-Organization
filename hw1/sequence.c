// Needed to use the long long int here to get the longest sequence. -1
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
//if I dont add this is does not count the last integer in the sequence
return length;
}

long longest(void) {
	int longest = 0;
	int value = 0;
	long i = 0;
	int number = 0;
	while(i <= 1000000){
		long current = sequence(i);
		if(current > longest){
			longest = current;
			 number = i;
			i += 1;
			}else{
i += 1;	
}
}
return number;
}
