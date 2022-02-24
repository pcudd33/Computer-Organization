/*
 * Read a file of zipcode data and count the number of lines 
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include "distance.h"



//preprocessor command 
//by convention these are capitol letters
#define ZIPLEN 6 //length of the zipcode including the null
//terminating byte
#define STATELEN 3
#define CITYLEN 128


int main(int argc, char *argv[]) { 

	char code1[ZIPLEN]; 			//zipcode 1
	char code2[ZIPLEN]; 			//zipcode 2
	char current_code[ZIPLEN]; 		//current zipcode
	char state1[STATELEN]; 			//state 1
	char state2[STATELEN];			//state 2
	char current_state[STATELEN];	//current state
	char city1[CITYLEN]; 			//city 1
	char city2[CITYLEN]; 			//city 2
	char current_city[CITYLEN];		//current city 
	double lng1, lng2, lat1, lat2;  //longitude latitude
	double current_lng, current_lat;//current latitude and longitude
	
	
	//check if right number of command line arguments specified
	if (argc != 3){
		printf("Error: no file and/or zipcode specified\n");
		return 0;
	}
	
	char *key1  = argv[1]; //zipcode we are searching for
	char *key2  = argv[2]; //the second zipcode we are searching for 
	
	if(strlen(key1) != 5 || strlen(key2) != 5){
		printf("The zipcode entered was invalid");
		}
	

	//open the zipcode file
	//the "r" opens it in read only mode 
	FILE *f = fopen("../../CS220_data/zips.csv", "r");
	
	//Good programs do not crash or have a runtime error, they fail gracefully
	//with a nice error message 

	//fscanf is for reading from a file
	if (f == NULL){
	printf("Error: file CS220_data/zips.csv not found\n");
	return 0;
	}

	while (1){
	
	//city read everything up to the comma
	//printf
	int rc = fscanf(f, "%5s,%2s,%[^,],%lf,%lf",current_code,current_state, current_city, &current_lng, &current_lat);
	
	//error checking
	
		if(rc == EOF){
		break;
		}
		
	//check if found key
	if(strncmp(key1, current_code, 6) == 0){
		lat1 = current_lat;
		lng1 = current_lng;
		strncpy(state1, current_state, STATELEN);
		strncpy(city1, current_city, CITYLEN); 
		}
	if (strncmp(key2, current_code, 6) == 0){
		lat2 = current_lat;
		lng2 = current_lng;
		strncpy(state2, current_state, STATELEN);
		strncpy(city2, current_city, CITYLEN); 
		}
		
	}
		
		//double miles = distance(lat1, lng1, lat2, lng2);
		//printf("%.3lf, %.3lf\n", lat1, lng1);
		//printf("%.3lf, %.3lf\n", lat2, lng2);
		printf("The distance from %s, %s to %s, %s is %.2lf miles.\n", city1, state1, city2, state2, distance(lat1, lng1, lat2, lng2));
	return 0;
}





















