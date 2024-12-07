#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

void run_cpu_test() {
    pid_t pid = fork();
    if(pid == 0){
    execlp("./bin/cpu_test", "cpu_test", (char *)NULL);
    perror("Failed to execute cpu_test");
    exit(0);
    }
}

void run_disk_test() {
    execlp("./bin/disk_test", "disk_test", (char *)NULL);
    perror("Failed to execute disk_test");
}

void run_memory_test() {
    execlp("./bin/memory_test", "memory_test", (char *)NULL);
    perror("Failed to execute memory_test");
}

void run_net_test() {
    execlp("./bin/net_test", "net_test", (char *)NULL);
    perror("Failed to execute net_test");
}

void run_io_test() {
    execlp("./bin/IO_test", "test_IO", (char *)NULL);           // ! 
    perror("Failed to execute test_IO");
}

int main() {
    char command[256];
    printf("             严锡好的系统资源监视器(pro)\n");  
    printf("----------------------------------------------------\n");
    printf("请输入想要测试的系统资源（cpu,disk,memory,net,io）:\n");
    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // 移除换行字符

        if (strcmp(command, "exit") == 0) {
            break;
        }

        if (strcmp(command, "cpu") == 0) {
            run_cpu_test();
        } else if (strcmp(command, "disk") == 0) {
            run_disk_test();
        } else if (strcmp(command, "memory") == 0) {
            run_memory_test();
        } else if (strcmp(command, "net") == 0) {
            run_net_test();
        } else if (strcmp(command, "io") == 0) {
            run_io_test();
        } else {
            printf("未知命令: %s\n", command);
        }
    }

    return 0;
}