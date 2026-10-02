#include <stdio.h>
#include <string.h>

#include "includes.h"

long memory_monitor(){
    FILE *file = fopen("/proc/meminfo", "r");

    if(file == NULL){
        printf("Erro de fopen!\n");
        return 1;
    }

    char buffer[256];
    long memory;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if((sscanf(buffer, "MemAvailable: %ld kb", &memory)) == 1){
            return memory;
            fclose(file);
        }
    }

    fclose(file);
    return 1;
}