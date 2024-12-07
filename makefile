CC = gcc
CFLAGS = -Wall -g
SRC_DIR = src/
TEST_DIR = tests/
OBJ_DIR = obj/
BIN_DIR = bin/

# 自动获取src目录下的所有源文件
SRCS = $(wildcard $(SRC_DIR)*.c)
# 对象文件对应于源文件，存放在obj目录下
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))
# 自动获取tests目录下的所有测试文件
TEST_SRCS = $(wildcard $(TEST_DIR)*_test.c)
# 测试对象文件
TEST_OBJS = $(patsubst $(TEST_DIR)%_test.c, $(OBJ_DIR)%_test.o, $(TEST_SRCS))
# 测试可执行文件
TEST_BINS = $(patsubst $(TEST_DIR)%_test.c, $(BIN_DIR)%_test, $(TEST_SRCS))

# 创建对象文件和可执行文件的目录
$(shell mkdir -p $(OBJ_DIR))
$(shell mkdir -p $(BIN_DIR))

# 默认目标，构建所有对象文件和测试
all: $(OBJS) $(TEST_BINS)

# 编译src目录下的所有源文件为对象文件
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

# 编译tests目录下的所有测试文件为对象文件
$(OBJ_DIR)%_test.o: $(TEST_DIR)%_test.c $(OBJ_DIR)%.o
	$(CC) $(CFLAGS) -c $< -o $@

# 链接测试对象文件和相应的源对象文件为可执行文件
$(BIN_DIR)%_test: $(OBJ_DIR)%_test.o $(OBJ_DIR)%.o
	$(CC) $(CFLAGS) $^ -o $@

# 运行所有测试
test: $(TEST_BINS)
	@echo "Running tests..."
	$(foreach bin, $(TEST_BINS), ./$(bin);)

# 清理构建生成的文件
clean:
	rm -rf $(OBJ_DIR)*.o $(BIN_DIR)* $(OBJ_DIR) $(BIN_DIR)

.PHONY: all test clean