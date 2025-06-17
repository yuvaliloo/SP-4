# === Compiler & Flags ===
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -pedantic -g

# === File names ===
SRC = MyContainer.cpp
HEADERS = MyContainer.hpp MyContainer_Iterators.hpp
MAIN = main.cpp
TEST = Test.cpp

# === Targets ===
all: main test

main: $(SRC) $(MAIN) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o main $(MAIN) $(SRC)

test: $(SRC) $(TEST) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o test $(TEST) $(SRC)

valgrind: test
	valgrind --leak-check=full --track-origins=yes ./test

clean:
	rm -f main test *.o core* vgcore.*
