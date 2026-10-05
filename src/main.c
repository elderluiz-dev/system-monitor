#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "includes.h"

int main(){
    while(1){
        char cpu[100];
        char kernel[30];
        int proc;
        unsigned long long usage;
        long memory = available_memory_monitor();
        double memory_gb = (double)memory / (1024.0 * 1024.0);
        double uptime = uptime_monitor();

        //uptime treatment
        long total = (long)uptime;
        long hours = total / 3600;
        long minutes = (total % 3600) / 60;
        long seconds = total % 60;

        cpu_monitor(cpu);
        kernel_monitor(kernel);
        process_monitor(&proc);
        cpu_usage_monitor(&usage);

        system("clear");

        printf(
            "╭──────────── SYSTEM MONITOR ────────────╮\n"
            "Kernel       : %s\n"
            "Uptime       : %02ld:%02ld:%02ld\n"
            "CPU          : %s\n"
            "CPU usage    : %llu%%\n"
            "RAM          : %.2f GiB\n"
            "Processes    : %d\n"
            "╰────────────────────────────────────────╯\n",
            kernel,

            hours, minutes, seconds,

            cpu,
            usage,
            memory_gb,
            proc
        );

    }
    return 0;
}