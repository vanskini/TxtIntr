TARGET = calculator
SRC = main.cpp
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) -lm

clean:
	rm -f $(TARGET) *.o

rebuild: clean all

.PHONY: all clean rebuild
