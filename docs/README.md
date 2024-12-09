# 使用指南

**1. 系统要求**<br>
本系统资源监视器“promax”设计用于在Linux操作系统上运行。它依赖于Linux特有的文件系统和命令行工具来收集系统资源信息。

**2. 依赖项**<br>
为了确保“promax”能够正常运行，你的系统需要安装以下依赖项：
- **标准C库**：项目使用C语言编写，需要标准C库支持。
- **unistd.h**：用于访问POSIX操作系统API。
- **stdio.h**：标准输入输出库。
- **stdlib.h**：标准库，提供通用工具函数。
- **string.h**：字符串处理库。
- **sys/stat.h**：文件系统访问相关的系统调用。
- **sys/types.h**：定义数据类型。

**3. 命令行工具**<br>
项目中的测试模块依赖于以下Linux命令行工具来收集系统信息：
- `top`：显示系统中进程的动态实时视图。
- `vmstat`：报告关于进程、内存、分页、块I/O、陷门和CPU活动的信息。
- `lsof`：列出当前系统打开的文件。
- `netstat`：显示网络连接、路由表、接口统计等。
- `htop`：交互式的进程查看器。
- `iotop`：监控磁盘I/O使用情况。
- `iostat`：监视系统输入/输出设备负载。
- `iftop`：实时网络使用监控工具。

**4. 编译工具**<br>
为了编译项目，你需要安装以下编译工具：
- **GCC**：GNU编译器集合，用于编译C语言程序。
- **Make**：自动化构建工具，用于编译和管理项目。

**5. 权限要求**<br>
某些测试模块可能需要管理员权限来执行，例如：
- `iotop`：需要root权限来显示所有进程的I/O信息。
(在终端输入`sudo iotop`之后，再输入Linux的密码即可执行)

**6. 环境变量**<br>
项目可能需要设置以下环境变量：
- `PATH`：确保包含GCC、Make以及所有依赖的命令行工具的路径。

**7. 安装依赖项**<br>
在Debian或Ubuntu系统上，你可以使用以下命令安装依赖项：
```
sudo apt-get update
sudo apt-get install build-essential gcc make
sudo apt-get install sysstat iotop iftop
```

在Red Hat或CentOS系统上，使用以下命令：
```
sudo yum update
sudo yum groupinstall "Development Tools"
sudo yum install gcc make sysstat iotop iftop
```

**8. 编译项目**<br>
在项目根目录下，使用以下命令编译项目：
make
这将根据 makefile 中的指令编译所有源代码文件。

**9. 运行项目**<br>
编译完成后，你可以通过以下方式运行项目：
./main
./main_tests
这将启动一个菜单驱动的界面，允许你选择不同的系统监控工具。

**10. 运行脚本**（IHG分支）<br>
编译完成后，你可以通过以下方式运行脚本：
chmod +x run.sh
./run.sh
这将启动一个菜单驱动的界面，允许你选择不同的系统监控版本。

**11. 运行结果**<br>
![image](https://github.com/user-attachments/assets/7de9afe4-fe93-4cb4-b73a-0eeb18bd978a)

![image](https://github.com/user-attachments/assets/a4691ce2-0558-49e3-8788-307aa100effb)


