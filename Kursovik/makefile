CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = temperature_stat

SRCS = main.c Temp_function.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /F /Q $(OBJS) $(TARGET) 2>nul
.PHONY: all clean