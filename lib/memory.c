#include <stdio.h>
#include <string.h>

#include "includes.h"

void available_memory_monitor(long *memory_used, long *memory_total){
    FILE *file = fopen("/proc/meminfo", "r");

    if(file == NULL){
        printf("Erro de fopen!\n");
        return;
    }

    char buffer[256];
    long memory_available;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if((sscanf(buffer, "MemAvailable: %ld kb", &memory_available)) == 1){
            continue;
        }
        if((sscanf(buffer, "MemTotal: %ld kb", memory_total)) == 1){
            continue;
        }
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        
    }

    *memory_used = *memory_total - memory_available;

    fclose(file);
    return;
}