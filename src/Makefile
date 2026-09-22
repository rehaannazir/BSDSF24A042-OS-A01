CC := gcc
CFLAGS := -Wall -Wextra -Werror -std=c11 -D_POSIX_C_SOURCE=200809L -I../include
TARGET := ../bin/client
SOURCES := mystrfunctions.c myfilefunctions.c main.c
OBJECTS := $(SOURCES:%.c=../obj/%.o)

.PHONY: all clean run directories

all: $(TARGET)

$(TARGET): $(OBJECTS) | directories
	$(CC) $(OBJECTS) -o $@

../obj/%.o: %.c | directories
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	mkdir -p ../obj ../bin

run: $(TARGET)
	$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

