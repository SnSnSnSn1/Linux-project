#!/bin/bash


make clean
make 

# 显示菜单
echo "请选择操作："
echo "1 - 编译并执行程序main"
echo "2 - 编译并执行程序main_test"
echo "0 - 退出"

# 读取用户输入
read -p "请输入选择: " choice

# 根据用户输入的选择进行相应操作
case $choice in
    1)
        echo "正在编译程序main..."
        gcc -o ./obj/program_a main.c   # 假设程序a的源文件是 program_a.c
        if [ $? -eq 0 ]; then          # 检查编译是否成功
            echo "程序a编译成功，正在执行..."
            ./obj/program_a                # 执行编译后的程序a
        else
            echo "程序a编译失败"
        fi
        ;;
    2)
        echo "正在编译程序main_test..."
        gcc -o ./obj/program_b main_tests.c   # 假设程序b的源文件是 program_b.c
        if [ $? -eq 0 ]; then          # 检查编译是否成功
            echo "程序b编译成功，正在执行..."
            ./obj/program_b                # 执行编译后的程序b
        else
            echo "程序b编译失败"
        fi
        ;;
    0)
        echo "退出程序"
        exit 0
        ;;
    *)
        echo "无效选择，请输入 0、1 或 2"
        ;;
esac
