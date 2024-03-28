CXX=clang++
CXXFLAGS= -Wall -std=c++11
EXEC_FILES=rational-test
SRC= $(wildcard *.cpp) # tous les fichiers .cpp du répertoire
OBJ=$(SRC:.cpp=.o)

all: rational-test
	

utilities-test: utilities/utilities.hpp utilities/utilities-test.cpp
	$(CXX) $(CXXFLAGS) utilities/utilities.cpp utilities/utilities-test.cpp -o utilities-test

rational-test: rational/rational.hpp rational/rational-test.cpp
	$(CXX) $(CXXFLAGS) rational/rational.cpp rational/rational-test.cpp -o rational-test

rational.o: rational/rational.hpp rational/rational.cpp 
	$(CXX) -c rational/rational.hpp rational/rational.cpp $(CXXFLAGS)

rational-test.o: rational/rational.hpp
	$(CXX) -c rational/rational.hpp rational/rational-test.cpp $(CXXFLAGS)

clean:
	rm -f *.o
