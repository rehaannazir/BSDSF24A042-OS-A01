CC := gcc
AR := ar
RANLIB := ranlib
CFLAGS := -Wall -Wextra -Werror -std=c11 -D_POSIX_C_SOURCE=200809L -I../include
TARGET := ../bin/client_static
LIBRARY := ../lib/libmyutils.a
LIB_SOURCES := mystrfunctions.c myfilefunctions.c
LIB_OBJECTS := $(LIB_SOURCES:%.c=../obj/%.o)
MAIN_OBJECT := ../obj/main.o

.PHONY: all clean run directories

all: $(TARGET)

$(TARGET): $(MAIN_OBJECT) $(LIBRARY) | directories
	$(CC) $(MAIN_OBJECT) -L../lib -lmyutils -o $@

$(LIBRARY): $(LIB_OBJECTS) | directories
	$(AR) rcs $@ $(LIB_OBJECTS)
	$(RANLIB) $@

../obj/%.o: %.c | directories
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	mkdir -p ../obj ../bin ../lib

run: $(TARGET)
	$(TARGET)

clean:
	rm -f $(LIB_OBJECTS) $(MAIN_OBJECT) $(LIBRARY) $(TARGET)
