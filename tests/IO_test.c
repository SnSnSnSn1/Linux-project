// test/test_IO.c
#include "../src/IO.c"  // 引入 IO.c 中的函数

int main() {
    printf("开始 I/O 使用情况测试...\n");
    print_io_usage();  // 调用函数打印 I/O 使用率
    return 0;
}