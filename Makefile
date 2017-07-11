all: vec unittest

vec: original.cpp
	g++  original.cpp -Wall -o vec

unittest: vec.cpp
	g++ -D UNIT_TEST vec.cpp -Wall -o unittest

clean:
	rm -f vec unittest
