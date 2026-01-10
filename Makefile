CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Ilib

all: src/Test.cpp
	$(CXX) src/Test.cpp -o TestApp $(CXXFLAGS)

clean:
	rm -f lib/*.o lib/*.a TestApp
