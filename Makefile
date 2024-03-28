

rational.o: rational.cpp rational.hpp
	clang++ -std=c++11 -Wall rational.cpp -c rational.o