# Compiler
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wshadow -DFELIX

# All .cpp files in the current directory
SRC := $(wildcard *.cpp)

# Corresponding executables
TARGETS := $(SRC:.cpp=)

# Default target
all: $(TARGETS)

# Pattern rule
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Remove executables
clean:
	rm -f $(TARGETS)

.PHONY: all clean
