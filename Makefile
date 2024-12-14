TARGET = AliExpress

CC = gcc
CFLAGS = -Wall -Wextra

SRCS = main.c Aliexpress.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean $(TARGET)
