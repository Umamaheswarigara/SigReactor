CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

TARGET = sigreactor

SRC = src/main.c \
      src/reactor.c \
      src/signal_handler.c \
      src/event.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)


