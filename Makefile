CC = gcc
CFLAGS = -Wall -Wextra -g -I./lib

TARGET = main

SRC = src/main.c \
      lib/cpu.c \
      lib/kernel.c \
      lib/memory.c \
      lib/process.c \
      lib/uptime.c

OBJ = $(SRC:%.c=obj/%.o)


$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf obj $(TARGET)


.PHONY: clean