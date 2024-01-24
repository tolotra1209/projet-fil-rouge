CC = gcc
CFLAGS = -Wall -Wextra -g -O0
HEADERS = head.h
SOURCES = main.c functions.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = robot_program

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
