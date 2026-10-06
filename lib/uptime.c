#include <stdio.h>
#include <string.h>

void uptime_monitor(double *uptime){
    FILE *file = fopen("/proc/uptime", "r");

    if(file == NULL){
        return;
    }

    char buffer[256];

    while(fgets(buffer, sizeof(buffer), file) != NULL){
        sscanf(buffer, "%lf", uptime);
    }

    fclose(file);
    return;
}