CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11 -pedantic
LDFLAGS =
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = program

.PHONY: all clean debug release test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(TARGET) $(OBJS)

debug: CFLAGS += -DDEBUG
debug: all

release: CFLAGS += -O2
release: all

test: $(TARGET)
	./$(TARGET)


