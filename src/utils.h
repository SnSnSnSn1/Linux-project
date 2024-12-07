#ifndef UTILS_HEADER
#define UTILS_HEADER

// 函数声明
void print_cpu_usage();
void read_cpu_times(
    long double *user, long double *nice, long double *system, 
    long double *idle, long double *iowait, long double *irq, long double *softirq, long double *steal);

void print_io_usage();
void get_disk_usage();
void print_network_usage();
// 函数声明
void print_memory_usage();

#endif // !UTILS_HEADER

