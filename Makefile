CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g

SRCS = src/main.c src/bisection.c src/array_utils.c
OBJS = $(SRCS:.c=.o)
TARGET = home_task_4

TEST_SRC = tests/test_main.c
TEST_MODULES = src/array_utils.c src/bisection.c
TEST_TARGET = test_runner

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
test:
	$(CC) $(CFLAGS) $(TEST_SRC) $(TEST_MODULES) -o $(TEST_TARGET) -lm
	./$(TEST_TARGET)

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_TARGET)

.PHONY: all clean test