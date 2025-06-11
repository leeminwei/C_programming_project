# Makefile for the Student Management Project

# 編譯器設定
CC = gcc
# 編譯選項: -g (加入除錯資訊), -Wall (顯示所有警告)
CFLAGS = -g -Wall

# 執行檔名稱
TARGET = student_manager

# 來源檔案 (.c)
SRCS = main.c student.c

# 物件檔案 (.o)，由來源檔案名稱自動生成
OBJS = $(SRCS:.c=.o)

# 預設目標: all
# 當執行 make 時，會執行這個目標
all: $(TARGET)

# 連結 (Linking) 規則:
# 如何從物件檔案生成最終的執行檔
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 編譯 (Compilation) 規則:
# 如何從 .c 檔案生成 .o 檔案
# $< 代表第一個依賴項目 (例如 main.c)
# $@ 代表目標 (例如 main.o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理規則:
# 刪除所有編譯產生的檔案
clean:
	rm -f $(OBJS) $(TARGET)

# 將 clean 宣告為 "PHONY" 目標，
# 這樣即使有名為 "clean" 的檔案存在，make clean 依然可以正常運作
.PHONY: all clean 