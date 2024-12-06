// test/test_memory.c
#include "../src/memory.c"  // 引入memory.c中的函数

int main() {
    printf("开始内存使用率测试...\n");
    print_memory_usage();  // 调用函数打印内存使用率
    return 0;
}