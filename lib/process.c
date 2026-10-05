#include <stdio.h>
#include <string.h>

void process_monitor(int *proc){
    FILE *file = fopen("/proc/loadavg", "r");

    if(file == NULL){
        printf("Erro no fopen!.\n");
        return;
    }

    char buffer[255];

    while(fgets(buffer, sizeof(buffer), file) != NULL){
        if(sscanf(buffer, "%*f %*f %*f %*d/%d", proc) == 1){
            fclose(file);
            return;
        }
    }

    fclose(file);
    return;
}