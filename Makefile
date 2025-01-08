CC = gcc
CFLAGS = -Wall -g -std=c11 -pedantic
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = program

.PHONY: all clean debug release

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(TARGET) $(OBJS)

debug: CFLAGS += -DDEBUG
debug: all

release: CFLAGS += -O2
release: all

