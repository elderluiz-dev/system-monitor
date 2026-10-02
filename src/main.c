#include <stdio.h>

#include "includes.h"

int main(){
    char cpu[100];
    char kernel[30];
    long memory = memory_monitor();
    double memory_gb = (double)memory / (1024.0 * 1024.0);
    double uptime = uptime_monitor();

    //uptime treatment
    long total = (long)uptime;
    long hours = total / 3600;
    long minutes = (total % 3600) / 60;
    long seconds = total % 60;

    cpu_monitor(cpu);
    kernel_monitor(kernel);

printf(
    "╭──────────── SYSTEM MONITOR ────────────╮\n"
    "Kernel       : %s\n"
    "Uptime       : %02ld:%02ld:%02ld\n"
    "CPU          : %s\n"
    "CPU usage    : xx.xx\n"
    "RAM          : %.2f GiB\n"
    "Processes    : xxx\n"
    "╰────────────────────────────────────────╯\n",
    kernel,

    hours, minutes, seconds,

    cpu,
    memory_gb
);
    return 0;
}