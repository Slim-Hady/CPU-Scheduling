CC = gcc
SRCS = main.c src/utils.c src/fcfs.c
TARGET = scheduler

all:
	$(CC) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)