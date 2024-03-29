/*
 * Read a file of zipcode data and count the number of lines 
 *
 *
 */

#include <stdio.h>
#include <string.h>



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
	
	//check if right number of command line arguments specified
	if (argc < 2){
		printf("Error: no file and/or zipcode specified\n");
		return 0;
	}

	char *fname = argv[1];
	char *key  = argv[2]; //zipcode we are searching for

	//open the zipcode file
	//the "r" opens it in read only mode 
	FILE *f = fopen(fname, "r");
	
	//Good programs do not crash or have a runtime error, they fail gracefully
	//with a nice error message 

	//fscanf is for reading from a file
	if (f == NULL){
	printf("Error: file %s not found\n", fname);
	return 0;
	}

	while (1){
	
	//city read everything up to the comma
	int rc = fscanf(f, "%5s,%2s,%[^,],%lf,%lf",code,state,city,&lng,&lat);
	
		if(rc == EOF){
		return 0;
		}
		
	//check if found key
	if(strcmp(key, code) == 0){
		printf("%s, %s, %s, %lf, %lf\n", city,state,code,lng,lat);
		break;
		}
		
		
	//lc++;
		
	}
//printf("Line count: %u\n", lc);
}





















