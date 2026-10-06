#pragma once

void available_memory_monitor(long *memory_used, long *memory_total);
void cpu_monitor(char *cpu);
void kernel_monitor(char *kernel);
void uptime_monitor(double *uptime);
void process_monitor(int *proc);
void cpu_usage_monitor(unsigned long long *usage);