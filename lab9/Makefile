CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = plikowiec

all: $(TARGET)

$(TARGET): main.o file.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o file.o

main.o: main.c file.h
	$(CC) $(CFLAGS) -c main.c99

file.o: file.c file.h
	$(CC) $(CFLAGS) -c file.c

clean:
	rm -rf *.o $(TARGET) content.txt
