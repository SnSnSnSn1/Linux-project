// test/test_net.c
//#include "../src/net.c"  // 引入 net.c 中的函数
#include "../src/utils.h"

int main() {
    printf("开始网络使用情况测试...\n");
    print_network_usage();  // 调用函数打印网络使用率
    return 0;
}