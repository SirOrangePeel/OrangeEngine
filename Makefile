CXX := g++
AR := ar
CXXFLAGS := -std=c++20 -Wall -Wextra -O2 -Iinclude
ARFLAGS := rcs

LIB := libOrangeEngine.a

SRCS := $(wildcard src/*.cpp)
OBJS     := $(SRCS:.cpp=.o)

all: VecTest

# Build the static library from engine object files
$(LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

# Compile engine .cpp -> .o (headers like VectorT.h are included via -Iinclude)
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ---- Test apps (link against the engine library) ----

VecTest: apps/TestApps/VecTest.cpp $(LIB)
	$(CXX) $(CXXFLAGS) $< -L. -lOrangeEngine -o VecTest

ArenaTest: apps/TestApps/ArenaTest.cpp $(LIB)
	$(CXX) $(CXXFLAGS) $< -L. -lOrangeEngine -o ArenaTest

clean:
	rm -f src/*.o $(LIB) VecTest ArenaTest
