
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Target executable
TARGET = cookbook

# Source files
SRCS = ArrayList.c Meal.c cookbook.c
# Object files (automatically replace .c with .o for each source file)
OBJS = $(SRCS:.c=.o)

# Default target to build the main executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile object files for each .c file / This is a new way to write the rule
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^ 

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET) ./test

test: unittest.c ArrayList.c Meal.c 
	$(CC) $(CFLAGS) -o $@ $^

# Run the program with a sample file
run: $(TARGET)
	./$(TARGET) 

valgrind: $(TARGET)
		valgrind ./$(TARGET) 