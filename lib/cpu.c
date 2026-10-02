#include <stdio.h>
#include <string.h>

void cpu_monitor(char *cpu){
    FILE *file = fopen("/proc/cpuinfo", "r");

    if(file == NULL){
        printf("Erro no fopen!");
        return;
    }

    char buffer[256];

    while(fgets(buffer, sizeof(buffer), file) != NULL){
        if (sscanf(buffer, "model name\t: %[^\n]", cpu) == 1) {
            break;
        }
    }

    return;
}