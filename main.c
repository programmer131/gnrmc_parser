#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float time_gps;
    float latitude;
    float longitude;
    char lat_str[20];
    char lon_str[20];
} GPSData;

int main() {
    //char gnrmc_string[] ="$GNRMC,,,,,000000.00,V,,,,*,0000*77";
    char gnrmc_string[] = "$GNRMC,123519.00,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A";
    
    GPSData gps_data;
    sscanf(gnrmc_string, "$GNRMC,%f,%*c,%f,%*c,%f",&gps_data.time_gps, &gps_data.latitude,  &gps_data.longitude);
    sscanf(gnrmc_string, "$GNRMC,%*f,%*c,%[^,],%*c,%[^,]",gps_data.lat_str, gps_data.lon_str);
    
    // Display parsed data
    printf("Time: %.02f\n", gps_data.time_gps);
    printf("Latitude: %f %s\n", gps_data.latitude, gps_data.lat_str);
    printf("Longitude: %f %s\n", gps_data.longitude, gps_data.lon_str);
    
    return 0;
}
