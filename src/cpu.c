// src/cpu.c
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// 函数声明
void print_cpu_usage();

// 读取/proc/stat文件并解析CPU时间
void read_cpu_times(long double *user, long double *nice, long double *system, long double *idle, long double *iowait, long double *irq, long double *softirq, long double *steal) {
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        return;
    }
    // 注意这里我们只有8个字段，因为/proc/stat中的cpu行有8个数值字段
    fscanf(fp, "cpu %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf", user, nice, system, idle, iowait, irq, softirq, steal);
    fclose(fp);
}

// 计算并打印CPU使用率
void print_cpu_usage() {
    long double user, nice, system, idle, iowait, irq, softirq, steal;
    long double prev_idle, prev_total, idle_time, total_time, cpu_usage;

    // 第一次读取，获取初始值
    read_cpu_times(&user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
    prev_idle = idle;
    prev_total = user + nice + system + idle + iowait + irq + softirq + steal;

    sleep(1); // 等待1秒

    // 第二次读取，计算差值
    read_cpu_times(&user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
    idle_time = idle - prev_idle;
    total_time = user + nice + system + idle + iowait + irq + softirq + steal - prev_total;
    cpu_usage = 100 * (1 - idle_time / total_time);

    printf("CPU使用率: %.2Lf%%\n", cpu_usage);
}