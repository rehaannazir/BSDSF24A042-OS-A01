CC := gcc
AR := ar
RANLIB := ranlib
CFLAGS := -Wall -Wextra -Werror -std=c11 -D_POSIX_C_SOURCE=200809L -I../include
STATIC_TARGET := ../bin/client_static
DYNAMIC_TARGET := ../bin/client_dynamic
STATIC_LIBRARY := ../lib/libmyutils.a
SHARED_LIBRARY := ../lib/libmyutils.so
LIB_SOURCES := mystrfunctions.c myfilefunctions.c
LIB_OBJECTS := $(LIB_SOURCES:%.c=../obj/%.o)
PIC_OBJECTS := $(LIB_SOURCES:%.c=../obj/%.pic.o)
MAIN_OBJECT := ../obj/main.o

.PHONY: all clean run run-dynamic directories

all: $(STATIC_TARGET) $(DYNAMIC_TARGET)

$(STATIC_TARGET): $(MAIN_OBJECT) $(STATIC_LIBRARY) | directories
	$(CC) $(MAIN_OBJECT) $(STATIC_LIBRARY) -o $@

$(DYNAMIC_TARGET): $(MAIN_OBJECT) $(SHARED_LIBRARY) | directories
	$(CC) $(MAIN_OBJECT) -L../lib -lmyutils -o $@

$(STATIC_LIBRARY): $(LIB_OBJECTS) | directories
	$(AR) rcs $@ $(LIB_OBJECTS)
	$(RANLIB) $@

$(SHARED_LIBRARY): $(PIC_OBJECTS) | directories
	$(CC) -shared $(PIC_OBJECTS) -o $@

../obj/%.pic.o: %.c | directories
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

../obj/%.o: %.c | directories
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	mkdir -p ../obj ../bin ../lib

run: $(STATIC_TARGET)
	$(STATIC_TARGET)

run-dynamic: $(DYNAMIC_TARGET)
	LD_LIBRARY_PATH=$(abspath ../lib) $(DYNAMIC_TARGET)

clean:
	rm -f $(LIB_OBJECTS) $(PIC_OBJECTS) $(MAIN_OBJECT) \
		$(STATIC_LIBRARY) $(SHARED_LIBRARY) $(STATIC_TARGET) $(DYNAMIC_TARGET)
