# 二元搜尋樹系統 Makefile
# 編譯器設定
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# 目標檔案和原始檔案
TARGET = bst_system
SOURCES = bst_system.c
OBJECTS = $(SOURCES:.c=.o)

# 預設目標
all: $(TARGET)

# 編譯執行檔
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) -lm

# 編譯目標檔案
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理編譯產生的檔案
clean:
	rm -f $(OBJECTS) $(TARGET)

# 執行程式
run: $(TARGET)
	./$(TARGET)

# 使用 valgrind 檢查記憶體洩漏 (Linux/Mac)
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# 測試目標 (可依需求調整)
test: $(TARGET)
	@echo "執行基本測試..."
	@echo "請手動測試程式功能，參考 interactive_test.txt"

# 建立提交用的壓縮檔
archive:
	tar -czf bst_assignment.tar.gz *.c *.h Makefile *.md *.txt

# 顯示說明
help:
	@echo "可用的 make 指令："
	@echo "  all      - 編譯程式 (預設)"
	@echo "  clean    - 清理編譯產生的檔案"
	@echo "  run      - 編譯並執行程式"
	@echo "  valgrind - 使用 valgrind 檢查記憶體洩漏"
	@echo "  test     - 執行測試"
	@echo "  archive  - 建立提交用的壓縮檔"
	@echo "  help     - 顯示此說明"

# 宣告偽目標
.PHONY: all clean run valgrind test archive help 