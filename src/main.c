#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "includes.h"

int main(){
    while(1){
        char cpu[100];
        char kernel[30];
        int proc;
        long memory_used;
        long memory_total;
        unsigned long long usage;
        double uptime;

        available_memory_monitor(&memory_used, &memory_total);
        cpu_monitor(cpu);
        kernel_monitor(kernel);
        process_monitor(&proc);
        cpu_usage_monitor(&usage);
        uptime_monitor(&uptime);

        // memory treatment
        double memory_used_treated = (double)memory_used / (1024.0 * 1024.0);
        double memory_total_treated = (double)memory_total / (1024.0 * 1024.0);

        //uptime treatment
        long total = (long)uptime;
        long hours = total / 3600;
        long minutes = (total % 3600) / 60;
        long seconds = total % 60;

        system("clear");

        printf(
            "╭──────────── SYSTEM MONITOR ────────────╮\n"
            "Kernel       : %s\n"
            "Uptime       : %02ld:%02ld:%02ld\n"
            "CPU          : %s\n"
            "CPU usage    : %llu%%\n"
            "RAM          : %.2f / %.2f GiB\n"
            "Processes    : %d\n"
            "╰────────────────────────────────────────╯\n",
            kernel,

            hours, minutes, seconds,

            cpu,
            usage,
            memory_used_treated,
            memory_total_treated,
            proc
        );

    }
    return 0;
}