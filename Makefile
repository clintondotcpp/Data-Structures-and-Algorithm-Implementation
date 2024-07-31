# Compiler for C++
CXX = g++

# Compiler for C
CC = gcc

# Compiler flags for C++
CXXFLAGS = -Wall -std=c++11

# Compiler flags for C
CFLAGS = -Wall

# Find all .cpp and .c files
CXX_SRCS := $(wildcard *.cpp)
C_SRCS := $(wildcard *.c)

# Generate object file names
CXX_OBJS := $(CXX_SRCS:.cpp=.o)
C_OBJS := $(C_SRCS:.c=.o)

# Executable name
EXEC = main

# Default target
all: $(EXEC)

# Link the object files to create the executable
$(EXEC): $(CXX_OBJS) $(C_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile C++ source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile C source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(CXX_OBJS) $(C_OBJS) $(EXEC)
