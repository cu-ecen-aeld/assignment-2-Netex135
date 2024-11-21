CROSS_COMPILE ?=
CC = gcc
TARGET = writer
CFLAGS = -Wall -Wextra -Werror

all:
	$(CROSS_COMPILE)gcc $(CFLAGS) writer.c -o $(TARGET)

clean: 
	rm -f $(TARGET)
