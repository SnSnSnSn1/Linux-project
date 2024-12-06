// src/memory.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 函数声明
void print_memory_usage();

// 读取/proc/meminfo文件并解析内存信息
void read_memory_info(long *total, long *free, long *buffers, long *cached) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Error opening /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, "MemTotal:")) {
            sscanf(buffer, "MemTotal: %ld kB", total);
        } else if (strstr(buffer, "MemFree:")) {
            sscanf(buffer, "MemFree: %ld kB", free);
        } else if (strstr(buffer, "Buffers:")) {
            sscanf(buffer, "Buffers: %ld kB", buffers);
        } else if (strstr(buffer, "Cached:")) {
            sscanf(buffer, "Cached: %ld kB", cached);
        }
    }
    fclose(fp);
}

// 计算并打印内存使用率
void print_memory_usage() {
    long total, free, buffers, cached;
    long used;

    read_memory_info(&total, &free, &buffers, &cached);
    used = total - free - buffers - cached; // 计算已使用内存
    double usage = (double)used / total * 100; // 计算使用率

    printf("内存使用率: %.2f%%\n", usage);
}