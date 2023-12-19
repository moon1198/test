# 设置编译器和编译选项
CC = gcc
CFLAGS = -Wall -Werror -g
//CFLAGS = -g

# 查找最近修改的 .cc 或 .c 文件
//SRC = $(shell ls -t *.cc *.c | head -1)
SRC = $(shell ls -t *.c | head -1)

# 生成可执行文件
TARGET = $(basename $(SRC))

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
