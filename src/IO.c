// src/IO.c
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// 使用 iostat 命令获取磁盘 I/O 统计信息
void print_io_usage() {
    FILE *fp = popen("iostat", "r");
    if (fp == NULL) {
        perror("Error opening pipe");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}