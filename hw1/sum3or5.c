int sum3or5(int n) {
	int sum = 0; 
	int i = 0;
	//for(int i = 0; i < n; i++){
	while(i < n){
		if(i % 3 == 0 || i % 5 == 0){
			sum = sum + i;
	}
	i++;
}
	return sum;
}