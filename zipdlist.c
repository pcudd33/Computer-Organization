/*
 * Read a file of zipcode data and count the number of lines 
 *
 *
 */

#include <stdio.h>



//preprocessor command 
//by convention these are capitol letters
#define ZIPLEN 6 //length of the zipcode including the null
//terminating byte
#define STATELEN 3
#define CITYLEN 128

int main(int argc, char *argv[]) {

	char code[ZIPLEN]; //zipcode 
	char state[STATELEN]; //state
	char city[CITYLEN]; //city 
	double lng, lat; //longitude latitude
	unsigned int lc = 0; //line counter

	//open the zipcode file
	//the "r" opens it in read only mode 
	FILE *f = fopen("../CS220_data/zips.csv", "r");

	//fscanf is for reading from a file

	while (1){
	
	//city read everything up to the comma
	int rc = fscanf(f, "%5s,%2s,%[^,],%lf,%lf",code,state,city,&lng,&lat);
	
		if(rc == EOF){
		break;
		}
	lc++;
		
		
	//printf("Line count: %u\n", lc);
	//return 0;
	}
printf("Line count: %u\n", lc);
}





















