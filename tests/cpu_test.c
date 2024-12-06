#include <stdio.h>
#include "../src/cpu.c"  // 引入cpu.c中的函数

int main() {
    printf("开始CPU使用率测试...\n");
    print_cpu_usage();  // 调用函数打印CPU使用率
    return 0;
}