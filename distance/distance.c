#include <math.h>  
#include <stdio.h>

#define M_PI  3.14159265358979323846  /* pi */    
#define R 6371000

//sin^2 = sin() * sin()
	

double distance(double lat1, double lng1, double lat2, double lng2){
	lat1 = (lat1 * (M_PI / 180.0));
	
	lat2 = (lat2 * (M_PI / 180.0));
	lng1 = (lng1 * (M_PI / 180.0));
	lng2 = (lng2 * (M_PI / 180.0));
	 
	double x = (sin((lat2 - lat1) / 2.0) * sin((lat2 - lat1) / 2.0)) + (cos(lat1) * cos(lat2) * sin((lng2 - lng1) / 2) * sin((lng2 - lng1) / 2.0));
	double y = 2 * atan2(sqrt(x), sqrt(1 - x));
	double distance_final = (R * y) / 1609.344; 	//change meters to miles
	return distance_final;  
	}
