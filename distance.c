#include <math.h>

#define PI 3.14159265358979323846
#define ERAD 6371

double degtorad(double deg) {
	return (deg * PI / 180);
}


// distance using haversine formula
double calcDistance(double long1, double long2, double lat1, double lat2) {

	double x = pow(sin(degtorad(0.5 * (lat2 - lat1))), 2) + (cos(degtorad(lat1)) * cos(degtorad(lat2)) * pow(sin(degtorad(0.5 * (long2 - long1))), 2));

	double d =  2 *ERAD*1000* asin(sqrt(x));
	return d;
}
