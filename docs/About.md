# 项目概述：
本项目是一个系统资源监视器，名为“严锡好的系统资源监视器”，并分为pro（main_tests.c）和promax(main.c)两个版本，main_tests.c是将test里面的功能整合到一起,而我在编写完成之后觉得他有些单调，于是进行了拓展优化，就有了promax版本。
项目结构清晰，分为源代码目录（src）、测试代码目录（tests）以及文档和配置文件。

# 文档和支持
README.md 提供了项目的使用说明。
About.txt 提供了项目的基本信息和详细描述。
LICENSE 文件包含了项目的使用许可信息。

# 功能概述：
1. pro版能够监控和展示系统中的CPU、磁盘、内存、网络和I/O使用情况。项目由多个模块组成，每个模块负责收集特定类型的系统资源信息，并通过命令行界面展示给用户。

2. promax版实现了一个用户友好的命令行界面，它提供了一个菜单驱动的系统，允许用户选择并执行多种系统资源监视和诊断工具。这个界面扩展了测试功能，整合了对CPU、内存、磁盘、网络和I/O使用情况的监控，并且能够调用如`top`、`vmstat`、`lsof`、`netstat`、`htop`、`iotop`、`iostat`、`iftop`等系统命令，以直观的方式展示系统性能和资源使用情况，从而为用户提供了一个全面的系统监控解决方案。

# 项目结构：
项目源码/
│
├── docs/
│   ├── About.md
│   ├── LICENSE
│   ├── makefile
│   └── README.md
│
├── src/
│   ├── cpu.c
│   ├── disk.c
│   ├── IO.c
│   ├── memory.c
│   └── net.c
│
├── tests/
│   ├── cpu_test.c
│   ├── disk_test.c
│   ├── IO_test.c
│   ├── memory_test.c
│   ├── net_test.c
│   └── main_tests.c
│
├── main.c
└── main_tests.c


# 代码分析：
1. `docs/` 目录：包含项目的文档文件，如`About.md`、`LICENSE`、`makefile`和`README.md`。这些文件提供了项目的基本信息、使用许可、编译指令和使用说明。

2. `src/` 目录：包含项目的核心源代码文件，每个文件负责一个特定的系统资源监控功能。
   - `cpu.c`：读取 `/proc/stat` 文件，计算并打印CPU的使用率。
   - `disk.c`：执行 `df` 命令，获取磁盘使用情况，并计算使用率。
   - `IO.c`：执行 `iostat` 命令，获取磁盘I/O统计信息。
   - `memory.c`：读取 `/proc/meminfo` 文件，计算并打印内存使用率。
   - `net.c`：执行 `nethogs` 命令，获取网络使用情况。

3. `tests/` 目录：包含用于测试src目录中各个模块功能的测试代码。
   - `cpu_test.c`：测试 `cpu.c` 模块的CPU使用率监控功能。
   - `disk_test.c`：测试 `disk.c` 模块的磁盘使用率监控功能。
   - `IO_test.c`：测试 `IO.c` 模块的磁盘I/O监控功能。
   - `memory_test.c`：测试 `memory.c` 模块的内存使用率监控功能。
   - `net_test.c`：测试 `net.c` 模块的网络使用情况监控功能。

4. 项目核心
`main_tests.c`文件（pro版）：提供一个交互式命令行界面，允许用户选择并运行不同的测试（基于tests文件夹里的功能）。
`main.c` 文件（promax版）：提供用户交互界面，允许用户选择不同的系统监控工具，如 `top`、`vmstat`、`lsof`、`netstat`、`htop`、`iotop`、`iostat`、`iftop`等，并执行相应的系统命令。

# 主程序说明
1. promax程序 (main.c)
启动程序后，你将看到一个菜单，列出了不同的系统监控选项。
输入对应的数字序号来选择你想要监控的系统资源。
例如，输入 1 将启动 top 命令，显示CPU使用情况。

2. pro程序 (main_tests.c)
启动程序后，你将看到一个提示符，要求你输入想要测试的系统资源。
输入 cpu、disk、memory、net 或 io 来运行相应的测试。
输入 exit 来退出测试程序。

# 模块化程序说明
1. CPU使用率测试 (cpu_test.c)
该测试将调用 cpu.c 中的函数来计算并显示CPU使用率。

2. 磁盘使用率测试 (disk_test.c)
该测试将调用 disk.c 中的函数来获取并显示磁盘使用率。

3. 内存使用率测试 (memory_test.c)
该测试将调用 memory.c 中的函数来计算并显示内存使用率。

4. 网络使用情况测试 (net_test.c)
该测试将调用 net.c 中的函数来获取并显示网络使用情况。

5. I/O使用情况测试 (IO_test.c)
该测试将调用 IO.c 中的函数来获取并显示I/O使用情况。