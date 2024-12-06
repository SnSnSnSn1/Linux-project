// test/test_disk.c
#include "../src/disk.c"  // 引入disk.c中的函数

int main() {
    printf("开始磁盘使用率测试...\n");
    get_disk_usage("/dev/sda");  // 调用函数打印磁盘使用率，假设你的磁盘设备是 /dev/sda1
    return 0;
}