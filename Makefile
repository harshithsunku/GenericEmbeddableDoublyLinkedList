CC=gcc
CFLAGS=-lpthread -Wall
TARGET=dll
SRCS=main.c dll.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) -o $(TARGET) $(SRCS) $(CFLAGS)

clean:
	rm -f $(TARGET)
