#include <stdio.h>
#include <string.h>

double uptime_monitor(){
    FILE *file = fopen("/proc/uptime", "r");

    if(file == NULL){
        return 1;
    }

    double uptime;
    char buffer[256];

    while(fgets(buffer, sizeof(buffer), file) != NULL){
        sscanf(buffer, "%lf", &uptime);
    }

    return uptime;
    fclose(file);

}