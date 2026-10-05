#include <stdio.h>
#include <string.h>

#include "includes.h"

long available_memory_monitor(){
    FILE *file = fopen("/proc/meminfo", "r");

    if(file == NULL){
        printf("Erro de fopen!\n");
        return 1;
    }

    char buffer[256];
    long memory;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if((sscanf(buffer, "MemAvailable: %ld kb", &memory)) == 1){
            fclose(file);
            return memory;
        }
    }

    fclose(file);
    return 1;
}