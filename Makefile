# CXX = g++
# CXXFLAGS = -std=c++20 -fsanitize=address

# all: main

# main: src/dijkstras_main.cpp lib/dijkstras.o
# 	$(CXX) $(CXXFLAGS) -o main src/dijkstras_main.cpp lib/dijkstras.o


# lib/dijkstras.o: src/dijkstras.cpp src/dijkstras.h
# 	$(CXX) $(CXXFLAGS) -c src/dijkstras.cpp -o lib/dijkstras.o


# clean:
# 	rm -f lib/*.o main

CXX = g++
CXXFLAGS = -std=c++20 -fsanitize=address

all: main

main: src/ladder_main.cpp lib/ladder.o
	$(CXX) $(CXXFLAGS) -o main src/ladder_main.cpp lib/ladder.o


lib/ladder.o: src/ladder.cpp src/ladder.h
	$(CXX) $(CXXFLAGS) -c src/ladder.cpp -o lib/ladder.o


clean:
	rm -f lib/*.o main