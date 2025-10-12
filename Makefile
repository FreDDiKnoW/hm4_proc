CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g

SRCS = src/main.c src/bisection.c src/array_utils.c
OBJS = $(SRCS:.c=.o)
TARGET = home_task_4

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean