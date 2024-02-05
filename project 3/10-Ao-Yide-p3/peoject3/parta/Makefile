# Makefile for C++ program

# Define the compiler and compilation flags
CXX = g++
CXXFLAGS = -std=c++11

# Define the source and header files
SRCS = Binarysearch.cpp Dictionary.cpp Grid.cpp Selectionsort.cpp main.cpp
HEADERS = Binarysearch.h Dictionary.h Grid.h Selectionsort.h

# Define the target executable
TARGET = main

# Default target: compile and run the program
all: run

# Compile the source files into the executable
$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run the compiled program
run: $(TARGET)
	./$(TARGET)

# Clean up the executable
clean:
	rm -f $(TARGET)
