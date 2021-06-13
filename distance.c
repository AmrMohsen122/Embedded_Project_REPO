
#include <math.h>

#define PI 3.14159265358979323846
#define ERAD 6371

double degtorad(double deg) {
    return (deg * PI / 180);
}

double convert(double in){
    int mid = in / 100;
    in -= mid *100;
    in /= 60;
    return mid + in;
}



// distance using haversine formula
void calcDistance(double long11, double long22, double lat11, double lat22 , double * amount) {
    double lat1 = convert(lat11);
    double lat2 = convert(lat22);
    double long1 = convert(long11);
    double long2= convert(long22);



    double x = pow(sin(degtorad(0.5 * (lat2 - lat1))), 2) + (cos(degtorad(lat1)) * cos(degtorad(lat2)) * pow(sin(degtorad(0.5 * (long2  - long1))), 2));

    *amount =  2 *ERAD*1000* asin(sqrt(x));

}
