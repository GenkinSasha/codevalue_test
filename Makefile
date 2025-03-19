CC = g++
CFLAGS = -Wall -Wextra -O2 -std=c++17
TARGET = codevalue_test
SRC = codevalue_test.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

debug: $(SRC)
	$(CC) $(CFLAGS) -g $(SRC) -o $(TARGET)
	gdb ./$(TARGET)

clean:
	rm -f $(TARGET)