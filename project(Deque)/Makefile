# 編譯器設定
CC = gcc
# 編譯選項: -g (加入除錯資訊), -Wall (開啟所有警告)
CFLAGS = -g -Wall -std=c99

# 連結器選項
LDFLAGS =

# 執行檔名稱
TARGET = sliding_window

# 原始碼檔案
SRCS = main.c deque.c

# 從原始碼檔案產生對應的 object 檔案名稱 (.o)
OBJS = $(SRCS:.c=.o)

# 預設規則：編譯所有東西
all: $(TARGET)

# 連結 object 檔案來產生最終的執行檔
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)

# 編譯 .c 檔案為 .o 檔案的通用規則
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清除編譯產生的檔案
clean:
	rm -f $(OBJS) $(TARGET)

# .PHONY 告訴 make，'clean' 和 'all' 不是真正的檔案名稱
.PHONY: all clean 