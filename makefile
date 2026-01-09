CC = clang
CFLAGS = -Wall -Wextra -std=c99
TARGET = publication_sorter
OBJS = main.o pub_record.o stack_container.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)