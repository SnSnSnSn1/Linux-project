#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    
    do {
        printf("            严锡好的系统资源监视器(promax)\n");  
        printf("----------------------------------------------------\n");
        printf("1. Top-CPU监视\n");
        printf("2. VmStat-虚拟内存统计\n");
        printf("3. Lsof-列出打开的文件\n");
        printf("4. Netstat-网络统计\n");
        printf("5. Htop-LINUX进程监视\n");
        printf("6. Iotop-LINUX磁盘监视\n");
        printf("7. Iostat-输入输出统计\n");
        printf("8. Iftop-网络带宽监视\n");
        printf("9. 退出\n");
        printf("----------------------------------------------------\n");
        printf("请输入想要测试的系统资源（数字序号）：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf(" Top-CPU监视:\n");
                system("top");
                printf("\n");
                break;
            case 2:
                printf(" VmStat-虚拟内存统计:\n");
                system("vmstat");
                printf("\n");
                break;
            case 3:
                printf(" Lsof-列出打开的文件:\n");
                system("lsof");
                printf("\n");
                break;
            case 4:
                printf(" Netstat-网络统计:\n");
                system("netstat -a | more");
                printf("\n");
                break;
            case 5:
                printf(" Htop-LINUX进程监视:\n");
                system("htop");
                printf("\n");
                break;
            case 6:
                printf(" Iotop-LINUX磁盘监视:\n");
                system("sudo iotop");
                printf("iotop 需要 root 权限来运行,请使用 sudo 或者以 root 用户身份运行程序。\n");
                printf("在终端先输入sudo iotop,再输入密码即可运行。\n");
                printf("\n");
                break;
            case 7:
                printf(" Iostat-输入输出统计:\n");
                system("iostat");
                printf("\n");
                break;
            case 8:
                printf(" Iftop-网络带宽监视:\n");
                system("iftop");
                printf("\n");
                break;
            case 9:
                printf("程序已退出。\n");
                break;
            default:
                printf("无效的选择，程序已退出。\n");
                printf("\n");
                break;
        }
    } while (choice != 9);

    return 0;
}