CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = bracket_checker
SOURCE = bracket_checker.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

test: $(TARGET)
	@echo "執行自動測試..."
	@echo "這將運行所有預定義的測試案例"
	./$(TARGET) < /dev/null

.PHONY: all run clean test 