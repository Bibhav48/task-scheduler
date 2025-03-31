# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -g

# Directories for object files and binary
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRC = DHeap.cpp Task.cpp Testbench.cpp

# Object files
OBJ = $(SRC:.cpp=.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))

# Output binary name for main program
MAIN_BIN = $(BIN_DIR)/main

# Output binary name for testbench
TESTBENCH_BIN = $(BIN_DIR)/testbench

# Targets
all: $(MAIN_BIN)

# Rule to create the main program
$(MAIN_BIN): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(MAIN_BIN) $(OBJ)

# Rule to compile the source files into object files
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run testbench
test: $(TESTBENCH_BIN)
	$(TESTBENCH_BIN)

# Rule to compile the testbench, excluding Testbench.cpp from main compile
$(TESTBENCH_BIN): $(OBJ_DIR)/DHeap.o $(OBJ_DIR)/Task.o $(OBJ_DIR)/Testbench.o
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(TESTBENCH_BIN) $(OBJ_DIR)/DHeap.o $(OBJ_DIR)/Task.o $(OBJ_DIR)/Testbench.o

# Clean the generated files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean test
