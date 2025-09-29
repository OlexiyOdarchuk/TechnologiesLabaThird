CXX = g++
CXXFLAGS = -Iinclude

SRC = src/main.cpp src/ArrayApp.cpp src/ArrayOperations.cpp
TARGET_DIR = target
TARGET = $(TARGET_DIR)/ArrayApp

all: $(TARGET)

$(TARGET): | $(TARGET_DIR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

clean:
	rm -rf $(TARGET_DIR)

.PHONY: all clean
