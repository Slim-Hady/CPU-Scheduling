CC = gcc
CFLAGS = -I./include
SRCS = main.c src/utils.c src/fcfs.c
TARGET = scheduler

all:
    $(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
    rm -f $(TARGET)