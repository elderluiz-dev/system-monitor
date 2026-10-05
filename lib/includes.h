#pragma once

long memory_monitor();
void cpu_monitor(char *cpu);
void kernel_monitor(char *kernel);
double uptime_monitor();
void process_monitor(int *proc);
void cpu_usage_monitor(unsigned long long *usage);