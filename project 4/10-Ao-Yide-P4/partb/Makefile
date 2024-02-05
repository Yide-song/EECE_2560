# Makefile for C++ program

# Define the compiler and compilation flags
CXX = g++
CXXFLAGS = -std=c++11 -Wno-all -g

# Define the source and header files
SRCS = board.cpp
HEADERS = d_except.h d_matrix.h

# Define the target executable
TARGET = main

# Default target: compile and run the program
all: run

# Compile the source files into the executable with debugging information
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run the compiled program
run: $(TARGET)
	./$(TARGET)

# Target for a debug build
debug: clean $(TARGET)

# Clean up the executable
clean:
	rm -f $(TARGET)
