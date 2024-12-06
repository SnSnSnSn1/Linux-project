#include <stdio.h>
#include <stdlib.h>


void get_disk_usage() {
    FILE *fp;
    char buffer[128];
    long blocks, used, available;

    fp = popen("df / | tail -1 | awk '{print $2,$3,$4}'", "r");
    if (fp == NULL) {
        perror("无法执行df命令");
        return;
    }

    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "%ld %ld %ld", &blocks, &used, &available);
    pclose(fp);

    double total = blocks / 1024.0;
    double used_percent = (double)used / blocks * 100.0;

    printf("磁盘使用率: %.2f%% (%.2fMB / %.2fMB)\n", used_percent, used / 1024.0, total);
}