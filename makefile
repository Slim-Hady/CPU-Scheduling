CC = gcc
CFLAGS = -I./include
# ضيفنا src/sjf.c في السطر اللي جاي ده
SRCS = main.c src/utils.c src/fcfs.c src/sjf.c
TARGET = scheduler

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)