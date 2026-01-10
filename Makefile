CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Ilib

all: src/main.cpp
	$(CXX) src/main.cpp -o TestApp $(CXXFLAGS)

clean:
	rm -f lib/*.o lib/*.a TestApp
