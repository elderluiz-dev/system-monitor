#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;
    unsigned long long steal;
} CpuStats;

void cpu_usage_monitor(unsigned long long *usage){
    FILE *file = fopen("/proc/stat", "r");
    if(file == NULL){
        printf("Erro no fopen!");
        return;
    }

   CpuStats old;
   CpuStats new;

    char buffer[256];

    while(fgets(buffer, sizeof(buffer), file) != NULL){
        if (sscanf(buffer, "cpu  %llu %llu %llu %llu %llu %llu %llu %llu",
                   &old.user, &old.nice, &old.system,
                   &old.idle, &old.iowait, &old.irq,
                   &old.softirq, &old.steal) == 8) {
            break;
        }
    }

    sleep(1);
    file = fopen("/proc/stat", "r");
    if(file == NULL){
        printf("Erro no fopen!");
        return;
    }

    while(fgets(buffer, sizeof(buffer), file) != NULL){
        if (sscanf(buffer, "cpu  %llu %llu %llu %llu %llu %llu %llu %llu",
                   &new.user, &new.nice, &new.system,
                   &new.idle, &new.iowait, &new.irq,
                   &new.softirq, &new.steal) == 8) {
            break;
        }
    }

    unsigned long long total_old = {
                old.user + old.nice + old.system + old.idle +
                old.iowait + old.irq + old.softirq + old.steal
    };
    unsigned long long total_new = {
                new.user + new.nice + new.system + new.idle +
                new.iowait + new.irq + new.softirq + new.steal
    };

    unsigned long long idle_old =
        old.idle + old.iowait;

    unsigned long long idle_new =
        new.idle + new.iowait;

    unsigned long long total_delta =
        total_new - total_old;

    unsigned long long idle_delta =
        idle_new - idle_old;

    unsigned long long busy_delta =
        total_delta - idle_delta;

    *usage = (100.0 * busy_delta) / total_delta;

}

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